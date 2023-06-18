$NetBSD$

--- src/jk.h.orig	2023-06-16 02:36:07.000000000 +0000
+++ src/jk.h
@@ -8,6 +8,7 @@ extern "C" {
 #include "engine_config.h"
 #include "types.h"
 #include <stdio.h>
+#include <string.h>
 
 #ifdef ARCH_WASM
 #include <string.h>
