$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/stdc/locale.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/stdc/locale.d
@@ -126,6 +126,23 @@ else version(FreeBSD)
     ///
     enum LC_MESSAGES       = 6;
 }
+else version(NetBSD)
+{
+    ///
+    enum LC_ALL            = 0;
+    ///
+    enum LC_COLLATE        = 1;
+    ///
+    enum LC_CTYPE          = 2;
+    ///
+    enum LC_MONETARY       = 3;
+    ///
+    enum LC_NUMERIC        = 4;
+    ///
+    enum LC_TIME           = 5;
+    ///
+    enum LC_MESSAGES       = 6;
+}
 else version(Solaris)
 {
     enum LC_CTYPE          = 0;
