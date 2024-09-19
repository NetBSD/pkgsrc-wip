$NetBSD$

--- src/efs_fmt_plug.c.orig	2014-12-18 07:59:02.000000000 +0000
+++ src/efs_fmt_plug.c
@@ -30,6 +30,7 @@ john_register_one(&fmt_efs);
 #include "memory.h"
 #include "options.h"
 #include "unicode.h"
+#include "des.h"
 #include "sha.h"
 #include "gladman_hmac.h"
 #include "sse-intrinsics.h"
