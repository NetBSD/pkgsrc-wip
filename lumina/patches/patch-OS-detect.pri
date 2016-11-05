$NetBSD$

Without this options symbols will be missing
--- src-qt5/OS-detect.pri.orig	2016-11-05 21:23:58.063535163 +0000
+++ src-qt5/OS-detect.pri	2016-11-05 21:27:14.262295953 +0000
@@ -51,7 +51,7 @@
 
   }else : netbsd-*{
     OS = NetBSD
-    LIBS += -L/usr/local/lib -L/usr/lib
+    LIBS += -L/usr/pkg/lib -L/usr/lib -L/usr/X11R7/lib -Wl,-R/usr/X11R7/lib -Wl,-R/usr/pkg/lib
     #Use the defaults for everything else
 
   }else : linux-*{
