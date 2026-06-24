$NetBSD$

--- libid/include/engine/random_seed.h.orig	2026-06-24 14:18:37.580748957 +0000
+++ libid/include/engine/random_seed.h
@@ -3,6 +3,9 @@
 #pragma once
 
 #include <cstdint>
+#ifdef RANDOM_MAX
+#undef RANDOM_MAX
+#endif
 
 namespace id::engine
 {
