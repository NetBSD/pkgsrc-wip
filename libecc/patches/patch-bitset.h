$NetBSD: patch-bitset.h,v 1.1.1.1 2011/10/28 17:37:04 jihbed Exp $

--- include/libecc/bitset.h.orig	2011-08-08 00:32:31.000000000 +0100
+++ include/libecc/bitset.h	2011-08-08 00:32:54.000000000 +0100
@@ -39,7 +39,7 @@
 #include <string>
 #include <inttypes.h>
 #include <cassert>
-#include <endian.h>
+#include <sys/endian.h>
 #ifdef CWDEBUG
 #include "debug.h"
 #include <libcwd/cwprint.h>
