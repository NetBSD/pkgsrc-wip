$NetBSD$

--- src/VBox/GuestHost/OpenGL/util/vboxhgsmi.c.orig	2016-03-04 19:29:23.000000000 +0000
+++ src/VBox/GuestHost/OpenGL/util/vboxhgsmi.c
@@ -255,7 +255,7 @@ static int crVBoxHGCMCall(void *pvData, 
     return VERR_NOT_SUPPORTED;
 # else
     int rc;
-#  if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#  if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     VBGLBIGREQ Hdr;
     Hdr.u32Magic = VBGLBIGREQ_MAGIC;
     Hdr.cbData = cbData;
@@ -1258,7 +1258,7 @@ static int crVBoxHGSMIDoConnect( CRConne
                         &info, sizeof (info),
                         &cbReturned,
                         NULL))
-#elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     VBGLBIGREQ Hdr;
     Hdr.u32Magic = VBGLBIGREQ_MAGIC;
     Hdr.cbData = sizeof(info);
@@ -1370,7 +1370,7 @@ static void crVBoxHGSMIDoDisconnect( CRC
         {
             crDebug("Disconnect failed with %x\n", GetLastError());
         }
-# elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         VBGLBIGREQ Hdr;
         Hdr.u32Magic = VBGLBIGREQ_MAGIC;
         Hdr.cbData = sizeof(info);
