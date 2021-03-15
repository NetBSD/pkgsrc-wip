$NetBSD$

--- src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/IR/CMakeFiles/intrinsics_gen.dir/cmake_clean.cmake.orig	2020-07-23 08:46:21.593341283 +0000
+++ src/3rdparty/chromium/third_party/swiftshader/third_party/llvm-subzero/build/NetBSD/include/llvm/IR/CMakeFiles/intrinsics_gen.dir/cmake_clean.cmake
@@ -0,0 +1,14 @@
+file(REMOVE_RECURSE
+  "Attributes.inc"
+  "Attributes.inc.tmp"
+  "CMakeFiles/intrinsics_gen"
+  "IntrinsicEnums.inc"
+  "IntrinsicEnums.inc.tmp"
+  "IntrinsicImpl.inc"
+  "IntrinsicImpl.inc.tmp"
+)
+
+# Per-language clean rules from dependency scanning.
+foreach(lang )
+  include(CMakeFiles/intrinsics_gen.dir/cmake_clean_${lang}.cmake OPTIONAL)
+endforeach()
