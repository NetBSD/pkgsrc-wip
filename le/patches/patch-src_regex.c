$NetBSD$

Remove implicit function declaration warning

--- src/regex.c.orig	2013-03-18 13:44:31.000000000 +0000
+++ src/regex.c
@@ -46,6 +46,9 @@
 # include <sys/types.h>
 #endif
 
+/* for write(2) */
+#include <unistd.h>
+
 /* Whether to use ISO C Amendment 1 wide char functions.
    Those should not be used for Emacs since it uses its own.  */
 #if defined _LIBC
