$NetBSD$

--- src/hir_conv/constant_evaluation.cpp.orig	2022-08-14 04:09:16.000000000 +0000
+++ src/hir_conv/constant_evaluation.cpp
@@ -21,6 +21,12 @@
 #include <trans/monomorphise.hpp>   // For handling monomorph of MIR in provided associated constants
 #include <trans/codegen.hpp>    // For encoding as part of transmute
 
+#if defined(__NetBSD__)
+#    undef bswap16
+#    undef bswap32
+#    undef bswap64
+#endif
+
 namespace {
     struct Defer {};
 
