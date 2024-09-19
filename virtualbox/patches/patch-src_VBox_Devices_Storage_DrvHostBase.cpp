$NetBSD$

--- src/VBox/Devices/Storage/DrvHostBase.cpp.orig	2016-03-04 19:28:24.000000000 +0000
+++ src/VBox/Devices/Storage/DrvHostBase.cpp
@@ -96,7 +96,7 @@ NTSTATUS __stdcall NtQueryVolumeInformat
         /*IN*/ ULONG                Length,
         /*IN*/ FS_INFORMATION_CLASS FileSystemInformationClass );
 
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/cdefs.h>
 # include <sys/param.h>
 # include <errno.h>
@@ -147,14 +147,14 @@ static DECLCALLBACK(int) drvHostBaseRead
     if (    pThis->fMediaPresent
         &&  pThis->ppScsiTaskDI
         &&  pThis->cbBlock)
-#elif RT_OS_FREEBSD
+#elif RT_OS_FREEBSD || defined(RT_OS_NETBSD)
     if (    pThis->fMediaPresent
         &&  pThis->cbBlock)
 #else
     if (pThis->fMediaPresent)
 #endif
     {
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         /*
          * Issue a READ(12) request.
          */
@@ -226,7 +226,7 @@ static DECLCALLBACK(int) drvHostBaseWrit
     {
         if (pThis->fMediaPresent)
         {
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             /** @todo write support... */
             rc = VERR_WRITE_PROTECT;
 
@@ -264,7 +264,7 @@ static DECLCALLBACK(int) drvHostBaseFlus
 
     if (pThis->fMediaPresent)
     {
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         rc = VINF_SUCCESS;
         /** @todo scsi device buffer flush... */
 #else
@@ -991,7 +991,7 @@ static int drvHostBaseOpen(PDRVHOSTBASE 
     IOObjectRelease(DVDServices);
     return rc;
 
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     RTFILE hFileDevice;
     int rc = RTFileOpen(&hFileDevice, pThis->pszDeviceOpen, RTFILE_O_READWRITE | RTFILE_O_OPEN | RTFILE_O_DENY_NONE);
     if (RT_FAILURE(rc))
@@ -1176,7 +1176,7 @@ static int drvHostBaseReopen(PDRVHOSTBAS
  */
 static DECLCALLBACK(int) drvHostBaseGetMediaSize(PDRVHOSTBASE pThis, uint64_t *pcb)
 {
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /*
      * Try a READ_CAPACITY command...
      */
@@ -1254,7 +1254,7 @@ static DECLCALLBACK(int) drvHostBaseGetM
 }
 
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 /**
  * Execute a SCSI command.
  *
@@ -1365,7 +1365,7 @@ DECLCALLBACK(int) DRVHostBaseScsiCmd(PDR
 
     (*ppScsiTaskI)->Release(ppScsiTaskI);
 
-# elif defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     int rc = VINF_SUCCESS;
     int rcBSD = 0;
     union ccb DeviceCCB;
@@ -2265,4 +2265,3 @@ int DRVHostBaseInitFinish(PDRVHOSTBASE p
         return src;
     return rc;
 }
-
