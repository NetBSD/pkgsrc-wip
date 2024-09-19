$NetBSD$

--- src/VBox/HostDrivers/Support/netbsd/SUPDrv-netbsd.c.orig	2016-07-07 07:08:46.487236799 +0000
+++ src/VBox/HostDrivers/Support/netbsd/SUPDrv-netbsd.c
@@ -0,0 +1,632 @@
+/*  SUPDrv-netbsd.c $ */
+/** @file
+ * VBoxDrv - The VirtualBox Support Driver - NetBSD specifics.
+ */
+
+/*
+ * Copyright (c) 2007 knut st. osmundsen <bird-src-spam@anduin.net>
+ *
+ * Permission is hereby granted, free of charge, to any person
+ * obtaining a copy of this software and associated documentation
+ * files (the "Software"), to deal in the Software without
+ * restriction, including without limitation the rights to use,
+ * copy, modify, merge, publish, distribute, sublicense, and/or sell
+ * copies of the Software, and to permit persons to whom the
+ * Software is furnished to do so, subject to the following
+ * conditions:
+ *
+ * The above copyright notice and this permission notice shall be
+ * included in all copies or substantial portions of the Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
+ * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
+ * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
+ * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
+ * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
+ * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
+ * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
+ * OTHER DEALINGS IN THE SOFTWARE.
+ */
+
+
+/*********************************************************************************************************************************
+*   Header Files                                                                                                                 *
+*********************************************************************************************************************************/
+#define LOG_GROUP LOG_GROUP_SUP_DRV
+/* Deal with conflicts first. */
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
+
+#include "../SUPDrvInternal.h"
+#include <VBox/version.h>
+#include <iprt/initterm.h>
+#include <iprt/string.h>
+#include <iprt/spinlock.h>
+#include <iprt/process.h>
+#include <iprt/assert.h>
+#include <iprt/uuid.h>
+#include <VBox/log.h>
+#include <iprt/alloc.h>
+#include <iprt/err.h>
+#include <iprt/asm.h>
+
+#ifdef VBOX_WITH_HARDENING
+# define VBOXDRV_PERM 0600
+#else
+# define VBOXDRV_PERM 0666
+#endif
+
+
+/*********************************************************************************************************************************
+*   Internal Functions                                                                                                           *
+*********************************************************************************************************************************/
+static int VBoxDrvNetBSDModuleEvent(struct module *pMod, int enmEventType, void *pvArg);
+static int VBoxDrvNetBSDLoad(void);
+static int VBoxDrvNetBSDUnload(void);
+
+static d_open_t     VBoxDrvNetBSDOpenUsr;
+static d_open_t     VBoxDrvNetBSDOpenSys;
+static void         vboxdrvNetBSDDtr(void *pvData);
+static d_ioctl_t    VBoxDrvNetBSDIOCtl;
+static int          VBoxDrvNetBSDIOCtlSlow(PSUPDRVSESSION pSession, u_long ulCmd, caddr_t pvData, struct thread *pTd);
+
+
+/*********************************************************************************************************************************
+*   Global Variables                                                                                                             *
+*********************************************************************************************************************************/
+/**
+ * Module info structure used by the kernel.
+ */
+static moduledata_t         g_VBoxDrvNetBSDModule =
+{
+    "vboxdrv",
+    VBoxDrvNetBSDModuleEvent,
+    NULL
+};
+
+/** Declare the module as a pseudo device. */
+DECLARE_MODULE(vboxdrv,     g_VBoxDrvNetBSDModule, SI_SUB_PSEUDO, SI_ORDER_ANY);
+MODULE_VERSION(vboxdrv, 1);
+
+/**
+ * The /dev/vboxdrv character device entry points.
+ */
+static struct cdevsw        g_VBoxDrvNetBSDChrDevSwSys =
+{
+    .d_version =        D_VERSION,
+    .d_open =           VBoxDrvNetBSDOpenSys,
+    .d_ioctl =          VBoxDrvNetBSDIOCtl,
+    .d_name =           "vboxdrv"
+};
+/** The /dev/vboxdrv character device. */
+static struct cdev         *g_pVBoxDrvNetBSDChrDevSys;
+
+/**
+ * The /dev/vboxdrvu character device entry points.
+ */
+static struct cdevsw        g_VBoxDrvNetBSDChrDevSwUsr =
+{
+    .d_version =        D_VERSION,
+    .d_open =           VBoxDrvNetBSDOpenUsr,
+    .d_ioctl =          VBoxDrvNetBSDIOCtl,
+    .d_name =           "vboxdrvu"
+};
+/** The /dev/vboxdrvu character device. */
+static struct cdev         *g_pVBoxDrvNetBSDChrDevUsr;
+
+/** Reference counter. */
+static volatile uint32_t    g_cUsers;
+
+/** The device extention. */
+static SUPDRVDEVEXT         g_VBoxDrvNetBSDDevExt;
+
+/**
+ * Module event handler.
+ *
+ * @param   pMod            The module structure.
+ * @param   enmEventType    The event type (modeventtype_t).
+ * @param   pvArg           Module argument. NULL.
+ *
+ * @return  0 on success, errno.h status code on failure.
+ */
+static int VBoxDrvNetBSDModuleEvent(struct module *pMod, int enmEventType, void *pvArg)
+{
+    int rc;
+    switch (enmEventType)
+    {
+        case MOD_LOAD:
+            rc = VBoxDrvNetBSDLoad();
+            break;
+
+        case MOD_UNLOAD:
+            mtx_unlock(&Giant);
+            rc = VBoxDrvNetBSDUnload();
+            mtx_lock(&Giant);
+            break;
+
+        case MOD_SHUTDOWN:
+        case MOD_QUIESCE:
+        default:
+            return EOPNOTSUPP;
+    }
+
+    if (RT_SUCCESS(rc))
+        return 0;
+    return RTErrConvertToErrno(rc);
+}
+
+
+static int VBoxDrvNetBSDLoad(void)
+{
+    g_cUsers = 0;
+
+    /*
+     * Initialize the runtime.
+     */
+    int rc = RTR0Init(0);
+    if (RT_SUCCESS(rc))
+    {
+        Log(("VBoxDrvNetBSDLoad:\n"));
+
+        /*
+         * Initialize the device extension.
+         */
+        rc = supdrvInitDevExt(&g_VBoxDrvNetBSDDevExt, sizeof(SUPDRVSESSION));
+        if (RT_SUCCESS(rc))
+        {
+            /*
+             * Configure character devices. Add symbolic links for compatibility.
+             */
+            g_pVBoxDrvNetBSDChrDevSys = make_dev(&g_VBoxDrvNetBSDChrDevSwSys, 0, UID_ROOT, GID_WHEEL, VBOXDRV_PERM, "vboxdrv");
+            g_pVBoxDrvNetBSDChrDevUsr = make_dev(&g_VBoxDrvNetBSDChrDevSwUsr, 1, UID_ROOT, GID_WHEEL, 0666,         "vboxdrvu");
+            return VINF_SUCCESS;
+        }
+
+        printf("vboxdrv: supdrvInitDevExt failed, rc=%d\n", rc);
+        RTR0Term();
+    }
+    else
+        printf("vboxdrv: RTR0Init failed, rc=%d\n", rc);
+    return rc;
+}
+
+static int VBoxDrvNetBSDUnload(void)
+{
+    Log(("VBoxDrvNetBSDUnload:\n"));
+
+    if (g_cUsers > 0)
+        return VERR_RESOURCE_BUSY;
+
+    /*
+     * Reserve what we did in VBoxDrvNetBSDInit.
+     */
+    destroy_dev(g_pVBoxDrvNetBSDChrDevUsr);
+    destroy_dev(g_pVBoxDrvNetBSDChrDevSys);
+
+    supdrvDeleteDevExt(&g_VBoxDrvNetBSDDevExt);
+
+    RTR0TermForced();
+
+    memset(&g_VBoxDrvNetBSDDevExt, 0, sizeof(g_VBoxDrvNetBSDDevExt));
+    return VINF_SUCCESS;
+}
+
+
+/**
+ *
+ * @returns 0 on success, errno on failure.
+ *          EBUSY if the device is used by someone else.
+ * @param   pDev            The device node.
+ * @param   fOpen           The open flags.
+ * @param   iDevType        Some device type thing we don't use.
+ * @param   pTd             The thread.
+ * @param   fUnrestricted   Set if opening /dev/vboxdrv, clear if /dev/vboxdrvu.
+ */
+static int vboxdrvNetBSDOpenCommon(struct cdev *pDev, int fOpen, int iDevType, struct thread *pTd, bool fUnrestricted)
+{
+    PSUPDRVSESSION pSession;
+    int rc;
+
+    /*
+     * Let's be a bit picky about the flags...
+     */
+    if (fOpen != (FREAD | FWRITE /*=O_RDWR*/))
+    {
+        Log(("VBoxDrvNetBSDOpen: fOpen=%#x expected %#x\n", fOpen, O_RDWR));
+        return EINVAL;
+    }
+
+    /*
+     * Create a new session.
+     */
+    rc = supdrvCreateSession(&g_VBoxDrvNetBSDDevExt, true /* fUser */, fUnrestricted, &pSession);
+    if (RT_SUCCESS(rc))
+    {
+        /** @todo get (r)uid and (r)gid.
+        pSession->Uid = stuff;
+        pSession->Gid = stuff; */
+        rc = devfs_set_cdevpriv(pSession, vboxdrvNetBSDDtr); Assert(rc == 0);
+        Log(("VBoxDrvNetBSDOpen: pSession=%p\n", pSession));
+        ASMAtomicIncU32(&g_cUsers);
+        return 0;
+    }
+
+    return RTErrConvertToErrno(rc);
+}
+
+
+/** For vboxdrv. */
+static int VBoxDrvNetBSDOpenSys(struct cdev *pDev, int fOpen, int iDevType, struct thread *pTd)
+{
+    return vboxdrvNetBSDOpenCommon(pDev, fOpen, iDevType, pTd, true);
+}
+
+
+/** For vboxdrvu. */
+static int VBoxDrvNetBSDOpenUsr(struct cdev *pDev, int fOpen, int iDevType, struct thread *pTd)
+{
+    return vboxdrvNetBSDOpenCommon(pDev, fOpen, iDevType, pTd, false);
+}
+
+
+/**
+ * Close a file device previously opened by VBoxDrvNetBSDOpen.
+ *
+ * @returns 0 on success.
+ * @param   pvData      The session being closed.
+ */
+static void vboxdrvNetBSDDtr(void *pvData)
+{
+    PSUPDRVSESSION pSession = pvData;
+    Log(("vboxdrvNetBSDDtr: pSession=%p\n", pSession));
+
+    /*
+     * Close the session.
+     */
+    supdrvSessionRelease(pSession);
+    ASMAtomicDecU32(&g_cUsers);
+}
+
+
+/**
+ * I/O control request.
+ *
+ * @returns depends...
+ * @param   pDev        The device.
+ * @param   ulCmd       The command.
+ * @param   pvData      Pointer to the data.
+ * @param   fFile       The file descriptor flags.
+ * @param   pTd         The calling thread.
+ */
+static int VBoxDrvNetBSDIOCtl(struct cdev *pDev, u_long ulCmd, caddr_t pvData, int fFile, struct thread *pTd)
+{
+    PSUPDRVSESSION pSession;
+    devfs_get_cdevpriv((void **)&pSession);
+
+    /*
+     * Deal with the fast ioctl path first.
+     */
+    if (   (   ulCmd == SUP_IOCTL_FAST_DO_RAW_RUN
+            || ulCmd == SUP_IOCTL_FAST_DO_HM_RUN
+            || ulCmd == SUP_IOCTL_FAST_DO_NOP)
+        && pSession->fUnrestricted == true)
+        return supdrvIOCtlFast(ulCmd, *(uint32_t *)pvData, &g_VBoxDrvNetBSDDevExt, pSession);
+
+    return VBoxDrvNetBSDIOCtlSlow(pSession, ulCmd, pvData, pTd);
+}
+
+
+/**
+ * Deal with the 'slow' I/O control requests.
+ *
+ * @returns 0 on success, appropriate errno on failure.
+ * @param   pSession    The session.
+ * @param   ulCmd       The command.
+ * @param   pvData      The request data.
+ * @param   pTd         The calling thread.
+ */
+static int VBoxDrvNetBSDIOCtlSlow(PSUPDRVSESSION pSession, u_long ulCmd, caddr_t pvData, struct thread *pTd)
+{
+    PSUPREQHDR  pHdr;
+    uint32_t    cbReq = IOCPARM_LEN(ulCmd);
+    void       *pvUser = NULL;
+
+    /*
+     * Buffered request?
+     */
+    if ((IOC_DIRMASK & ulCmd) == IOC_INOUT)
+    {
+        pHdr = (PSUPREQHDR)pvData;
+        if (RT_UNLIKELY(cbReq < sizeof(*pHdr)))
+        {
+            OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: cbReq=%#x < %#x; ulCmd=%#lx\n", cbReq, (int)sizeof(*pHdr), ulCmd));
+            return EINVAL;
+        }
+        if (RT_UNLIKELY((pHdr->fFlags & SUPREQHDR_FLAGS_MAGIC_MASK) != SUPREQHDR_FLAGS_MAGIC))
+        {
+            OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: bad magic fFlags=%#x; ulCmd=%#lx\n", pHdr->fFlags, ulCmd));
+            return EINVAL;
+        }
+        if (RT_UNLIKELY(    RT_MAX(pHdr->cbIn, pHdr->cbOut) != cbReq
+                        ||  pHdr->cbIn < sizeof(*pHdr)
+                        ||  pHdr->cbOut < sizeof(*pHdr)))
+        {
+            OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: max(%#x,%#x) != %#x; ulCmd=%#lx\n", pHdr->cbIn, pHdr->cbOut, cbReq, ulCmd));
+            return EINVAL;
+        }
+    }
+    /*
+     * Big unbuffered request?
+     */
+    else if ((IOC_DIRMASK & ulCmd) == IOC_VOID && !cbReq)
+    {
+        /*
+         * Read the header, validate it and figure out how much that needs to be buffered.
+         */
+        SUPREQHDR Hdr;
+        pvUser = *(void **)pvData;
+        int rc = copyin(pvUser, &Hdr, sizeof(Hdr));
+        if (RT_UNLIKELY(rc))
+        {
+            OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: copyin(%p,Hdr,) -> %#x; ulCmd=%#lx\n", pvUser, rc, ulCmd));
+            return rc;
+        }
+        if (RT_UNLIKELY((Hdr.fFlags & SUPREQHDR_FLAGS_MAGIC_MASK) != SUPREQHDR_FLAGS_MAGIC))
+        {
+            OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: bad magic fFlags=%#x; ulCmd=%#lx\n", Hdr.fFlags, ulCmd));
+            return EINVAL;
+        }
+        cbReq = RT_MAX(Hdr.cbIn, Hdr.cbOut);
+        if (RT_UNLIKELY(    Hdr.cbIn < sizeof(Hdr)
+                        ||  Hdr.cbOut < sizeof(Hdr)
+                        ||  cbReq > _1M*16))
+        {
+            OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: max(%#x,%#x); ulCmd=%#lx\n", Hdr.cbIn, Hdr.cbOut, ulCmd));
+            return EINVAL;
+        }
+
+        /*
+         * Allocate buffer and copy in the data.
+         */
+        pHdr = (PSUPREQHDR)RTMemTmpAlloc(cbReq);
+        if (RT_UNLIKELY(!pHdr))
+        {
+            OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: failed to allocate buffer of %d bytes; ulCmd=%#lx\n", cbReq, ulCmd));
+            return ENOMEM;
+        }
+        rc = copyin(pvUser, pHdr, Hdr.cbIn);
+        if (RT_UNLIKELY(rc))
+        {
+            OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: copyin(%p,%p,%#x) -> %#x; ulCmd=%#lx\n",
+                        pvUser, pHdr, Hdr.cbIn, rc, ulCmd));
+            RTMemTmpFree(pHdr);
+            return rc;
+        }
+        if (Hdr.cbIn < cbReq)
+            RT_BZERO((uint8_t *)pHdr + Hdr.cbIn, cbReq - Hdr.cbIn);
+    }
+    else
+    {
+        Log(("VBoxDrvNetBSDIOCtlSlow: huh? cbReq=%#x ulCmd=%#lx\n", cbReq, ulCmd));
+        return EINVAL;
+    }
+
+    /*
+     * Process the IOCtl.
+     */
+    int rc = supdrvIOCtl(ulCmd, &g_VBoxDrvNetBSDDevExt, pSession, pHdr, cbReq);
+    if (RT_LIKELY(!rc))
+    {
+        /*
+         * If unbuffered, copy back the result before returning.
+         */
+        if (pvUser)
+        {
+            uint32_t cbOut = pHdr->cbOut;
+            if (cbOut > cbReq)
+            {
+                OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: too much output! %#x > %#x; uCmd=%#lx!\n", cbOut, cbReq, ulCmd));
+                cbOut = cbReq;
+            }
+            rc = copyout(pHdr, pvUser, cbOut);
+            if (RT_UNLIKELY(rc))
+                OSDBGPRINT(("VBoxDrvNetBSDIOCtlSlow: copyout(%p,%p,%#x) -> %d; uCmd=%#lx!\n", pHdr, pvUser, cbOut, rc, ulCmd));
+
+            Log(("VBoxDrvNetBSDIOCtlSlow: returns %d / %d ulCmd=%lx\n", 0, pHdr->rc, ulCmd));
+
+            /* cleanup */
+            RTMemTmpFree(pHdr);
+        }
+    }
+    else
+    {
+        /*
+         * The request failed, just clean up.
+         */
+        if (pvUser)
+            RTMemTmpFree(pHdr);
+
+        Log(("VBoxDrvNetBSDIOCtlSlow: ulCmd=%lx pData=%p failed, rc=%d\n", ulCmd, pvData, rc));
+        rc = EINVAL;
+    }
+
+    return rc;
+}
+
+
+/**
+ * The SUPDRV IDC entry point.
+ *
+ * @returns VBox status code, see supdrvIDC.
+ * @param   uReq        The request code.
+ * @param   pReq        The request.
+ */
+int VBOXCALL SUPDrvNetBSDIDC(uint32_t uReq, PSUPDRVIDCREQHDR pReq)
+{
+    PSUPDRVSESSION  pSession;
+
+    /*
+     * Some quick validations.
+     */
+    if (RT_UNLIKELY(!VALID_PTR(pReq)))
+        return VERR_INVALID_POINTER;
+
+    pSession = pReq->pSession;
+    if (pSession)
+    {
+        if (RT_UNLIKELY(!VALID_PTR(pReq->pSession)))
+            return VERR_INVALID_PARAMETER;
+        if (RT_UNLIKELY(pSession->pDevExt != &g_VBoxDrvNetBSDDevExt))
+            return VERR_INVALID_PARAMETER;
+    }
+    else if (RT_UNLIKELY(uReq != SUPDRV_IDC_REQ_CONNECT))
+        return VERR_INVALID_PARAMETER;
+
+    /*
+     * Do the job.
+     */
+    return supdrvIDC(uReq, &g_VBoxDrvNetBSDDevExt, pSession, pReq);
+}
+
+
+void VBOXCALL supdrvOSCleanupSession(PSUPDRVDEVEXT pDevExt, PSUPDRVSESSION pSession)
+{
+    NOREF(pDevExt);
+    NOREF(pSession);
+}
+
+
+void VBOXCALL supdrvOSSessionHashTabInserted(PSUPDRVDEVEXT pDevExt, PSUPDRVSESSION pSession, void *pvUser)
+{
+    NOREF(pDevExt); NOREF(pSession); NOREF(pvUser);
+}
+
+
+void VBOXCALL supdrvOSSessionHashTabRemoved(PSUPDRVDEVEXT pDevExt, PSUPDRVSESSION pSession, void *pvUser)
+{
+    NOREF(pDevExt); NOREF(pSession); NOREF(pvUser);
+}
+
+
+void VBOXCALL   supdrvOSObjInitCreator(PSUPDRVOBJ pObj, PSUPDRVSESSION pSession)
+{
+    NOREF(pObj);
+    NOREF(pSession);
+}
+
+
+bool VBOXCALL   supdrvOSObjCanAccess(PSUPDRVOBJ pObj, PSUPDRVSESSION pSession, const char *pszObjName, int *prc)
+{
+    NOREF(pObj);
+    NOREF(pSession);
+    NOREF(pszObjName);
+    NOREF(prc);
+    return false;
+}
+
+
+bool VBOXCALL  supdrvOSGetForcedAsyncTscMode(PSUPDRVDEVEXT pDevExt)
+{
+    return false;
+}
+
+
+bool VBOXCALL  supdrvOSAreCpusOfflinedOnSuspend(void)
+{
+    /** @todo verify this. */
+    return false;
+}
+
+
+bool VBOXCALL  supdrvOSAreTscDeltasInSync(void)
+{
+    return false;
+}
+
+
+int  VBOXCALL   supdrvOSLdrOpen(PSUPDRVDEVEXT pDevExt, PSUPDRVLDRIMAGE pImage, const char *pszFilename)
+{
+    NOREF(pDevExt); NOREF(pImage); NOREF(pszFilename);
+    return VERR_NOT_SUPPORTED;
+}
+
+
+void VBOXCALL   supdrvOSLdrNotifyOpened(PSUPDRVDEVEXT pDevExt, PSUPDRVLDRIMAGE pImage)
+{
+    NOREF(pDevExt); NOREF(pImage);
+}
+
+
+int  VBOXCALL   supdrvOSLdrValidatePointer(PSUPDRVDEVEXT pDevExt, PSUPDRVLDRIMAGE pImage, void *pv, const uint8_t *pbImageBits)
+{
+    NOREF(pDevExt); NOREF(pImage); NOREF(pv); NOREF(pbImageBits);
+    return VERR_NOT_SUPPORTED;
+}
+
+
+int  VBOXCALL   supdrvOSLdrLoad(PSUPDRVDEVEXT pDevExt, PSUPDRVLDRIMAGE pImage, const uint8_t *pbImageBits, PSUPLDRLOAD pReq)
+{
+    NOREF(pDevExt); NOREF(pImage); NOREF(pbImageBits); NOREF(pReq);
+    return VERR_NOT_SUPPORTED;
+}
+
+
+void VBOXCALL   supdrvOSLdrUnload(PSUPDRVDEVEXT pDevExt, PSUPDRVLDRIMAGE pImage)
+{
+    NOREF(pDevExt); NOREF(pImage);
+}
+
+
+#ifdef SUPDRV_WITH_MSR_PROBER
+
+int VBOXCALL    supdrvOSMsrProberRead(uint32_t uMsr, RTCPUID idCpu, uint64_t *puValue)
+{
+    NOREF(uMsr); NOREF(idCpu); NOREF(puValue);
+    return VERR_NOT_SUPPORTED;
+}
+
+
+int VBOXCALL    supdrvOSMsrProberWrite(uint32_t uMsr, RTCPUID idCpu, uint64_t uValue)
+{
+    NOREF(uMsr); NOREF(idCpu); NOREF(uValue);
+    return VERR_NOT_SUPPORTED;
+}
+
+
+int VBOXCALL    supdrvOSMsrProberModify(RTCPUID idCpu, PSUPMSRPROBER pReq)
+{
+    NOREF(idCpu); NOREF(pReq);
+    return VERR_NOT_SUPPORTED;
+}
+
+#endif /* SUPDRV_WITH_MSR_PROBER */
+
+
+SUPR0DECL(int) SUPR0Printf(const char *pszFormat, ...)
+{
+    va_list va;
+    char szMsg[256];
+    int cch;
+
+    va_start(va, pszFormat);
+    cch = RTStrPrintfV(szMsg, sizeof(szMsg), pszFormat, va);
+    va_end(va);
+
+    printf("%s", szMsg);
+
+    return cch;
+}
+
+
+SUPR0DECL(uint32_t) SUPR0GetKernelFeatures(void)
+{
+    return 0;
+}
