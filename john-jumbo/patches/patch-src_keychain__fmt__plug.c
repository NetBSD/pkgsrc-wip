$NetBSD$

--- src/keychain_fmt_plug.c.orig	2014-12-18 07:59:02.000000000 +0000
+++ src/keychain_fmt_plug.c
@@ -18,6 +18,7 @@ john_register_one(&fmt_keychain);
 #include <string.h>
 #include <assert.h>
 #include <errno.h>
+#include <des.h>
 #include "arch.h"
 #include "misc.h"
 #include "common.h"
