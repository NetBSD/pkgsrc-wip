$NetBSD$

--- gcc/d/d-builtins.cc.orig	2019-01-20 18:53:13.000000000 +0000
+++ gcc/d/d-builtins.cc
@@ -382,6 +382,8 @@ d_add_builtin_version (const char* ident
     global.params.isWindows = true;
   else if (strcmp (ident, "FreeBSD") == 0)
     global.params.isFreeBSD = true;
+  else if (strcmp (ident, "NetBSD") == 0)
+    global.params.isNetBSD = true;
   else if (strcmp (ident, "OpenBSD") == 0)
     global.params.isOpenBSD = true;
   else if (strcmp (ident, "Solaris") == 0)
