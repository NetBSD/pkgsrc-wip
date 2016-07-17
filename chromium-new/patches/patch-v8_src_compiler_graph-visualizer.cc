$NetBSD$

--- v8/src/compiler/graph-visualizer.cc.orig	2016-06-24 01:04:22.000000000 +0000
+++ v8/src/compiler/graph-visualizer.cc
@@ -5,6 +5,7 @@
 #include "src/compiler/graph-visualizer.h"
 
 #include <sstream>
+#include <cstdio>
 #include <string>
 
 #include "src/code-stubs.h"
@@ -26,7 +27,7 @@ namespace internal {
 namespace compiler {
 
 
-FILE* OpenVisualizerLogFile(CompilationInfo* info, const char* phase,
+std::FILE* OpenVisualizerLogFile(CompilationInfo* info, const char* phase,
                             const char* suffix, const char* mode) {
   EmbeddedVector<char, 256> filename(0);
   base::SmartArrayPointer<char> debug_name = info->GetDebugName();
