$NetBSD$

--- tools/emojigen/src/emojigen.c.orig	2024-08-07 16:40:05.656695985 +0000
+++ tools/emojigen/src/emojigen.c
@@ -2,7 +2,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <uchar.h>
+#ifndef char32_t
+#define char32_t uint32_t
+#endif
 
 typedef struct Emoji Emoji;
 typedef struct EmojiGroup EmojiGroup;
