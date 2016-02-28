$NetBSD$

--- OS-detect.pri.orig	2016-02-10 20:41:00.000000000 +0000
+++ OS-detect.pri
@@ -46,9 +46,9 @@
     
   }else : netbsd-*{
     OS = NetBSD
-    LIBS += -L/usr/local/lib -L/usr/lib
-    PREFIX=/usr/local
-    LIBPREFIX=/usr/local/lib
+    LIBS += -L/usr/pkg/lib -L/usr/lib -L/usr/X11R7/lib/ -Wl,-R/usr/X11R7/lib/ -Wl,-R/usr/pkg/lib
+    PREFIX=/usr/pkg
+    LIBPREFIX=/usr/pkg/lib
     #Use the defaults for everything else
     
   }else : linux-*{
