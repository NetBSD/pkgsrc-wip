$NetBSD: patch-lib_tt_bin_ttsession_mp__server.C,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- lib/tt/bin/ttsession/mp_server.C.orig	2012-09-28 20:52:38.000000000 +0000
+++ lib/tt/bin/ttsession/mp_server.C
@@ -53,7 +53,7 @@
 
 #include <sys/resource.h>
 #include <unistd.h>
-#if defined(sgi) || defined(__FreeBSD__)
+#if defined(sgi) || defined(CSRG_BASED)
 #include <getopt.h>
 #endif
 
