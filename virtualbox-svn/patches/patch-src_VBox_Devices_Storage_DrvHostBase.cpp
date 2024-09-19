$NetBSD$

--- src/VBox/Devices/Storage/DrvHostBase.cpp.orig	2016-08-05 16:42:58.000000000 +0000
+++ src/VBox/Devices/Storage/DrvHostBase.cpp
@@ -96,15 +96,18 @@ NTSTATUS __stdcall NtQueryVolumeInformat
         /*IN*/ ULONG                Length,
         /*IN*/ FS_INFORMATION_CLASS FileSystemInformationClass );
 
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/cdefs.h>
 # include <sys/param.h>
+# undef PVM
 # include <errno.h>
 # include <stdio.h>
-# include <cam/cam.h>
-# include <cam/cam_ccb.h>
-# include <cam/scsi/scsi_message.h>
-# include <cam/scsi/scsi_pass.h>
+# if defined(RT_OS_FREEBSD)
+#  include <cam/cam.h>
+#  include <cam/cam_ccb.h>
+#  include <cam/scsi/scsi_message.h>
+#  include <cam/scsi/scsi_pass.h>
+# endif
 # include <VBox/scsi.h>
 # include <iprt/log.h>
 #else
@@ -2237,4 +2240,3 @@ int DRVHostBaseInitFinish(PDRVHOSTBASE p
         return src;
     return rc;
 }
-
