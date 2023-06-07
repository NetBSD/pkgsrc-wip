$NetBSD$

Include <strings.h> for strcasecmp(3).

--- tsv2agenda.c.orig	2021-06-25 18:18:33.000000000 +0000
+++ tsv2agenda.c
@@ -5,6 +5,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
+#include <strings.h>
 #include <unistd.h>
 #include <time.h>
 #include "util.h"
