$NetBSD: patch-src_llfuse_capi.c,v 1.2 2015/08/22 16:20:34 thomasklausner Exp $

Add NetBSD support by handling it the same as FreeBSD.
https://bitbucket.org/nikratio/python-llfuse/issues/48/netbsd-support-for-llfuse-041

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
