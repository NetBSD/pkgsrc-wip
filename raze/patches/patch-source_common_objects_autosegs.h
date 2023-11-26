$NetBSD$

Include cstdint fot intptr_t (exposed by turning pre-compiled headers off).

--- source/common/objects/autosegs.h.orig	2023-11-12 13:35:34.000000000 +0000
+++ source/common/objects/autosegs.h
@@ -35,6 +35,7 @@
 #ifndef AUTOSEGS_H
 #define AUTOSEGS_H
 
+#include <cstdint>
 #include <type_traits>
 
 #if defined(__clang__)
