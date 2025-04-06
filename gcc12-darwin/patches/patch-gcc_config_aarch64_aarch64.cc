$NetBSD$

Fix https://github.com/iains/gcc-12-branch/issues/24
Patch from https://github.com/iains/gcc-12-branch/commit/99533d9

--- gcc/config/aarch64/aarch64.cc.orig	2025-04-06 08:57:15.770348157 +0000
+++ gcc/config/aarch64/aarch64.cc
@@ -21475,6 +21475,8 @@ aarch64_mangle_type (const_tree type)
     {
       if (TYPE_MODE (type) == BFmode)
 	return "u6__bf16";
+      else if (TARGET_MACHO && TYPE_MODE (type) == HFmode)
+        return "DF16_"; /* Match clang, and later GCC.  */
       else
 	return "Dh";
     }
