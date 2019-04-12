$NetBSD$

	For SCSI ioctl to work on NetBSD the device must be open for writing.

--- core/src/stored/dir_cmd.cc.orig	2018-12-20 08:51:51.000000000 +0000
+++ core/src/stored/dir_cmd.cc
@@ -976,7 +976,7 @@ static bool MountCmd(JobControlRecord *j
                TryAutoloadDevice(jcr, dcr, slot, "");
             }
             /* We freed the device, so reopen it and wake any waiting threads */
-            if (!dev->open(dcr, OPEN_READ_ONLY)) {
+            if (!dev->open(dcr, dev->device->drive_crypto_enabled ? OPEN_READ_WRITE : OPEN_READ_ONLY)) {
                dir->fsend(_("3901 Unable to open device %s: ERR=%s\n"), dev->print_name(), dev->bstrerror());
                if (dev->blocked() == BST_UNMOUNTED) {
                   /* We blocked the device, so unblock it */
@@ -1027,7 +1027,7 @@ static bool MountCmd(JobControlRecord *j
                                "If this is not a blank tape, try unmounting and remounting the Volume.\n"), dev->print_name());
                }
             } else if (dev->IsTape()) {
-               if (!dev->open(dcr, OPEN_READ_ONLY)) {
+               if (!dev->open(dcr, dev->device->drive_crypto_enabled ? OPEN_READ_WRITE : OPEN_READ_ONLY)) {
                   dir->fsend(_("3901 Unable to open device %s: ERR=%s\n"), dev->print_name(), dev->bstrerror());
                   break;
                }
