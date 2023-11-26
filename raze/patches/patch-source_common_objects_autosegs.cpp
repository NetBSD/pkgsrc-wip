$NetBSD$

Include cassert for assert() (exposed by turning pre-compiled headers off).

--- source/common/objects/autosegs.cpp.orig	2023-11-12 13:35:34.000000000 +0000
+++ source/common/objects/autosegs.cpp
@@ -42,6 +42,7 @@
 ** compile with something other than Visual C++ or GCC.
 */
 
+#include <cassert>
 #include "autosegs.h"
 
 #ifdef _WIN32
