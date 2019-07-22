$NetBSD$

--- vm/src/any/fast_compiler/fcompiler.hh.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/any/fast_compiler/fcompiler.hh
@@ -9,13 +9,13 @@
   # pragma interface
 # endif
 
+#include "aCompiler.hh"
+
 
 // The FCompiler structure holds global state associated with the current
 // NIC compilation. (NIC stands for "non-inlining compiler"; for historical
 // reasons, the NIC's classes & files start with f for "fast".)
 
-extern FCompiler* theCompiler;
-
 class FCompiler:  public AbstractCompiler {
  public:
   int32 countID;
@@ -65,5 +65,6 @@ class FCompiler:  public AbstractCompile
 
 };
 
+extern FCompiler* theCompiler;
 
 # endif // FAST_COMPILER
