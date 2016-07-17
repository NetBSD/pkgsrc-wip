$NetBSD$

--- v8/src/compiler/graph-visualizer.h.orig	2016-06-24 01:04:22.000000000 +0000
+++ v8/src/compiler/graph-visualizer.h
@@ -5,7 +5,7 @@
 #ifndef V8_COMPILER_GRAPH_VISUALIZER_H_
 #define V8_COMPILER_GRAPH_VISUALIZER_H_
 
-#include <stdio.h>
+#include <cstdio>
 #include <iosfwd>
 
 namespace v8 {
@@ -21,7 +21,7 @@ class RegisterAllocationData;
 class Schedule;
 class SourcePositionTable;
 
-FILE* OpenVisualizerLogFile(CompilationInfo* info, const char* phase,
+std::FILE* OpenVisualizerLogFile(CompilationInfo* info, const char* phase,
                             const char* suffix, const char* mode);
 
 struct AsJSON {
