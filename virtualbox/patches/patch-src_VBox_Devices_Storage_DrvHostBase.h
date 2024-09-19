$NetBSD$

--- src/VBox/Devices/Storage/DrvHostBase.h.orig	2016-03-04 19:28:24.000000000 +0000
+++ src/VBox/Devices/Storage/DrvHostBase.h
@@ -147,6 +147,17 @@ typedef struct DRVHOSTBASE
     lun_id_t                ScsiLunID;
 #endif
 
+#ifdef RT_OS_NETBSD
+    /** The block size. Set when querying the media size. */
+    uint32_t                cbBlock;
+    /** SCSI bus number. */
+    path_id_t               ScsiBus;
+    /** target ID of the passthrough device. */
+    target_id_t             ScsiTargetID;
+    /** LUN of the passthrough device. */
+    lun_id_t                ScsiLunID;
+#endif
+
     /**
      * Performs the locking / unlocking of the device.
      *
@@ -185,7 +196,7 @@ int DRVHostBaseInitFinish(PDRVHOSTBASE p
 int DRVHostBaseMediaPresent(PDRVHOSTBASE pThis);
 void DRVHostBaseMediaNotPresent(PDRVHOSTBASE pThis);
 DECLCALLBACK(void) DRVHostBaseDestruct(PPDMDRVINS pDrvIns);
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 DECLCALLBACK(int) DRVHostBaseScsiCmd(PDRVHOSTBASE pThis, const uint8_t *pbCmd, size_t cbCmd, PDMBLOCKTXDIR enmTxDir,
                                      void *pvBuf, uint32_t *pcbBuf, uint8_t *pbSense, size_t cbSense, uint32_t cTimeoutMillies);
 #endif
