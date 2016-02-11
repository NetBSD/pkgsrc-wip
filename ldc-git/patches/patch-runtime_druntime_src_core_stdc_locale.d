$NetBSD$

--- runtime/druntime/src/core/stdc/locale.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/stdc/locale.d
@@ -126,6 +126,21 @@ else version(FreeBSD)
     ///
     enum LC_MESSAGES       = 6;
 }
+else version( NetBSD )
+{
+    enum
+    {
+        LC_ALL,
+     	LC_COLLATE,
+     	LC_CTYPE,
+     	LC_MONETARY,
+     	LC_NUMERIC,
+     	LC_TIME,
+        LC_MESSAGES,
+      
+     	_LC_LAST,	/* marks end */
+    }
+}
 else version(Solaris)
 {
     enum LC_CTYPE          = 0;
