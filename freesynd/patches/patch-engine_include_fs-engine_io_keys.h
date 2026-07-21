$NetBSD$

Use utf8cpp from pkgsrc

--- engine/include/fs-engine/io/keys.h.orig	2026-07-20 05:30:01.930932540 +0000
+++ engine/include/fs-engine/io/keys.h
@@ -24,7 +24,7 @@
 #ifndef KEYS_H
 #define KEYS_H
 
-#include "utf8.h"
+#include <utf8cpp/utf8.h>
 
 #include "fs-utils/common.h"
 
