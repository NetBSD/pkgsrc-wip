$NetBSD$

# Portability

--- sambam-file.c.orig	2024-07-25 00:30:10.000000000 +0000
+++ sambam-file.c
@@ -30,6 +30,7 @@
 #include <string.h>
 #include <assert.h>
 #include <ctype.h>
+#include <unistd.h>
 #include "subread.h"
 #include "core.h"
 #include "HelperFunctions.h"
