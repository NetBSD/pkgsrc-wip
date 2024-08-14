$NetBSD$

https://github.com/Zirias/xmoji/pull/6

--- src/bin/xmoji/unistrbuilder.h.orig	2024-08-07 16:44:35.604855277 +0000
+++ src/bin/xmoji/unistrbuilder.h
@@ -2,7 +2,11 @@
 #define XMOJI_UNISTRBUILDER_H
 
 #include <poser/decl.h>
-#include <uchar.h>
+#include <stddef.h>
+#include <stdint.h>
+#ifndef char32_t
+#define char32_t uint32_t
+#endif
 
 C_CLASS_DECL(UniStr);
 C_CLASS_DECL(UniStrBuilder);
