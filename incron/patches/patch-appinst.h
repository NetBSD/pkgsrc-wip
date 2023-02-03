$NetBSD$

Do not hardcode system paths. This is pkgsrc-specific.

--- appinst.h.orig	2023-02-03 01:52:35.609771302 +0000
+++ appinst.h
@@ -25,7 +25,7 @@
 #include <string>
 
 
-#define APPLOCK_BASEDIR "/var/run"
+#define APPLOCK_BASEDIR "@VARBASE@/run"
 
 
 /// Exception class.
