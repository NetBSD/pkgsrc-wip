$NetBSD$

# Portability

--- sambam-file.c.orig	2018-11-08 15:20:35 UTC
--- sambam-file.c.orig	2021-03-27 07:38:08.000000000 +0000
+++ sambam-file.c
@@ -30,6 +30,7 @@
 #include <string.h>
 #include <assert.h>
 #include <ctype.h>
+#include <unistd.h>
 #include "subread.h"
 #include "core.h"
 #include "HelperFunctions.h"
