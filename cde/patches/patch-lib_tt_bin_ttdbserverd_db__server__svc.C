$NetBSD: patch-lib_tt_bin_ttdbserverd_db__server__svc.C,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- lib/tt/bin/ttdbserverd/db_server_svc.C.orig	2012-09-28 20:51:40.000000000 +0000
+++ lib/tt/bin/ttdbserverd/db_server_svc.C
@@ -63,7 +63,7 @@
 #include <termios.h>
 #include <time.h>
 
-#if defined(sgi) || defined(__FreeBSD__)
+#if defined(sgi) || defined(CSRG_BASED)
 #include <getopt.h>
 #endif
 
