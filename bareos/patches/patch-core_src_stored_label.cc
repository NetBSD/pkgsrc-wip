$NetBSD$

	For SCSI ioctl to work on NetBSD the device must be open for writing.

--- core/src/stored/label.cc.orig	2018-12-20 08:51:51.000000000 +0000
+++ core/src/stored/label.cc
@@ -86,7 +86,7 @@ int ReadDevVolumeLabel(DeviceControlReco
          dev->VolHdr.VolumeName[0]?dev->VolHdr.VolumeName:"*NULL*", dev->max_block_size);
 
    if (!dev->IsOpen()) {
-      if (!dev->open(dcr, OPEN_READ_ONLY)) {
+      if (!dev->open(dcr, OPEN_READ_WRITE)) {
          return VOL_IO_ERROR;
       }
    }
