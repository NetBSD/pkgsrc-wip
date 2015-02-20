$NetBSD: patch-libpkg_pkg__elf.c,v 1.1 2015/02/20 13:30:17 khorben Exp $

NetBSD defines roundup2() in <sys/param.h> already; use it.

--- libpkg/pkg_elf.c.orig	2015-02-20 00:10:44.000000000 +0000
+++ libpkg/pkg_elf.c
@@ -74,7 +74,9 @@
 /* FFR: when we support installing a 32bit package on a 64bit host */
 #define _PATH_ELF32_HINTS       "/var/run/ld-elf32.so.hints"
 
+#ifndef roundup2
 #define roundup2(x, y)	(((x)+((y)-1))&(~((y)-1))) /* if y is powers of two */
+#endif
 
 static const char * elf_corres_to_string(const struct _elf_corres* m, int e);
 static int elf_string_to_corres(const struct _elf_corres* m, const char *s);
