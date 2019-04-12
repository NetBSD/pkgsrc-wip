$NetBSD$

	Fix coding - was probably never tested with scsi-crypto flag

--- core/src/lib/scsi_lli.cc.orig	2018-12-20 08:51:51.000000000 +0000
+++ core/src/lib/scsi_lli.cc
@@ -384,6 +384,7 @@ bool CheckScsiAtEod(int fd)
 #elif defined(HAVE_NETBSD_OS) || defined(HAVE_OPENBSD_OS)
 
 #if defined(HAVE_NETBSD_OS)
+#include <sys/scsiio.h>
 #include <dev/scsipi/scsipi_all.h>
 #else
 #include <scsi/uscsi_all.h>
@@ -403,7 +404,7 @@ static inline bool do_scsi_cmd_page(int 
 {
    int rc;
    scsireq_t req;
-   SCSI_PAGE_SENSE *sense;
+   SCSI_PAGE_SENSE sense;
    bool opened_device = false;
    bool retval = false;
 
@@ -446,19 +447,17 @@ static inline bool do_scsi_cmd_page(int 
       retval = true;
       break;
    case SCCMD_SENSE:
-      sense = req.sense;
+      memcpy(&sense, &req.sense, sizeof sense < sizeof req.sense ? sizeof sense : sizeof req.sense);
       Emsg3(M_ERROR, 0, _("Sense Key: %0.2X ASC: %0.2X ASCQ: %0.2X\n"),
             LOBYTE(sense.senseKey), sense.addSenseCode, sense.addSenseCodeQual);
       break;
    case SCCMD_TIMEOUT:
       Emsg1(M_ERROR, 0, _("SCIOCCOMMAND ioctl on %s returned SCSI command timed out\n"),
-            devicename);
+            device_name);
       break;
    case SCCMD_BUSY:
       Emsg1(M_ERROR, 0, _("SCIOCCOMMAND ioctl on %s returned device is busy\n"),
-            devicename);
-      break;
-   case SCCMD_SENSE:
+            device_name);
       break;
    default:
       Emsg2(M_ERROR, 0, _("SCIOCCOMMAND ioctl on %s returned unknown status %d\n"),
