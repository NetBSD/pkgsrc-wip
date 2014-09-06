$NetBSD: patch-include_common_SC__Endian.h,v 1.1 2014/09/06 22:22:36 thomasklausner Exp $

Add NetBSD support.

--- include/common/SC_Endian.h.orig	2013-11-27 12:54:02.000000000 +0000
+++ include/common/SC_Endian.h
@@ -35,7 +35,7 @@
 
 # include <machine/endian.h>
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 
 # include <machine/endian.h>
 # include <netinet/in.h>
