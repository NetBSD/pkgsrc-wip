$NetBSD$

	The original hooks did not clear the key soon enough.
	It was possible to change media in the tape library 
	without the key being cleared causing key confusion
	when bareos operation was mixe with other library clients.
	Now the key is cleared whenever the device is closed.

--- core/src/plugins/stored/scsicrypto-sd.cc.orig	2019-01-31 11:39:26.000000000 +0000
+++ core/src/plugins/stored/scsicrypto-sd.cc
@@ -191,6 +191,7 @@ static bRC newPlugin(bpContext *ctx)
     * bsdEventLabelWrite - Write of volume label clear key as volume
     *                      labels are unencrypted.
     * bsdEventVolumeUnload - Unload of volume clear key
+    * bsdEventDeviceClose  - Unload of volume clear key (auto changer)
     * bsdEventReadError - Read error on volume see if its due to
     *                     the fact encryption is enabled and we
     *                     have either the wrong key loaded or no key
@@ -201,11 +202,12 @@ static bRC newPlugin(bpContext *ctx)
     *                        of the volume loaded in the drive.
     */
    bfuncs->registerBareosEvents(ctx,
-                                7,
+                                8,
                                 bsdEventLabelRead,
                                 bsdEventLabelVerified,
                                 bsdEventLabelWrite,
                                 bsdEventVolumeUnload,
+                                bsdEventDeviceClose,
                                 bsdEventReadError,
                                 bsdEventDriveStatus,
                                 bsdEventVolumeStatus);
@@ -255,6 +257,7 @@ static bRC handlePluginEvent(bpContext *
    case bsdEventLabelRead:
    case bsdEventLabelWrite:
    case bsdEventVolumeUnload:
+   case bsdEventDeviceClose:
       return do_clear_scsi_encryption_key(value);
    case bsdEventLabelVerified:
       return do_set_scsi_encryption_key(value);
