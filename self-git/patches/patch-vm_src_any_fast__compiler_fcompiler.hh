$NetBSD$

--- vm/src/any/fast_compiler/fcompiler.hh.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/any/fast_compiler/fcompiler.hh
@@ -10,6 +10,7 @@
 # endif
 
 
+
 // The FCompiler structure holds global state associated with the current
 // NIC compilation. (NIC stands for "non-inlining compiler"; for historical
 // reasons, the NIC's classes & files start with f for "fast".)
@@ -65,5 +66,4 @@ class FCompiler:  public AbstractCompile
 
 };
 
-
 # endif // FAST_COMPILER
