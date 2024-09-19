$NetBSD$

--- src/VBox/Additions/common/VBoxGuest/VBoxGuest-netbsd.c.orig	2016-07-07 07:08:46.294122795 +0000
+++ src/VBox/Additions/common/VBoxGuest/VBoxGuest-netbsd.c
@@ -0,0 +1,631 @@
+/*  VBoxGuest-netbsd.c $ */
+/** @file
+ * VirtualBox Guest Additions Driver for NetBSD.
+ */
+
+/*
+ * Copyright (C) 2007-2015 Oracle Corporation
+ *
+ * This file is part of VirtualBox Open Source Edition (OSE), as
+ * available from http://www.virtualbox.org. This file is free software;
+ * you can redistribute it and/or modify it under the terms of the GNU
+ * General Public License (GPL) as published by the Free Software
+ * Foundation, in version 2 as it comes in the "COPYING" file of the
+ * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
+ * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
+ */
+
+/** @todo r=bird: This must merge with SUPDrv-netbsd.c before long. The two
+ * source files should only differ on prefixes and the extra bits wrt to the
+ * pci device. I.e. it should be diffable so that fixes to one can easily be
+ * applied to the other. */
+
+
+/*********************************************************************************************************************************
+*   Header Files                                                                                                                 *
+*********************************************************************************************************************************/
+#include <sys/param.h>
+#undef PVM
+#include <sys/types.h>
+#include <sys/module.h>
+#include <sys/systm.h>
+#include <sys/errno.h>
+#include <sys/kernel.h>
+#include <sys/fcntl.h>
+#include <sys/conf.h>
+#include <sys/uio.h>
+#include <sys/bus.h>
+#include <sys/poll.h>
+#include <sys/selinfo.h>
+#include <sys/queue.h>
+#include <sys/lock.h>
+#include <sys/lockmgr.h>
+#include <sys/malloc.h>
+#include <sys/file.h>
+#include <sys/rman.h>
+#include <machine/bus.h>
+#include <machine/resource.h>
+#include <dev/pci/pcivar.h>
+#include <dev/pci/pcireg.h>
+
+#include "VBoxGuestInternal.h"
+#include <VBox/version.h>
+#include <VBox/log.h>
+#include <iprt/assert.h>
+#include <iprt/initterm.h>
+#include <iprt/process.h>
+#include <iprt/mem.h>
+#include <iprt/asm.h>
+
+
+/*********************************************************************************************************************************
+*   Defined Constants And Macros                                                                                                 *
+*********************************************************************************************************************************/
+/** The module name. */
+#define DEVICE_NAME  "vboxguest"
+
+
+/*********************************************************************************************************************************
+*   Structures and Typedefs                                                                                                      *
+*********************************************************************************************************************************/
+struct VBoxGuestDeviceState
+{
+    /** Resource ID of the I/O port */
+    int                iIOPortResId;
+    /** Pointer to the I/O port resource. */
+    struct resource   *pIOPortRes;
+    /** Start address of the IO Port. */
+    uint16_t           uIOPortBase;
+    /** Resource ID of the MMIO area */
+    int                iVMMDevMemResId;
+    /** Pointer to the MMIO resource. */
+    struct resource   *pVMMDevMemRes;
+    /** Handle of the MMIO resource. */
+    bus_space_handle_t VMMDevMemHandle;
+    /** Size of the memory area. */
+    bus_size_t         VMMDevMemSize;
+    /** Mapping of the register space */
+    void              *pMMIOBase;
+    /** IRQ number */
+    int                iIrqResId;
+    /** IRQ resource handle. */
+    struct resource   *pIrqRes;
+    /** Pointer to the IRQ handler. */
+    void              *pfnIrqHandler;
+    /** VMMDev version */
+    uint32_t           u32Version;
+};
+
+
+/*********************************************************************************************************************************
+*   Internal Functions                                                                                                           *
+*********************************************************************************************************************************/
+/*
+ * Character device file handlers.
+ */
+static d_fdopen_t vgdrvNetBSDOpen;
+static d_close_t  vgdrvNetBSDClose;
+static d_ioctl_t  vgdrvNetBSDIOCtl;
+static d_write_t  vgdrvNetBSDWrite;
+static d_read_t   vgdrvNetBSDRead;
+static d_poll_t   vgdrvNetBSDPoll;
+
+/*
+ * IRQ related functions.
+ */
+static void vgdrvNetBSDRemoveIRQ(device_t pDevice, void *pvState);
+static int  vgdrvNetBSDAddIRQ(device_t pDevice, void *pvState);
+static int  vgdrvNetBSDISR(void *pvState);
+
+
+/*********************************************************************************************************************************
+*   Global Variables                                                                                                             *
+*********************************************************************************************************************************/
+static MALLOC_DEFINE(M_VBOXGUEST, "vboxguest", "VirtualBox Guest Device Driver");
+
+#ifndef D_NEEDMINOR
+# define D_NEEDMINOR 0
+#endif
+
+/*
+ * The /dev/vboxguest character device entry points.
+ */
+static struct cdevsw    g_vgdrvNetBSDChrDevSW =
+{
+    .d_version =        D_VERSION,
+    .d_flags =          D_TRACKCLOSE | D_NEEDMINOR,
+    .d_fdopen =         vgdrvNetBSDOpen,
+    .d_close =          vgdrvNetBSDClose,
+    .d_ioctl =          vgdrvNetBSDIOCtl,
+    .d_read =           vgdrvNetBSDRead,
+    .d_write =          vgdrvNetBSDWrite,
+    .d_poll =           vgdrvNetBSDPoll,
+    .d_name =           "vboxguest"
+};
+
+/** Device extention & session data association structure. */
+static VBOXGUESTDEVEXT      g_DevExt;
+
+/** List of cloned device. Managed by the kernel. */
+static struct clonedevs    *g_pvgdrvNetBSDClones;
+/** The dev_clone event handler tag. */
+static eventhandler_tag     g_vgdrvNetBSDEHTag;
+/** Reference counter */
+static volatile uint32_t    cUsers;
+/** selinfo structure used for polling. */
+static struct selinfo       g_SelInfo;
+
+/**
+ * DEVFS event handler.
+ */
+static void vgdrvNetBSDClone(void *pvArg, struct ucred *pCred, char *pszName, int cchName, struct cdev **ppDev)
+{
+    int iUnit;
+    int rc;
+
+    Log(("vgdrvNetBSDClone: pszName=%s ppDev=%p\n", pszName, ppDev));
+
+    /*
+     * One device node per user, si_drv1 points to the session.
+     * /dev/vboxguest<N> where N = {0...255}.
+     */
+    if (!ppDev)
+        return;
+    if (strcmp(pszName, "vboxguest") == 0)
+        iUnit =  -1;
+    else if (dev_stdclone(pszName, NULL, "vboxguest", &iUnit) != 1)
+        return;
+    if (iUnit >= 256)
+    {
+        Log(("vgdrvNetBSDClone: iUnit=%d >= 256 - rejected\n", iUnit));
+        return;
+    }
+
+    Log(("vgdrvNetBSDClone: pszName=%s iUnit=%d\n", pszName, iUnit));
+
+    rc = clone_create(&g_pvgdrvNetBSDClones, &g_vgdrvNetBSDChrDevSW, &iUnit, ppDev, 0);
+    Log(("vgdrvNetBSDClone: clone_create -> %d; iUnit=%d\n", rc, iUnit));
+    if (rc)
+    {
+        *ppDev = make_dev(&g_vgdrvNetBSDChrDevSW,
+                          iUnit,
+                          UID_ROOT,
+                          GID_WHEEL,
+                          0664,
+                          "vboxguest%d", iUnit);
+        if (*ppDev)
+        {
+            dev_ref(*ppDev);
+            (*ppDev)->si_flags |= SI_CHEAPCLONE;
+            Log(("vgdrvNetBSDClone: Created *ppDev=%p iUnit=%d si_drv1=%p si_drv2=%p\n",
+                     *ppDev, iUnit, (*ppDev)->si_drv1, (*ppDev)->si_drv2));
+            (*ppDev)->si_drv1 = (*ppDev)->si_drv2 = NULL;
+        }
+        else
+            Log(("vgdrvNetBSDClone: make_dev iUnit=%d failed\n", iUnit));
+    }
+    else
+        Log(("vgdrvNetBSDClone: Existing *ppDev=%p iUnit=%d si_drv1=%p si_drv2=%p\n",
+             *ppDev, iUnit, (*ppDev)->si_drv1, (*ppDev)->si_drv2));
+}
+
+/**
+ * File open handler
+ *
+ */
+static int vgdrvNetBSDOpen(struct cdev *pDev, int fOpen, struct thread *pTd)
+{
+    int                 rc;
+    PVBOXGUESTSESSION   pSession;
+
+    LogFlow(("vgdrvNetBSDOpen:\n"));
+
+    /*
+     * Try grab it (we don't grab the giant, remember).
+     */
+    if (!ASMAtomicCmpXchgPtr(&pDev->si_drv1, (void *)0x42, NULL))
+        return EBUSY;
+
+    /*
+     * Create a new session.
+     */
+    rc = VGDrvCommonCreateUserSession(&g_DevExt, &pSession);
+    if (RT_SUCCESS(rc))
+    {
+        if (ASMAtomicCmpXchgPtr(&pDev->si_drv1, pSession, (void *)0x42))
+        {
+            Log(("vgdrvNetBSDOpen: success - g_DevExt=%p pSession=%p rc=%d pid=%d\n", &g_DevExt, pSession, rc, (int)RTProcSelf()));
+            ASMAtomicIncU32(&cUsers);
+            return 0;
+        }
+
+        VGDrvCommonCloseSession(&g_DevExt, pSession);
+    }
+
+    LogRel(("vgdrvNetBSDOpen: failed. rc=%d\n", rc));
+    return RTErrConvertToErrno(rc);
+}
+
+/**
+ * File close handler
+ *
+ */
+static int vgdrvNetBSDClose(struct cdev *pDev, int fFile, int DevType, struct thread *pTd)
+{
+    PVBOXGUESTSESSION pSession = (PVBOXGUESTSESSION)pDev->si_drv1;
+    Log(("vgdrvNetBSDClose: fFile=%#x pSession=%p\n", fFile, pSession));
+
+    /*
+     * Close the session if it's still hanging on to the device...
+     */
+    if (VALID_PTR(pSession))
+    {
+        VGDrvCommonCloseSession(&g_DevExt, pSession);
+        if (!ASMAtomicCmpXchgPtr(&pDev->si_drv1, NULL, pSession))
+            Log(("vgdrvNetBSDClose: si_drv1=%p expected %p!\n", pDev->si_drv1, pSession));
+        ASMAtomicDecU32(&cUsers);
+        /* Don't use destroy_dev here because it may sleep resulting in a hanging user process. */
+        destroy_dev_sched(pDev);
+    }
+    else
+        Log(("vgdrvNetBSDClose: si_drv1=%p!\n", pSession));
+    return 0;
+}
+
+/**
+ * IOCTL handler
+ *
+ */
+static int vgdrvNetBSDIOCtl(struct cdev *pDev, u_long ulCmd, caddr_t pvData, int fFile, struct thread *pTd)
+{
+    LogFlow(("vgdrvNetBSDIOCtl\n"));
+
+    int rc = 0;
+
+    /*
+     * Validate the input.
+     */
+    PVBOXGUESTSESSION pSession = (PVBOXGUESTSESSION)pDev->si_drv1;
+    if (RT_UNLIKELY(!VALID_PTR(pSession)))
+        return EINVAL;
+
+    /*
+     * Validate the request wrapper.
+     */
+    if (IOCPARM_LEN(ulCmd) != sizeof(VBGLBIGREQ))
+    {
+        Log(("vgdrvNetBSDIOCtl: bad request %lu size=%lu expected=%d\n", ulCmd, IOCPARM_LEN(ulCmd), sizeof(VBGLBIGREQ)));
+        return ENOTTY;
+    }
+
+    PVBGLBIGREQ ReqWrap = (PVBGLBIGREQ)pvData;
+    if (ReqWrap->u32Magic != VBGLBIGREQ_MAGIC)
+    {
+        Log(("vgdrvNetBSDIOCtl: bad magic %#x; pArg=%p Cmd=%lu.\n", ReqWrap->u32Magic, pvData, ulCmd));
+        return EINVAL;
+    }
+    if (RT_UNLIKELY(   ReqWrap->cbData == 0
+                    || ReqWrap->cbData > _1M*16))
+    {
+        printf("vgdrvNetBSDIOCtl: bad size %#x; pArg=%p Cmd=%lu.\n", ReqWrap->cbData, pvData, ulCmd);
+        return EINVAL;
+    }
+
+    /*
+     * Read the request.
+     */
+    void *pvBuf = RTMemTmpAlloc(ReqWrap->cbData);
+    if (RT_UNLIKELY(!pvBuf))
+    {
+        Log(("vgdrvNetBSDIOCtl: RTMemTmpAlloc failed to alloc %d bytes.\n", ReqWrap->cbData));
+        return ENOMEM;
+    }
+
+    rc = copyin((void *)(uintptr_t)ReqWrap->pvDataR3, pvBuf, ReqWrap->cbData);
+    if (RT_UNLIKELY(rc))
+    {
+        RTMemTmpFree(pvBuf);
+        Log(("vgdrvNetBSDIOCtl: copyin failed; pvBuf=%p pArg=%p Cmd=%lu. rc=%d\n", pvBuf, pvData, ulCmd, rc));
+        return EFAULT;
+    }
+    if (RT_UNLIKELY(   ReqWrap->cbData != 0
+                    && !VALID_PTR(pvBuf)))
+    {
+        RTMemTmpFree(pvBuf);
+        Log(("vgdrvNetBSDIOCtl: pvBuf invalid pointer %p\n", pvBuf));
+        return EINVAL;
+    }
+    Log(("vgdrvNetBSDIOCtl: pSession=%p pid=%d.\n", pSession, (int)RTProcSelf()));
+
+    /*
+     * Process the IOCtl.
+     */
+    size_t cbDataReturned;
+    rc = VGDrvCommonIoCtl(ulCmd, &g_DevExt, pSession, pvBuf, ReqWrap->cbData, &cbDataReturned);
+    if (RT_SUCCESS(rc))
+    {
+        rc = 0;
+        if (RT_UNLIKELY(cbDataReturned > ReqWrap->cbData))
+        {
+            Log(("vgdrvNetBSDIOCtl: too much output data %d expected %d\n", cbDataReturned, ReqWrap->cbData));
+            cbDataReturned = ReqWrap->cbData;
+        }
+        if (cbDataReturned > 0)
+        {
+            rc = copyout(pvBuf, (void *)(uintptr_t)ReqWrap->pvDataR3, cbDataReturned);
+            if (RT_UNLIKELY(rc))
+            {
+                Log(("vgdrvNetBSDIOCtl: copyout failed; pvBuf=%p pArg=%p Cmd=%lu. rc=%d\n", pvBuf, pvData, ulCmd, rc));
+                rc = EFAULT;
+            }
+        }
+    }
+    else
+    {
+        Log(("vgdrvNetBSDIOCtl: VGDrvCommonIoCtl failed. rc=%d\n", rc));
+        rc = EFAULT;
+    }
+    RTMemTmpFree(pvBuf);
+    return rc;
+}
+
+static int vgdrvNetBSDPoll(struct cdev *pDev, int fEvents, struct thread *td)
+{
+    int fEventsProcessed;
+
+    LogFlow(("vgdrvNetBSDPoll: fEvents=%d\n", fEvents));
+
+    PVBOXGUESTSESSION pSession = (PVBOXGUESTSESSION)pDev->si_drv1;
+    if (RT_UNLIKELY(!VALID_PTR(pSession))) {
+        Log(("vgdrvNetBSDPoll: no state data for %s\n", devtoname(pDev)));
+        return (fEvents & (POLLHUP|POLLIN|POLLRDNORM|POLLOUT|POLLWRNORM));
+    }
+
+    uint32_t u32CurSeq = ASMAtomicUoReadU32(&g_DevExt.u32MousePosChangedSeq);
+    if (pSession->u32MousePosChangedSeq != u32CurSeq)
+    {
+        fEventsProcessed = fEvents & (POLLIN | POLLRDNORM);
+        pSession->u32MousePosChangedSeq = u32CurSeq;
+    }
+    else
+    {
+        fEventsProcessed = 0;
+
+        selrecord(td, &g_SelInfo);
+    }
+
+    return fEventsProcessed;
+}
+
+static int vgdrvNetBSDWrite(struct cdev *pDev, struct uio *pUio, int fIo)
+{
+    return 0;
+}
+
+static int vgdrvNetBSDRead(struct cdev *pDev, struct uio *pUio, int fIo)
+{
+    return 0;
+}
+
+static int vgdrvNetBSDDetach(device_t pDevice)
+{
+    struct VBoxGuestDeviceState *pState = device_get_softc(pDevice);
+
+    if (cUsers > 0)
+        return EBUSY;
+
+    /*
+     * Reverse what we did in vgdrvNetBSDAttach.
+     */
+    if (g_vgdrvNetBSDEHTag != NULL)
+        EVENTHANDLER_DEREGISTER(dev_clone, g_vgdrvNetBSDEHTag);
+
+    clone_cleanup(&g_pvgdrvNetBSDClones);
+
+    vgdrvNetBSDRemoveIRQ(pDevice, pState);
+
+    if (pState->pVMMDevMemRes)
+        bus_release_resource(pDevice, SYS_RES_MEMORY, pState->iVMMDevMemResId, pState->pVMMDevMemRes);
+    if (pState->pIOPortRes)
+        bus_release_resource(pDevice, SYS_RES_IOPORT, pState->iIOPortResId, pState->pIOPortRes);
+
+    VGDrvCommonDeleteDevExt(&g_DevExt);
+
+    RTR0Term();
+
+    return 0;
+}
+
+/**
+ * Interrupt service routine.
+ *
+ * @returns Whether the interrupt was from VMMDev.
+ * @param   pvState Opaque pointer to the device state.
+ */
+static int vgdrvNetBSDISR(void *pvState)
+{
+    LogFlow(("vgdrvNetBSDISR: pvState=%p\n", pvState));
+
+    bool fOurIRQ = VGDrvCommonISR(&g_DevExt);
+
+    return fOurIRQ ? 0 : 1;
+}
+
+void VGDrvNativeISRMousePollEvent(PVBOXGUESTDEVEXT pDevExt)
+{
+    LogFlow(("VGDrvNativeISRMousePollEvent:\n"));
+
+    /*
+     * Wake up poll waiters.
+     */
+    selwakeup(&g_SelInfo);
+}
+
+/**
+ * Sets IRQ for VMMDev.
+ *
+ * @returns NetBSD error code.
+ * @param   pDevice  Pointer to the device info structure.
+ * @param   pvState  Pointer to the state info structure.
+ */
+static int vgdrvNetBSDAddIRQ(device_t pDevice, void *pvState)
+{
+    int iResId = 0;
+    int rc = 0;
+    struct VBoxGuestDeviceState *pState = (struct VBoxGuestDeviceState *)pvState;
+
+    pState->pIrqRes = bus_alloc_resource_any(pDevice, SYS_RES_IRQ, &iResId, RF_SHAREABLE | RF_ACTIVE);
+
+    rc = bus_setup_intr(pDevice, pState->pIrqRes, INTR_TYPE_BIO, (driver_intr_t *)vgdrvNetBSDISR, pState, &pState->pfnIrqHandler);
+
+    if (rc)
+    {
+        pState->pfnIrqHandler = NULL;
+        return VERR_DEV_IO_ERROR;
+    }
+
+    pState->iIrqResId = iResId;
+
+    return VINF_SUCCESS;
+}
+
+/**
+ * Removes IRQ for VMMDev.
+ *
+ * @param   pDevice  Pointer to the device info structure.
+ * @param   pvState  Opaque pointer to the state info structure.
+ */
+static void vgdrvNetBSDRemoveIRQ(device_t pDevice, void *pvState)
+{
+    struct VBoxGuestDeviceState *pState = (struct VBoxGuestDeviceState *)pvState;
+
+    if (pState->pIrqRes)
+    {
+        bus_teardown_intr(pDevice, pState->pIrqRes, pState->pfnIrqHandler);
+        bus_release_resource(pDevice, SYS_RES_IRQ, 0, pState->pIrqRes);
+    }
+}
+
+static int vgdrvNetBSDAttach(device_t pDevice)
+{
+    int rc;
+    int iResId;
+    struct VBoxGuestDeviceState *pState;
+
+    cUsers = 0;
+
+    /*
+     * Initialize IPRT R0 driver, which internally calls OS-specific r0 init.
+     */
+    rc = RTR0Init(0);
+    if (RT_FAILURE(rc))
+    {
+        LogFunc(("RTR0Init failed.\n"));
+        return ENXIO;
+    }
+
+    pState = device_get_softc(pDevice);
+
+    /*
+     * Allocate I/O port resource.
+     */
+    iResId                 = PCIR_BAR(0);
+    pState->pIOPortRes     = bus_alloc_resource_any(pDevice, SYS_RES_IOPORT, &iResId, RF_ACTIVE);
+    pState->uIOPortBase    = rman_get_start(pState->pIOPortRes);
+    pState->iIOPortResId   = iResId;
+    if (pState->uIOPortBase)
+    {
+        /*
+         * Map the MMIO region.
+         */
+        iResId                   = PCIR_BAR(1);
+        pState->pVMMDevMemRes    = bus_alloc_resource_any(pDevice, SYS_RES_MEMORY, &iResId, RF_ACTIVE);
+        pState->VMMDevMemHandle  = rman_get_bushandle(pState->pVMMDevMemRes);
+        pState->VMMDevMemSize    = rman_get_size(pState->pVMMDevMemRes);
+
+        pState->pMMIOBase        = rman_get_virtual(pState->pVMMDevMemRes);
+        pState->iVMMDevMemResId  = iResId;
+        if (pState->pMMIOBase)
+        {
+            /*
+             * Call the common device extension initializer.
+             */
+            rc = VGDrvCommonInitDevExt(&g_DevExt, pState->uIOPortBase,
+                                       pState->pMMIOBase, pState->VMMDevMemSize,
+#if ARCH_BITS == 64
+                                       VBOXOSTYPE_NetBSD_x64,
+#else
+                                       VBOXOSTYPE_NetBSD,
+#endif
+                                       VMMDEV_EVENT_MOUSE_POSITION_CHANGED);
+            if (RT_SUCCESS(rc))
+            {
+                /*
+                 * Add IRQ of VMMDev.
+                 */
+                rc = vgdrvNetBSDAddIRQ(pDevice, pState);
+                if (RT_SUCCESS(rc))
+                {
+                    /*
+                     * Configure device cloning.
+                     */
+                    clone_setup(&g_pvgdrvNetBSDClones);
+                    g_vgdrvNetBSDEHTag = EVENTHANDLER_REGISTER(dev_clone, vgdrvNetBSDClone, 0, 1000);
+                    if (g_vgdrvNetBSDEHTag)
+                    {
+                        printf(DEVICE_NAME ": loaded successfully\n");
+                        return 0;
+                    }
+
+                    printf(DEVICE_NAME ": EVENTHANDLER_REGISTER(dev_clone,,,) failed\n");
+                    clone_cleanup(&g_pvgdrvNetBSDClones);
+                    vgdrvNetBSDRemoveIRQ(pDevice, pState);
+                }
+                else
+                    printf((DEVICE_NAME ": VGDrvCommonInitDevExt failed.\n"));
+                VGDrvCommonDeleteDevExt(&g_DevExt);
+            }
+            else
+                printf((DEVICE_NAME ": vgdrvNetBSDAddIRQ failed.\n"));
+        }
+        else
+            printf((DEVICE_NAME ": MMIO region setup failed.\n"));
+    }
+    else
+        printf((DEVICE_NAME ": IOport setup failed.\n"));
+
+    RTR0Term();
+    return ENXIO;
+}
+
+static int vgdrvNetBSDProbe(device_t pDevice)
+{
+    if ((pci_get_vendor(pDevice) == VMMDEV_VENDORID) && (pci_get_device(pDevice) == VMMDEV_DEVICEID))
+        return 0;
+
+    return ENXIO;
+}
+
+static device_method_t vgdrvNetBSDMethods[] =
+{
+    /* Device interface. */
+    DEVMETHOD(device_probe,  vgdrvNetBSDProbe),
+    DEVMETHOD(device_attach, vgdrvNetBSDAttach),
+    DEVMETHOD(device_detach, vgdrvNetBSDDetach),
+    {0,0}
+};
+
+static driver_t vgdrvNetBSDDriver =
+{
+    DEVICE_NAME,
+    vgdrvNetBSDMethods,
+    sizeof(struct VBoxGuestDeviceState),
+};
+
+static devclass_t vgdrvNetBSDClass;
+
+DRIVER_MODULE(vboxguest, pci, vgdrvNetBSDDriver, vgdrvNetBSDClass, 0, 0);
+MODULE_VERSION(vboxguest, 1);
+
+/* Common code that depend on g_DevExt. */
+#include "VBoxGuestIDC-unix.c.h"
