$NetBSD$

--- src/VBox/Devices/USB/netbsd/USBProxyDevice-netbsd.cpp.orig	2016-07-08 22:38:39.836808295 +0000
+++ src/VBox/Devices/USB/netbsd/USBProxyDevice-netbsd.cpp
@@ -0,0 +1,1061 @@
+/*  USBProxyDevice-netbsd.cpp $ */
+/** @file
+ * USB device proxy - the NetBSD backend.
+ */
+
+/*
+ * Includes contributions from Hans Petter Selasky
+ *
+ * Copyright (C) 2006-2015 Oracle Corporation
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
+
+/*********************************************************************************************************************************
+*   Header Files                                                                                                                 *
+*********************************************************************************************************************************/
+#define LOG_GROUP LOG_GROUP_DRV_USBPROXY
+#ifdef VBOX
+# include <iprt/stdint.h>
+#endif
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/ioctl.h>
+#include <sys/poll.h>
+#include <stdint.h>
+#include <stdio.h>
+#include <string.h>
+#include <stdlib.h>
+#include <limits.h>
+#include <unistd.h>
+#include <fcntl.h>
+#include <errno.h>
+#include <dev/usb/usb.h>
+#include <dev/usb/usbdi.h>
+#include <dev/usb/usb_ioctl.h>
+
+#include <VBox/vmm/pdm.h>
+#include <VBox/err.h>
+#include <VBox/log.h>
+#include <VBox/vusb.h>
+#include <iprt/assert.h>
+#include <iprt/stream.h>
+#include <iprt/alloc.h>
+#include <iprt/thread.h>
+#include <iprt/time.h>
+#include <iprt/asm.h>
+#include <iprt/string.h>
+#include <iprt/file.h>
+#include <iprt/pipe.h>
+#include "../USBProxyDevice.h"
+
+/** Maximum endpoints supported. */
+#define USBNBSD_MAXENDPOINTS 127
+#define USBNBSD_MAXFRAMES 56
+
+/** This really needs to be defined in vusb.h! */
+#ifndef VUSB_DIR_TO_DEV
+# define VUSB_DIR_TO_DEV        0x00
+#endif
+
+
+/*********************************************************************************************************************************
+*   Structures and Typedefs                                                                                                      *
+*********************************************************************************************************************************/
+typedef struct USBENDPOINTNBSD
+{
+    /** Flag whether it is opened. */
+    bool     fOpen;
+    /** Flag whether it is cancelling. */
+    bool     fCancelling;
+    /** Buffer pointers. */
+    void    *apvData[USBNBSD_MAXFRAMES];
+    /** Buffer lengths. */
+    uint32_t acbData[USBNBSD_MAXFRAMES];
+    /** Initial buffer length. */
+    uint32_t cbData0;
+    /** Pointer to the URB. */
+    PVUSBURB pUrb;
+    /** Copy of endpoint number. */
+    unsigned iEpNum;
+    /** Maximum transfer length. */
+    unsigned cMaxIo;
+    /** Maximum frame count. */
+    unsigned cMaxFrames;
+} USBENDPOINTNBSD, *PUSBENDPOINTNBSD;
+
+/**
+ * Data for the NetBSD usb proxy backend.
+ */
+typedef struct USBPROXYDEVNBSD
+{
+    /** The open file. */
+    RTFILE                 hFile;
+    /** Flag whether an URB is cancelling. */
+    bool                   fCancelling;
+    /** Flag whether initialised or not */
+    bool                   fInit;
+    /** Pipe handle for waking up - writing end. */
+    RTPIPE                 hPipeWakeupW;
+    /** Pipe handle for waking up - reading end. */
+    RTPIPE                 hPipeWakeupR;
+    /** Software endpoint structures */
+    USBENDPOINTNBSD        aSwEndpoint[USBNBSD_MAXENDPOINTS];
+    /** Kernel endpoint structures */
+    struct usb_fs_endpoint aHwEndpoint[USBNBSD_MAXENDPOINTS];
+} USBPROXYDEVNBSD, *PUSBPROXYDEVNBSD;
+
+
+/*********************************************************************************************************************************
+*   Internal Functions                                                                                                           *
+*********************************************************************************************************************************/
+static int usbProxyNetBSDEndpointClose(PUSBPROXYDEV pProxyDev, int Endpoint);
+
+/**
+ * Wrapper for the ioctl call.
+ *
+ * This wrapper will repeat the call if we get an EINTR or EAGAIN. It can also
+ * handle ENODEV (detached device) errors.
+ *
+ * @returns whatever ioctl returns.
+ * @param   pProxyDev       The proxy device.
+ * @param   iCmd            The ioctl command / function.
+ * @param   pvArg           The ioctl argument / data.
+ * @param   fHandleNoDev    Whether to handle ENXIO.
+ * @internal
+ */
+static int usbProxyNetBSDDoIoCtl(PUSBPROXYDEV pProxyDev, unsigned long iCmd,
+                                  void *pvArg, bool fHandleNoDev)
+{
+    int rc = VINF_SUCCESS;
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+
+    LogFlow(("usbProxyNetBSDDoIoCtl: iCmd=%#x\n", iCmd));
+
+    do
+    {
+        rc = ioctl(RTFileToNative(pDevNBSD->hFile), iCmd, pvArg);
+        if (rc >= 0)
+            return VINF_SUCCESS;
+    } while (errno == EINTR);
+
+    if (errno == ENXIO && fHandleNoDev)
+    {
+        Log(("usbProxyNetBSDDoIoCtl: ENXIO -> unplugged. pProxyDev=%s\n",
+             pProxyDev->pUsbIns->pszName));
+        errno = ENODEV;
+    }
+    else if (errno != EAGAIN)
+    {
+        LogFlow(("usbProxyNetBSDDoIoCtl: Returned %d. pProxyDev=%s\n",
+                 errno, pProxyDev->pUsbIns->pszName));
+    }
+    return RTErrConvertFromErrno(errno);
+}
+
+/**
+ * Init USB subsystem.
+ */
+static int usbProxyNetBSDFsInit(PUSBPROXYDEV pProxyDev)
+{
+    struct usb_fs_init UsbFsInit;
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    int rc;
+
+    LogFlow(("usbProxyNetBSDFsInit: pProxyDev=%p\n", (void *)pProxyDev));
+
+    /* Sanity check */
+    AssertPtrReturn(pDevNBSD, VERR_INVALID_PARAMETER);
+
+    if (pDevNBSD->fInit == true)
+        return VINF_SUCCESS;
+
+    /* Zero default */
+    memset(&UsbFsInit, 0, sizeof(UsbFsInit));
+
+    UsbFsInit.pEndpoints = pDevNBSD->aHwEndpoint;
+    UsbFsInit.ep_index_max = USBNBSD_MAXENDPOINTS;
+
+    /* Init USB subsystem */
+    rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_FS_INIT, &UsbFsInit, false);
+    if (RT_SUCCESS(rc))
+        pDevNBSD->fInit = true;
+
+    return rc;
+}
+
+/**
+ * Uninit USB subsystem.
+ */
+static int usbProxyNetBSDFsUnInit(PUSBPROXYDEV pProxyDev)
+{
+    struct usb_fs_uninit UsbFsUninit;
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    int rc;
+
+    LogFlow(("usbProxyNetBSDFsUnInit: ProxyDev=%p\n", (void *)pProxyDev));
+
+    /* Sanity check */
+    AssertPtrReturn(pDevNBSD, VERR_INVALID_PARAMETER);
+
+    if (pDevNBSD->fInit != true)
+        return VINF_SUCCESS;
+
+    /* Close any open endpoints. */
+    for (unsigned n = 0; n != USBNBSD_MAXENDPOINTS; n++)
+        usbProxyNetBSDEndpointClose(pProxyDev, n);
+
+    /* Zero default */
+    memset(&UsbFsUninit, 0, sizeof(UsbFsUninit));
+
+    /* Uninit USB subsystem */
+    rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_FS_UNINIT, &UsbFsUninit, false);
+    if (RT_SUCCESS(rc))
+        pDevNBSD->fInit = false;
+
+    return rc;
+}
+
+/**
+ * Setup a USB request packet.
+ */
+static void usbProxyNetBSDSetupReq(struct usb_device_request *pSetupData,
+                                    uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue,
+                                    uint16_t wIndex, uint16_t wLength)
+{
+    LogFlow(("usbProxyNetBSDSetupReq: pSetupData=%p bmRequestType=%x "
+             "bRequest=%x wValue=%x wIndex=%x wLength=%x\n", (void *)pSetupData,
+             bmRequestType, bRequest, wValue, wIndex, wLength));
+
+    pSetupData->bmRequestType = bmRequestType;
+    pSetupData->bRequest = bRequest;
+
+    /* Handle endianess here. Currently no swapping is needed. */
+    pSetupData->wValue[0] = wValue & 0xff;
+    pSetupData->wValue[1] = (wValue >> 8) & 0xff;
+    pSetupData->wIndex[0] = wIndex & 0xff;
+    pSetupData->wIndex[1] = (wIndex >> 8) & 0xff;
+    pSetupData->wLength[0] = wLength & 0xff;
+    pSetupData->wLength[1] = (wLength >> 8) & 0xff;
+}
+
+static int usbProxyNetBSDEndpointOpen(PUSBPROXYDEV pProxyDev, int Endpoint, bool fIsoc, int index)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    PUSBENDPOINTNBSD pEndpointNBSD = NULL; /* shut up gcc */
+    struct usb_fs_endpoint *pXferEndpoint;
+    struct usb_fs_open UsbFsOpen;
+    int rc;
+
+    LogFlow(("usbProxyNetBSDEndpointOpen: pProxyDev=%p Endpoint=%d\n",
+             (void *)pProxyDev, Endpoint));
+
+    for (; index < USBNBSD_MAXENDPOINTS; index++)
+    {
+        pEndpointNBSD = &pDevNBSD->aSwEndpoint[index];
+        if (pEndpointNBSD->fCancelling)
+            continue;
+        if (   pEndpointNBSD->fOpen
+            && !pEndpointNBSD->pUrb
+            && (int)pEndpointNBSD->iEpNum == Endpoint)
+            return index;
+    }
+
+    if (index == USBNBSD_MAXENDPOINTS)
+    {
+        for (index = 0; index != USBNBSD_MAXENDPOINTS; index++)
+        {
+            pEndpointNBSD = &pDevNBSD->aSwEndpoint[index];
+            if (pEndpointNBSD->fCancelling)
+                continue;
+            if (!pEndpointNBSD->fOpen)
+                break;
+        }
+        if (index == USBNBSD_MAXENDPOINTS)
+            return -1;
+    }
+    /* set ppBuffer and pLength */
+
+    pXferEndpoint = &pDevNBSD->aHwEndpoint[index];
+    pXferEndpoint->ppBuffer = &pEndpointNBSD->apvData[0];
+    pXferEndpoint->pLength = &pEndpointNBSD->acbData[0];
+
+    LogFlow(("usbProxyNetBSDEndpointOpen: ep_index=%d ep_num=%d\n",
+             index, Endpoint));
+
+    memset(&UsbFsOpen, 0, sizeof(UsbFsOpen));
+
+    UsbFsOpen.ep_index = index;
+    UsbFsOpen.ep_no = Endpoint;
+    UsbFsOpen.max_bufsize = 256 * 1024;
+    /* Hardcoded assumption about the URBs we get. */
+
+    UsbFsOpen.max_frames = fIsoc ? USBNBSD_MAXFRAMES : 2;
+
+    rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_FS_OPEN, &UsbFsOpen, true);
+    if (RT_FAILURE(rc))
+    {
+        if (rc == VERR_RESOURCE_BUSY)
+            LogFlow(("usbProxyNetBSDEndpointOpen: EBUSY\n"));
+
+        return -1;
+    }
+    pEndpointNBSD->fOpen = true;
+    pEndpointNBSD->pUrb = NULL;
+    pEndpointNBSD->iEpNum = Endpoint;
+    pEndpointNBSD->cMaxIo = UsbFsOpen.max_bufsize;
+    pEndpointNBSD->cMaxFrames = UsbFsOpen.max_frames;
+
+    return index;
+}
+
+/**
+ * Close an endpoint.
+ *
+ * @returns VBox status code.
+ */
+static int usbProxyNetBSDEndpointClose(PUSBPROXYDEV pProxyDev, int Endpoint)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    PUSBENDPOINTNBSD pEndpointNBSD = &pDevNBSD->aSwEndpoint[Endpoint];
+    struct usb_fs_close UsbFsClose;
+    int rc = VINF_SUCCESS;
+
+    LogFlow(("usbProxyNetBSDEndpointClose: pProxyDev=%p Endpoint=%d\n",
+             (void *)pProxyDev, Endpoint));
+
+    /* check for cancelling */
+    if (pEndpointNBSD->pUrb != NULL)
+    {
+        pEndpointNBSD->fCancelling = true;
+        pDevNBSD->fCancelling = true;
+    }
+
+    /* check for opened */
+    if (pEndpointNBSD->fOpen)
+    {
+        pEndpointNBSD->fOpen = false;
+
+        /* Zero default */
+        memset(&UsbFsClose, 0, sizeof(UsbFsClose));
+
+        /* Set endpoint index */
+        UsbFsClose.ep_index = Endpoint;
+
+        /* Close endpoint */
+        rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_FS_CLOSE, &UsbFsClose, true);
+    }
+    return rc;
+}
+
+/**
+ * Opens the device file.
+ *
+ * @returns VBox status code.
+ * @param   pProxyDev       The device instance.
+ * @param   pszAddress      If we are using usbfs, this is the path to the
+ *                          device.  If we are using sysfs, this is a string of
+ *                          the form "sysfs:<sysfs path>//device:<device node>".
+ *                          In the second case, the two paths are guaranteed
+ *                          not to contain the substring "//".
+ * @param   pvBackend       Backend specific pointer, unused for the linux backend.
+ */
+static DECLCALLBACK(int) usbProxyNetBSDOpen(PUSBPROXYDEV pProxyDev, const char *pszAddress,
+                                             void *pvBackend)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    int rc;
+
+    LogFlow(("usbProxyNetBSDOpen: pProxyDev=%p pszAddress=%s\n", pProxyDev, pszAddress));
+
+    NOREF(pvBackend);
+
+    /*
+     * Try open the device node.
+     */
+    RTFILE hFile;
+    rc = RTFileOpen(&hFile, pszAddress, RTFILE_O_READWRITE | RTFILE_O_OPEN | RTFILE_O_DENY_NONE);
+    if (RT_SUCCESS(rc))
+    {
+        /*
+         * Initialize the NetBSD backend data.
+         */
+        pDevNBSD->hFile = hFile;
+        rc = usbProxyNetBSDFsInit(pProxyDev);
+        if (RT_SUCCESS(rc))
+        {
+            /*
+             * Create wakeup pipe.
+             */
+            rc = RTPipeCreate(&pDevNBSD->hPipeWakeupR, &pDevNBSD->hPipeWakeupW, 0);
+            if (RT_SUCCESS(rc))
+            {
+                LogFlow(("usbProxyNetBSDOpen(%p, %s): returns successfully hFile=%RTfile iActiveCfg=%d\n",
+                         pProxyDev, pszAddress, pDevNBSD->hFile, pProxyDev->iActiveCfg));
+
+                return VINF_SUCCESS;
+            }
+        }
+
+        RTFileClose(hFile);
+    }
+    else if (rc == VERR_ACCESS_DENIED)
+        rc = VERR_VUSB_USBFS_PERMISSION;
+
+    Log(("usbProxyNetBSDOpen(%p, %s) failed, rc=%d!\n",
+         pProxyDev, pszAddress, rc));
+
+    return rc;
+}
+
+
+/**
+ * Claims all the interfaces and figures out the
+ * current configuration.
+ *
+ * @returns VINF_SUCCESS.
+ * @param   pProxyDev       The proxy device.
+ */
+static DECLCALLBACK(int) usbProxyNetBSDInit(PUSBPROXYDEV pProxyDev)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    int rc;
+
+    LogFlow(("usbProxyNetBSDInit: pProxyDev=%s\n",
+             pProxyDev->pUsbIns->pszName));
+
+    /* Retrieve current active configuration. */
+    rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_GET_CONFIG,
+                                &pProxyDev->iActiveCfg, true);
+    if (RT_FAILURE(rc) || pProxyDev->iActiveCfg == 255)
+    {
+        pProxyDev->cIgnoreSetConfigs = 0;
+        pProxyDev->iActiveCfg = -1;
+    }
+    else
+    {
+        pProxyDev->cIgnoreSetConfigs = 1;
+        pProxyDev->iActiveCfg++;
+    }
+
+    Log(("usbProxyNetBSDInit: iActiveCfg=%d\n", pProxyDev->iActiveCfg));
+
+    return rc;
+}
+
+/**
+ * Closes the proxy device.
+ */
+static DECLCALLBACK(void) usbProxyNetBSDClose(PUSBPROXYDEV pProxyDev)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+
+    LogFlow(("usbProxyNetBSDClose: pProxyDev=%s\n", pProxyDev->pUsbIns->pszName));
+
+    /* sanity check */
+    AssertPtrReturnVoid(pDevNBSD);
+
+    usbProxyNetBSDFsUnInit(pProxyDev);
+
+    RTPipeClose(pDevNBSD->hPipeWakeupR);
+    RTPipeClose(pDevNBSD->hPipeWakeupW);
+
+    RTFileClose(pDevNBSD->hFile);
+    pDevNBSD->hFile = NIL_RTFILE;
+
+    LogFlow(("usbProxyNetBSDClose: returns\n"));
+}
+
+/**
+ * Reset a device.
+ *
+ * @returns VBox status code.
+ * @param   pDev    The device to reset.
+ */
+static DECLCALLBACK(int) usbProxyNetBSDReset(PUSBPROXYDEV pProxyDev, bool fResetOnNetBSD)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    int iParm;
+    int rc = VINF_SUCCESS;
+
+    LogFlow(("usbProxyNetBSDReset: pProxyDev=%s\n",
+             pProxyDev->pUsbIns->pszName));
+
+    if (!fResetOnNetBSD)
+        goto done;
+
+    /* We need to release kernel ressources first. */
+    rc = usbProxyNetBSDFsUnInit(pProxyDev);
+    if (RT_FAILURE(rc))
+        goto done;
+
+    /* Resetting is only possible as super-user, ignore any failures: */
+    iParm = 0;
+    rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_DEVICEENUMERATE, &iParm, true);
+    if (RT_FAILURE(rc))
+    {
+        /* Set the config instead of bus reset */
+        iParm = 255;
+        rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_SET_CONFIG, &iParm, true);
+        if (RT_SUCCESS(rc))
+        {
+            iParm = 0;
+            rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_SET_CONFIG, &iParm, true);
+        }
+    }
+    usleep(10000); /* nice it! */
+
+    /* Allocate kernel ressources again. */
+    rc = usbProxyNetBSDFsInit(pProxyDev);
+    if (RT_FAILURE(rc))
+        goto done;
+
+    /* Retrieve current active configuration. */
+    rc = usbProxyNetBSDInit(pProxyDev);
+
+done:
+    pProxyDev->cIgnoreSetConfigs = 2;
+
+    return rc;
+}
+
+/**
+ * SET_CONFIGURATION.
+ *
+ * The caller makes sure that it's not called first time after open or reset
+ * with the active interface.
+ *
+ * @returns success indicator.
+ * @param   pProxyDev       The device instance data.
+ * @param   iCfg            The configuration to set.
+ */
+static DECLCALLBACK(int) usbProxyNetBSDSetConfig(PUSBPROXYDEV pProxyDev, int iCfg)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    int iCfgIndex;
+    int rc;
+
+    LogFlow(("usbProxyNetBSDSetConfig: pProxyDev=%s cfg=%x\n",
+             pProxyDev->pUsbIns->pszName, iCfg));
+
+    /* We need to release kernel ressources first. */
+    rc = usbProxyNetBSDFsUnInit(pProxyDev);
+    if (RT_FAILURE(rc))
+    {
+        LogFlow(("usbProxyNetBSDSetInterface: Freeing kernel resources "
+                 "failed failed rc=%d\n", rc));
+        return rc;
+    }
+
+    if (iCfg == 0)
+    {
+        /* Unconfigure */
+        iCfgIndex = 255;
+    }
+    else
+    {
+        /* Get the configuration index matching the value. */
+        for (iCfgIndex = 0; iCfgIndex < pProxyDev->DevDesc.bNumConfigurations; iCfgIndex++)
+        {
+            if (pProxyDev->paCfgDescs[iCfgIndex].Core.bConfigurationValue == iCfg)
+                break;
+        }
+
+        if (iCfgIndex == pProxyDev->DevDesc.bNumConfigurations)
+        {
+            LogFlow(("usbProxyNetBSDSetConfig: configuration "
+                     "%d not found\n", iCfg));
+            return VERR_NOT_FOUND;
+        }
+    }
+
+    /* Set the config */
+    rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_SET_CONFIG, &iCfgIndex, true);
+    if (RT_FAILURE(rc))
+        return rc;
+
+    /* Allocate kernel ressources again. */
+    return usbProxyNetBSDFsInit(pProxyDev);
+}
+
+/**
+ * Claims an interface.
+ * @returns success indicator.
+ */
+static DECLCALLBACK(int) usbProxyNetBSDClaimInterface(PUSBPROXYDEV pProxyDev, int iIf)
+{
+    int rc;
+
+    LogFlow(("usbProxyNetBSDClaimInterface: pProxyDev=%s "
+             "ifnum=%x\n", pProxyDev->pUsbIns->pszName, iIf));
+
+    /*
+     * Try to detach kernel driver on this interface, ignore any
+     * failures
+     */
+    usbProxyNetBSDDoIoCtl(pProxyDev, USB_IFACE_DRIVER_DETACH, &iIf, true);
+
+    /* Try to claim interface */
+    return usbProxyNetBSDDoIoCtl(pProxyDev, USB_CLAIM_INTERFACE, &iIf, true);
+}
+
+/**
+ * Releases an interface.
+ * @returns success indicator.
+ */
+static DECLCALLBACK(int) usbProxyNetBSDReleaseInterface(PUSBPROXYDEV pProxyDev, int iIf)
+{
+    int rc;
+
+    LogFlow(("usbProxyNetBSDReleaseInterface: pProxyDev=%s "
+        "ifnum=%x\n", pProxyDev->pUsbIns->pszName, iIf));
+
+    return usbProxyNetBSDDoIoCtl(pProxyDev, USB_RELEASE_INTERFACE, &iIf, true);
+}
+
+/**
+ * SET_INTERFACE.
+ *
+ * @returns success indicator.
+ */
+static DECLCALLBACK(int) usbProxyNetBSDSetInterface(PUSBPROXYDEV pProxyDev, int iIf, int iAlt)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    struct usb_alt_interface UsbIntAlt;
+    int rc;
+
+    LogFlow(("usbProxyNetBSDSetInterface: pProxyDev=%p iIf=%x iAlt=%x\n",
+             pProxyDev, iIf, iAlt));
+
+    /* We need to release kernel ressources first. */
+    rc = usbProxyNetBSDFsUnInit(pProxyDev);
+    if (RT_FAILURE(rc))
+    {
+        LogFlow(("usbProxyNetBSDSetInterface: Freeing kernel resources "
+                 "failed failed rc=%d\n", rc));
+        return rc;
+    }
+    memset(&UsbIntAlt, 0, sizeof(UsbIntAlt));
+    UsbIntAlt.uai_interface_index = iIf;
+    UsbIntAlt.uai_alt_index = iAlt;
+
+    rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_SET_ALTINTERFACE, &UsbIntAlt, true);
+    if (RT_FAILURE(rc))
+    {
+        LogFlow(("usbProxyNetBSDSetInterface: Setting interface %d %d "
+                 "failed rc=%d\n", iIf, iAlt, rc));
+        return rc;
+    }
+
+    return usbProxyNetBSDFsInit(pProxyDev);
+}
+
+/**
+ * Clears the halted endpoint 'ep_num'.
+ */
+static DECLCALLBACK(int) usbProxyNetBSDClearHaltedEp(PUSBPROXYDEV pProxyDev, unsigned int ep_num)
+{
+    LogFlow(("usbProxyNetBSDClearHaltedEp: pProxyDev=%s ep_num=%u\n",
+             pProxyDev->pUsbIns->pszName, ep_num));
+
+    /*
+     * Clearing the zero control pipe doesn't make sense.
+     * Just ignore it.
+     */
+    if ((ep_num & 0xF) == 0)
+        return VINF_SUCCESS;
+
+    struct usb_ctl_request Req;
+    memset(&Req, 0, sizeof(Req));
+    usbProxyNetBSDSetupReq(&Req.ucr_request,
+                            VUSB_DIR_TO_DEV | VUSB_TO_ENDPOINT,
+                            VUSB_REQ_CLEAR_FEATURE, 0, ep_num, 0);
+
+    int rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_DO_REQUEST, &Req, true);
+
+    LogFlow(("usbProxyNetBSDClearHaltedEp: rc=%Rrc\n", rc));
+    return rc;
+}
+
+/**
+ * @copydoc USBPROXYBACK::pfnUrbQueue
+ */
+static DECLCALLBACK(int) usbProxyNetBSDUrbQueue(PUSBPROXYDEV pProxyDev, PVUSBURB pUrb)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    PUSBENDPOINTNBSD pEndpointNBSD;
+    struct usb_fs_endpoint *pXferEndpoint;
+    struct usb_fs_start UsbFsStart;
+    unsigned cFrames;
+    uint8_t *pbData;
+    int index;
+    int ep_num;
+    int rc;
+
+    LogFlow(("usbProxyNetBSDUrbQueue: pUrb=%p EndPt=%u Dir=%u\n",
+             pUrb, (unsigned)pUrb->EndPt, (unsigned)pUrb->enmDir));
+
+    ep_num = pUrb->EndPt;
+    if ((pUrb->enmType != VUSBXFERTYPE_MSG) && (pUrb->enmDir == VUSBDIRECTION_IN)) {
+        /* set IN-direction bit */
+        ep_num |= 0x80;
+    }
+
+    index = 0;
+
+retry:
+
+    index = usbProxyNetBSDEndpointOpen(pProxyDev, ep_num,
+                                        (pUrb->enmType == VUSBXFERTYPE_ISOC),
+                                        index);
+
+    if (index < 0)
+        return VERR_INVALID_PARAMETER;
+
+    pEndpointNBSD = &pDevNBSD->aSwEndpoint[index];
+    pXferEndpoint = &pDevNBSD->aHwEndpoint[index];
+
+    pbData = pUrb->abData;
+
+    switch (pUrb->enmType)
+    {
+        case VUSBXFERTYPE_MSG:
+        {
+            pEndpointNBSD->apvData[0] = pbData;
+            pEndpointNBSD->acbData[0] = 8;
+
+            /* check wLength */
+            if (pbData[6] || pbData[7])
+            {
+                pEndpointNBSD->apvData[1] = pbData + 8;
+                pEndpointNBSD->acbData[1] = pbData[6] | (pbData[7] << 8);
+                cFrames = 2;
+            }
+            else
+            {
+                pEndpointNBSD->apvData[1] = NULL;
+                pEndpointNBSD->acbData[1] = 0;
+                cFrames = 1;
+            }
+
+            LogFlow(("usbProxyNetBSDUrbQueue: pUrb->cbData=%u, 0x%02x, "
+                     "0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
+                     pUrb->cbData, pbData[0], pbData[1], pbData[2], pbData[3],
+                     pbData[4], pbData[5], pbData[6], pbData[7]));
+
+            pXferEndpoint->timeout = USB_FS_TIMEOUT_NONE;
+            pXferEndpoint->flags = USB_FS_FLAG_MULTI_SHORT_OK;
+            break;
+        }
+        case VUSBXFERTYPE_ISOC:
+        {
+            unsigned i;
+
+            for (i = 0; i < pUrb->cIsocPkts; i++)
+            {
+                if (i >= pEndpointNBSD->cMaxFrames)
+                    break;
+                pEndpointNBSD->apvData[i] = pbData + pUrb->aIsocPkts[i].off;
+                pEndpointNBSD->acbData[i] = pUrb->aIsocPkts[i].cb;
+            }
+            /* Timeout handling will be done during reap. */
+            pXferEndpoint->timeout = USB_FS_TIMEOUT_NONE;
+            pXferEndpoint->flags = USB_FS_FLAG_MULTI_SHORT_OK;
+            cFrames = i;
+            break;
+        }
+        default:
+        {
+            pEndpointNBSD->apvData[0] = pbData;
+            pEndpointNBSD->cbData0 = pUrb->cbData;
+
+            /* XXX maybe we have to loop */
+            if (pUrb->cbData > pEndpointNBSD->cMaxIo)
+                pEndpointNBSD->acbData[0] = pEndpointNBSD->cMaxIo;
+            else
+                pEndpointNBSD->acbData[0] = pUrb->cbData;
+
+            /* Timeout handling will be done during reap. */
+            pXferEndpoint->timeout = USB_FS_TIMEOUT_NONE;
+            pXferEndpoint->flags = pUrb->fShortNotOk ? 0 : USB_FS_FLAG_MULTI_SHORT_OK;
+            cFrames = 1;
+            break;
+        }
+    }
+
+    /* store number of frames */
+    pXferEndpoint->nFrames = cFrames;
+
+    /* zero-default */
+    memset(&UsbFsStart, 0, sizeof(UsbFsStart));
+
+    /* Start the transfer */
+    UsbFsStart.ep_index = index;
+
+    rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_FS_START, &UsbFsStart, true);
+
+    LogFlow(("usbProxyNetBSDUrbQueue: USB_FS_START returned rc=%d "
+             "len[0]=%u len[1]=%u cbData=%u index=%u ep_num=%u\n", rc,
+             (unsigned)pEndpointNBSD->acbData[0],
+             (unsigned)pEndpointNBSD->acbData[1],
+             (unsigned)pUrb->cbData,
+             (unsigned)index, (unsigned)ep_num));
+
+    if (RT_FAILURE(rc))
+    {
+        if (rc == VERR_RESOURCE_BUSY)
+        {
+            index++;
+            goto retry;
+        }
+        return rc;
+    }
+    pUrb->Dev.pvPrivate = (void *)(long)(index + 1);
+    pEndpointNBSD->pUrb = pUrb;
+
+    return rc;
+}
+
+/**
+ * Reap URBs in-flight on a device.
+ *
+ * @returns Pointer to a completed URB.
+ * @returns NULL if no URB was completed.
+ * @param   pProxyDev   The device.
+ * @param   cMillies    Number of milliseconds to wait. Use 0 to not wait at all.
+ */
+static DECLCALLBACK(PVUSBURB) usbProxyNetBSDUrbReap(PUSBPROXYDEV pProxyDev, RTMSINTERVAL cMillies)
+{
+    struct usb_fs_endpoint *pXferEndpoint;
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    PUSBENDPOINTNBSD pEndpointNBSD;
+    PVUSBURB pUrb;
+    struct usb_fs_complete UsbFsComplete;
+    struct pollfd pfd[2];
+    int rc;
+
+    LogFlow(("usbProxyNetBSDUrbReap: pProxyDev=%p, cMillies=%u\n",
+             pProxyDev, cMillies));
+
+repeat:
+
+    pUrb = NULL;
+
+    /* check for cancelled transfers */
+    if (pDevNBSD->fCancelling)
+    {
+        for (unsigned n = 0; n < USBNBSD_MAXENDPOINTS; n++)
+        {
+            pEndpointNBSD = &pDevNBSD->aSwEndpoint[n];
+            if (pEndpointNBSD->fCancelling)
+            {
+                pEndpointNBSD->fCancelling = false;
+                pUrb = pEndpointNBSD->pUrb;
+                pEndpointNBSD->pUrb = NULL;
+
+                if (pUrb != NULL)
+                    break;
+            }
+        }
+
+        if (pUrb != NULL)
+        {
+            pUrb->enmStatus = VUSBSTATUS_INVALID;
+            pUrb->Dev.pvPrivate = NULL;
+
+            switch (pUrb->enmType)
+            {
+                case VUSBXFERTYPE_MSG:
+                    pUrb->cbData = 0;
+                    break;
+                case VUSBXFERTYPE_ISOC:
+                    pUrb->cbData = 0;
+                    for (int n = 0; n < (int)pUrb->cIsocPkts; n++)
+                        pUrb->aIsocPkts[n].cb = 0;
+                    break;
+                default:
+                    pUrb->cbData = 0;
+                    break;
+            }
+            return pUrb;
+        }
+        pDevNBSD->fCancelling = false;
+    }
+    /* Zero default */
+
+    memset(&UsbFsComplete, 0, sizeof(UsbFsComplete));
+
+    /* Check if any endpoints are complete */
+    rc = usbProxyNetBSDDoIoCtl(pProxyDev, USB_FS_COMPLETE, &UsbFsComplete, true);
+    if (RT_SUCCESS(rc))
+    {
+        pXferEndpoint = &pDevNBSD->aHwEndpoint[UsbFsComplete.ep_index];
+        pEndpointNBSD = &pDevNBSD->aSwEndpoint[UsbFsComplete.ep_index];
+
+        LogFlow(("usbProxyNetBSDUrbReap: Reaped "
+                 "URB %#p\n", pEndpointNBSD->pUrb));
+
+        if (pXferEndpoint->status == USB_ERR_CANCELLED)
+            goto repeat;
+
+        pUrb = pEndpointNBSD->pUrb;
+        pEndpointNBSD->pUrb = NULL;
+        if (pUrb == NULL)
+            goto repeat;
+
+        switch (pXferEndpoint->status)
+        {
+            case USB_ERR_NORMAL_COMPLETION:
+                pUrb->enmStatus = VUSBSTATUS_OK;
+                break;
+            case USB_ERR_STALLED:
+                pUrb->enmStatus = VUSBSTATUS_STALL;
+                break;
+            default:
+                pUrb->enmStatus = VUSBSTATUS_INVALID;
+                break;
+        }
+
+        pUrb->Dev.pvPrivate = NULL;
+
+        switch (pUrb->enmType)
+        {
+            case VUSBXFERTYPE_MSG:
+                pUrb->cbData = pEndpointNBSD->acbData[0] + pEndpointNBSD->acbData[1];
+                break;
+            case VUSBXFERTYPE_ISOC:
+            {
+                int n;
+
+                if (pUrb->enmDir == VUSBDIRECTION_OUT)
+                    break;
+                pUrb->cbData = 0;
+                for (n = 0; n < (int)pUrb->cIsocPkts; n++)
+                {
+                    if (n >= (int)pEndpointNBSD->cMaxFrames)
+                        break;
+                    pUrb->cbData += pEndpointNBSD->acbData[n];
+                    pUrb->aIsocPkts[n].cb = pEndpointNBSD->acbData[n];
+                }
+                for (; n < (int)pUrb->cIsocPkts; n++)
+                    pUrb->aIsocPkts[n].cb = 0;
+
+                break;
+            }
+            default:
+                pUrb->cbData = pEndpointNBSD->acbData[0];
+                break;
+        }
+
+        LogFlow(("usbProxyNetBSDUrbReap: Status=%d epindex=%u "
+                 "len[0]=%d len[1]=%d\n",
+                 (int)pXferEndpoint->status,
+                 (unsigned)UsbFsComplete.ep_index,
+                 (unsigned)pEndpointNBSD->acbData[0],
+                 (unsigned)pEndpointNBSD->acbData[1]));
+
+    }
+    else if (cMillies != 0 && rc == VERR_RESOURCE_BUSY)
+    {
+        for (;;)
+        {
+            pfd[0].fd = RTFileToNative(pDevNBSD->hFile);
+            pfd[0].events = POLLIN | POLLRDNORM;
+            pfd[0].revents = 0;
+
+            pfd[1].fd = RTPipeToNative(pDevNBSD->hPipeWakeupR);
+            pfd[1].events = POLLIN | POLLRDNORM;
+            pfd[1].revents = 0;
+
+            rc = poll(pfd, 2, (cMillies == RT_INDEFINITE_WAIT) ? INFTIM : cMillies);
+            if (rc > 0)
+            {
+                if (pfd[1].revents & POLLIN)
+                {
+                    /* Got woken up, drain pipe. */
+                    uint8_t bRead;
+                    size_t cbIgnored = 0;
+                    RTPipeRead(pDevNBSD->hPipeWakeupR, &bRead, 1, &cbIgnored);
+                    /* Make sure we return from this function */
+                    cMillies = 0;
+                }
+                break;
+            }
+            if (rc == 0)
+                return NULL;
+            if (errno != EAGAIN)
+                return NULL;
+        }
+        goto repeat;
+    }
+    return pUrb;
+}
+
+/**
+ * Cancels the URB.
+ * The URB requires reaping, so we don't change its state.
+ */
+static DECLCALLBACK(int) usbProxyNetBSDUrbCancel(PUSBPROXYDEV pProxyDev, PVUSBURB pUrb)
+{
+    int index;
+
+    index = (int)(long)pUrb->Dev.pvPrivate - 1;
+
+    if (index < 0 || index >= USBNBSD_MAXENDPOINTS)
+        return VINF_SUCCESS; /* invalid index, pretend success. */
+
+    LogFlow(("usbProxyNetBSDUrbCancel: epindex=%u\n", (unsigned)index));
+    return usbProxyNetBSDEndpointClose(pProxyDev, index);
+}
+
+static DECLCALLBACK(int) usbProxyNetBSDWakeup(PUSBPROXYDEV pProxyDev)
+{
+    PUSBPROXYDEVNBSD pDevNBSD = USBPROXYDEV_2_DATA(pProxyDev, PUSBPROXYDEVNBSD);
+    size_t cbIgnored;
+
+    LogFlowFunc(("pProxyDev=%p\n", pProxyDev));
+
+    return RTPipeWrite(pDevNBSD->hPipeWakeupW, "", 1, &cbIgnored);
+}
+
+/**
+ * The NetBSD USB Proxy Backend.
+ */
+extern const USBPROXYBACK g_USBProxyDeviceHost =
+{
+    /* pszName */
+    "host",
+    /* cbBackend */
+    sizeof(USBPROXYDEVNBSD),
+    usbProxyNetBSDOpen,
+    usbProxyNetBSDInit,
+    usbProxyNetBSDClose,
+    usbProxyNetBSDReset,
+    usbProxyNetBSDSetConfig,
+    usbProxyNetBSDClaimInterface,
+    usbProxyNetBSDReleaseInterface,
+    usbProxyNetBSDSetInterface,
+    usbProxyNetBSDClearHaltedEp,
+    usbProxyNetBSDUrbQueue,
+    usbProxyNetBSDUrbCancel,
+    usbProxyNetBSDUrbReap,
+    usbProxyNetBSDWakeup,
+    0
+};
+
+/*
+ * Local Variables:
+ *  mode: c
+ *  c-file-style: "bsd"
+ *  c-basic-offset: 4
+ *  tab-width: 4
+ *  indent-tabs-mode: s
+ * End:
+ */
