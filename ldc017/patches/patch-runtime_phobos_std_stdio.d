$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/stdio.d.orig	2016-02-13 20:04:46.000000000 +0000
+++ runtime/phobos/std/stdio.d
@@ -68,6 +68,12 @@ version (FreeBSD)
     version = HAS_GETDELIM;
 }
 
+version (NetBSD)
+{
+    version = GENERIC_IO;
+    version = HAS_GETDELIM;
+}
+
 version (Solaris)
 {
     version = GENERIC_IO;
