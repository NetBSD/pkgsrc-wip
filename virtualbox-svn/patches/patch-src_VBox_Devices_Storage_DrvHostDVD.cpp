$NetBSD$

--- src/VBox/Devices/Storage/DrvHostDVD.cpp.orig	2016-03-04 19:28:24.000000000 +0000
+++ src/VBox/Devices/Storage/DrvHostDVD.cpp
@@ -86,7 +86,7 @@
 # undef _interlockedbittestandreset64
 # undef USE_MEDIA_POLLING
 
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/cdefs.h>
 # include <sys/param.h>
 # include <stdio.h>
@@ -144,7 +144,7 @@ static DECLCALLBACK(int) drvHostDvdUnmou
             /*
              * Eject the disc.
              */
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             uint8_t abCmd[16] =
             {
                 SCSI_START_STOP_UNIT, 0, 0, 0, 2 /*eject+stop*/, 0,
@@ -234,7 +234,7 @@ static DECLCALLBACK(int) drvHostDvdUnmou
  */
 static DECLCALLBACK(int) drvHostDvdDoLock(PDRVHOSTBASE pThis, bool fLock)
 {
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     uint8_t abCmd[16] =
     {
         SCSI_PREVENT_ALLOW_MEDIUM_REMOVAL, 0, 0, 0, fLock, 0,
@@ -322,7 +322,7 @@ static DECLCALLBACK(int) drvHostDvdPoll(
     /*
      * Poll for media change.
      */
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #ifdef RT_OS_DARWIN
     AssertReturn(pThis->ppScsiTaskDI, VERR_INTERNAL_ERROR);
 #endif
@@ -392,7 +392,7 @@ static DECLCALLBACK(int) drvHostDvdPoll(
         /*
          * Poll for media change.
          */
-#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         /* taken care of above. */
 #elif defined(RT_OS_LINUX)
         bool fMediaChanged = ioctl(RTFileToNative(pThis->hFileDevice), CDROM_MEDIA_CHANGED, CDSL_CURRENT) == 1;
@@ -422,7 +422,7 @@ static DECLCALLBACK(int) drvHostDvdSendC
     int rc;
     LogFlow(("%s: cmd[0]=%#04x txdir=%d pcbBuf=%d timeout=%d\n", __FUNCTION__, pbCmd[0], enmTxDir, *pcbBuf, cTimeoutMillies));
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /*
      * Pass the request on to the internal scsi command interface.
      * The command seems to be 12 bytes long, the docs a bit copy&pasty on the command length point...
@@ -878,4 +878,3 @@ const PDMDRVREG g_DrvHostDVD =
     /* u32EndVersion */
     PDM_DRVREG_VERSION
 };
-
