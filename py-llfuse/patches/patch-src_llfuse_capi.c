$NetBSD: patch-src_llfuse_capi.c,v 1.1 2015/08/22 13:50:45 thomasklausner Exp $

Fake NetBSD support by handling it the same as FreeBSD.

--- src/llfuse/capi.c.orig	2015-08-20 22:51:49.000000000 +0000
+++ src/llfuse/capi.c
@@ -11,6 +11,8 @@ the terms of the GNU LGPL.
 #include "capi_linux.c"
 #elif __FreeBSD__
 #include "capi_freebsd.c"
+#elif __NetBSD__
+#include "capi_freebsd.c"
 #elif __APPLE__ && __MACH__
 #include "capi_darwin.c"
 #else
