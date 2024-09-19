$NetBSD$

--- src/mozilla_ng_fmt_plug.c.orig	2014-12-18 07:59:02.000000000 +0000
+++ src/mozilla_ng_fmt_plug.c
@@ -27,6 +27,7 @@ john_register_one(&fmt_mozilla);
 #endif
 
 #include "arch.h"
+#include "des.h"
 #include "md5.h"
 #include "misc.h"
 #include "common.h"
