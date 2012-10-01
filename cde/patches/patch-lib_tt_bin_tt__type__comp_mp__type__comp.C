$NetBSD: patch-lib_tt_bin_tt__type__comp_mp__type__comp.C,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- lib/tt/bin/tt_type_comp/mp_type_comp.C.orig	2012-09-28 20:50:44.000000000 +0000
+++ lib/tt/bin/tt_type_comp/mp_type_comp.C
@@ -42,7 +42,7 @@
 #if defined(linux)
 #include <unistd.h>
 #endif
-#if defined(sgi) || defined(__FreeBSD__)
+#if defined(sgi) || defined(CSRG_BASED)
 #include <getopt.h>
 #endif
 #if defined(USL) || defined(__uxp__)
