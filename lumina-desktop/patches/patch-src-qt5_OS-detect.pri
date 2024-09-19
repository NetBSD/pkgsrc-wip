$NetBSD$

Fix Missing options symbols

--- src-qt5/OS-detect.pri.orig	2021-12-26 02:33:45.000000000 +0000
+++ src-qt5/OS-detect.pri
@@ -54,7 +54,7 @@ isEmpty(OS){
   }else : netbsd-*{
     isEmpty(PREFIX){ PREFIX=/usr/local }
     OS = NetBSD
-    LIBS += -L/usr/local/lib -L/usr/lib
+    LIBS += -L/${PREFIX}/lib -L/usr/lib -L/usr/X11R7/lib -Wl,-R/usr/X11R7/lib -Wl,-R/${PREFIX}/lib 
     #Use the defaults for everything else
 
   }else : linux-*{
