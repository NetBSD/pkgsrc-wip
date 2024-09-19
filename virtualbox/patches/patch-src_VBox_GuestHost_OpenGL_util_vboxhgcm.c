$NetBSD$

--- src/VBox/GuestHost/OpenGL/util/vboxhgcm.c.orig	2016-03-04 19:29:23.000000000 +0000
+++ src/VBox/GuestHost/OpenGL/util/vboxhgcm.c
@@ -623,7 +623,7 @@ static int crVBoxHGCMCall(CRConnection *
     }
 # else
     int rc;
-#  if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#  if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     VBGLBIGREQ Hdr;
     Hdr.u32Magic = VBGLBIGREQ_MAGIC;
     Hdr.cbData = cbData;
@@ -1405,7 +1405,7 @@ static int crVBoxHGCMDoConnect( CRConnec
                         &info, sizeof (info),
                         &cbReturned,
                         NULL))
-#elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     VBGLBIGREQ Hdr;
     Hdr.u32Magic = VBGLBIGREQ_MAGIC;
     Hdr.cbData = sizeof(info);
@@ -1567,7 +1567,7 @@ static void crVBoxHGCMDoDisconnect( CRCo
         {
             crDebug("Disconnect failed with %x\n", GetLastError());
         }
-# elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+# elif defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         VBGLBIGREQ Hdr;
         Hdr.u32Magic = VBGLBIGREQ_MAGIC;
         Hdr.cbData = sizeof(info);
