$NetBSD$

	For NetBSD SCSI ioctl to go through the device must be writable.

--- core/src/stored/acquire.cc.orig	2018-12-20 08:51:51.000000000 +0000
+++ core/src/stored/acquire.cc
@@ -270,7 +270,7 @@ bool AcquireDeviceForRead(DeviceControlR
        * it opens it. If it is a tape, it checks the volume name
        */
       Dmsg1(rdebuglevel, "stored: open vol=%s\n", dcr->VolumeName);
-      if (!dev->open(dcr, OPEN_READ_ONLY)) {
+      if (!dev->open(dcr, dev->device->drive_crypto_enabled ? OPEN_READ_WRITE : OPEN_READ_ONLY)) {
          if (!dev->poll) {
             Jmsg3(jcr, M_WARNING, 0, _("Read open device %s Volume \"%s\" failed: ERR=%s\n"),
                   dev->print_name(), dcr->VolumeName, dev->bstrerror());
