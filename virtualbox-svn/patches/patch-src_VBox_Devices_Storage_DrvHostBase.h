$NetBSD$

--- src/VBox/Devices/Storage/DrvHostBase.h.orig	2016-07-10 20:21:49.000000000 +0000
+++ src/VBox/Devices/Storage/DrvHostBase.h
@@ -145,6 +145,17 @@ typedef struct DRVHOSTBASE
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
