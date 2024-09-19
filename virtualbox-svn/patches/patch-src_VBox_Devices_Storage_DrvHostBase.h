$NetBSD$

--- src/VBox/Devices/Storage/DrvHostBase.h.orig	2016-08-05 16:42:58.000000000 +0000
+++ src/VBox/Devices/Storage/DrvHostBase.h
@@ -183,7 +183,7 @@ int DRVHostBaseInitFinish(PDRVHOSTBASE p
 int DRVHostBaseMediaPresent(PDRVHOSTBASE pThis);
 void DRVHostBaseMediaNotPresent(PDRVHOSTBASE pThis);
 DECLCALLBACK(void) DRVHostBaseDestruct(PPDMDRVINS pDrvIns);
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 DECLCALLBACK(int) DRVHostBaseScsiCmd(PDRVHOSTBASE pThis, const uint8_t *pbCmd, size_t cbCmd, PDMMEDIATXDIR enmTxDir,
                                      void *pvBuf, uint32_t *pcbBuf, uint8_t *pbSense, size_t cbSense, uint32_t cTimeoutMillies);
 #endif
