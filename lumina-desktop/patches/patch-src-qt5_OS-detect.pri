$NetBSD$

Fix missing options symbols

--- src-qt5/OS-detect.pri.orig	2020-01-31 20:25:37.000000000 +0000
+++ src-qt5/OS-detect.pri
@@ -52,7 +52,7 @@ isEmpty(OS){
 
   }else : netbsd-*{
     OS = NetBSD
-    LIBS += -L/usr/local/lib -L/usr/lib
+    LIBS += -L/${PREFIX}/lib -L/usr/lib -L/usr/X11R7/lib -Wl,-R/usr/X11R7/lib -Wl,-R/${PREFIX}/lib
     #Use the defaults for everything else
 
   }else : linux-*{
