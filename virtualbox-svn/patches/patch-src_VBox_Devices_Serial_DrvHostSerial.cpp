$NetBSD$

--- src/VBox/Devices/Serial/DrvHostSerial.cpp.orig	2016-03-04 19:28:24.000000000 +0000
+++ src/VBox/Devices/Serial/DrvHostSerial.cpp
@@ -33,7 +33,7 @@
 #include <iprt/semaphore.h>
 #include <iprt/uuid.h>
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <errno.h>
 # ifdef RT_OS_SOLARIS
 #  include <sys/termios.h>
@@ -101,7 +101,7 @@ typedef struct DRVHOSTSERIAL
     /** the device path */
     char                        *pszDevicePath;
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /** the device handle */
     RTFILE                      hDeviceFile;
 # ifdef RT_OS_DARWIN
@@ -194,7 +194,7 @@ static DECLCALLBACK(int) drvHostSerialWr
 static DECLCALLBACK(int) drvHostSerialSetParameters(PPDMICHARCONNECTOR pInterface, unsigned Bps, char chParity, unsigned cDataBits, unsigned cStopBits)
 {
     PDRVHOSTSERIAL pThis = PDMICHAR_2_DRVHOSTSERIAL(pInterface);
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     struct termios *termiosSetup;
     int baud_rate;
 #elif defined(RT_OS_WINDOWS)
@@ -482,7 +482,7 @@ static DECLCALLBACK(int) drvHostSerialSe
         {
             /* copy the send queue so we get a linear buffer with the maximal size. */
             uint8_t ch = pThis->u8SendByte;
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 
             size_t cbWritten;
             rc = RTFileWrite(pThis->hDeviceFile, &ch, 1, &cbWritten);
@@ -679,7 +679,7 @@ static DECLCALLBACK(int) drvHostSerialRe
             }
             cbRemaining = cbRead;
 
-#elif defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 
             size_t cbRead;
             struct pollfd aFDs[2];
@@ -865,7 +865,7 @@ static DECLCALLBACK(int) drvHostSerialRe
 static DECLCALLBACK(int) drvHostSerialWakeupRecvThread(PPDMDRVINS pDrvIns, PPDMTHREAD /*pThread*/)
 {
     PDRVHOSTSERIAL pThis = PDMINS_2_DATA(pDrvIns, PDRVHOSTSERIAL);
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     size_t cbIgnored;
     return RTPipeWrite(pThis->hWakeupPipeW, "", 1, &cbIgnored);
 
@@ -878,7 +878,7 @@ static DECLCALLBACK(int) drvHostSerialWa
 #endif
 }
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 /* -=-=-=-=- Monitor thread -=-=-=-=- */
 
 /**
@@ -998,7 +998,7 @@ static DECLCALLBACK(int) drvHostSerialSe
 {
     PDRVHOSTSERIAL pThis = PDMICHAR_2_DRVHOSTSERIAL(pInterface);
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     int modemStateSet = 0;
     int modemStateClear = 0;
 
@@ -1046,7 +1046,7 @@ static DECLCALLBACK(int) drvHostSerialSe
 {
     PDRVHOSTSERIAL pThis = PDMICHAR_2_DRVHOSTSERIAL(pInterface);
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     if (fBreak)
         ioctl(RTFileToNative(pThis->hDeviceFile), TIOCSBRK);
     else
@@ -1085,7 +1085,7 @@ static DECLCALLBACK(void) drvHostSerialD
         pThis->SendSem = NIL_RTSEMEVENT;
     }
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 
     int rc = RTPipeClose(pThis->hWakeupPipeW); AssertRC(rc);
     pThis->hWakeupPipeW = NIL_RTPIPE;
@@ -1138,7 +1138,7 @@ static DECLCALLBACK(int) drvHostSerialCo
     /*
      * Init basic data members and interfaces.
      */
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     pThis->hDeviceFile  = NIL_RTFILE;
 # ifdef RT_OS_DARWIN
     pThis->hDeviceFileR = NIL_RTFILE;
@@ -1233,7 +1233,7 @@ static DECLCALLBACK(int) drvHostSerialCo
         {
             case VERR_ACCESS_DENIED:
                 return PDMDrvHlpVMSetError(pDrvIns, rc, RT_SRC_POS,
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                                            N_("Cannot open host device '%s' for read/write access. Check the permissions "
                                               "of that device ('/bin/ls -l %s'): Most probably you need to be member "
                                               "of the device group. Make sure that you logout/login after changing "
@@ -1251,7 +1251,7 @@ static DECLCALLBACK(int) drvHostSerialCo
     }
 
     /* Set to non blocking I/O */
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 
     fcntl(RTFileToNative(pThis->hDeviceFile), F_SETFL, O_NONBLOCK);
 # ifdef RT_OS_DARWIN
@@ -1296,7 +1296,7 @@ static DECLCALLBACK(int) drvHostSerialCo
     if (RT_FAILURE(rc))
         return PDMDrvHlpVMSetError(pDrvIns, rc, RT_SRC_POS, N_("HostSerial#%d cannot create send thread"), pDrvIns->iInstance);
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_LINUX) || defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /* Linux & darwin needs a separate thread which monitors the status lines. */
 # ifndef RT_OS_LINUX
     ioctl(RTFileToNative(pThis->hDeviceFile), TIOCMGET, &pThis->fStatusLines);
@@ -1368,4 +1368,3 @@ const PDMDRVREG g_DrvHostSerial =
     /* u32EndVersion */
     PDM_DRVREG_VERSION
 };
-
