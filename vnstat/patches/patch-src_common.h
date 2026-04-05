$NetBSD$

Include <fcntl.h> for open(2).

--- src/common.h.orig	2025-01-08 21:19:22.000000000 +0000
+++ src/common.h	2026-04-05 21:31:12.885893036 +0000
@@ -6,6 +6,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <unistd.h>
+#include <fcntl.h>
 #include <locale.h>
 #include <time.h>
 #include <string.h>
