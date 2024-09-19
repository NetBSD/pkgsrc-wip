$NetBSD$

Avoid implicit declarations:
ctype.h for isdigit
unistd.h for access
stdlib.h for exit

--- main.c.orig	2011-03-30 16:40:53.000000000 +0000
+++ main.c
@@ -44,6 +44,9 @@
 #include "debug.h"	/* Debugging */
 #include "platform.h"	/* Platform-specific includes and definitions */
 #include "kermit.h"	/* Kermit symbols and data structures */
+#include <ctype.h>
+#include <unistd.h>
+#include <stdlib.h>
 #ifdef __linux
 #include <errno.h>
 #endif /* __linux */
