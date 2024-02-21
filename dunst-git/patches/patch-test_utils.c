$NetBSD$

Only use Linux-only header on Linux.
https://github.com/dunst-project/dunst/pull/1288

--- test/utils.c.orig	2024-02-21 12:52:50.623620603 +0000
+++ test/utils.c
@@ -1,4 +1,6 @@
+#if defined(__linux__)
 #include <features.h>
+#endif
 
 #include "../src/utils.c"
 #include "greatest.h"
