$NetBSD$

Fix https://github.com/iains/gcc-12-branch/issues/24
Patch from https://github.com/iains/gcc-12-branch/commit/99533d9

--- gcc/config/aarch64/aarch64-builtins.cc.orig	2025-04-06 08:53:53.699031766 +0000
+++ gcc/config/aarch64/aarch64-builtins.cc
@@ -1474,11 +1474,38 @@ aarch64_init_builtin_rsqrt (void)
 static void
 aarch64_init_fp16_types (void)
 {
-  aarch64_fp16_type_node = make_node (REAL_TYPE);
-  TYPE_PRECISION (aarch64_fp16_type_node) = 16;
-  layout_type (aarch64_fp16_type_node);
+  if (TARGET_MACHO)
+  {
+    /* We want to publish _Float16 so that we can consume the headers from
+     *   newer SDKs.  Do the same as the x86 backend.  TODO: See if we need
+     *     to make __fp16 an alias for this.  */
+    if (!float16_type_node)
+    {
+      aarch64_fp16_type_node = make_node (REAL_TYPE);
+      TYPE_PRECISION (aarch64_fp16_type_node) = 16;
+      SET_TYPE_MODE (aarch64_fp16_type_node, HFmode);
+      layout_type (aarch64_fp16_type_node);
+    }
+    else
+      aarch64_fp16_type_node = float16_type_node;
 
-  (*lang_hooks.types.register_builtin_type) (aarch64_fp16_type_node, "__fp16");
+    if (!maybe_get_identifier ("_Float16"))
+      (*lang_hooks.types.register_builtin_type)
+        (aarch64_fp16_type_node, "_Float16");
+
+    if (!maybe_get_identifier ("__fp16"))
+      (*lang_hooks.types.register_builtin_type)
+        (aarch64_fp16_type_node, "__fp16");
+  }
+  else
+  {
+    aarch64_fp16_type_node = make_node (REAL_TYPE);
+    TYPE_PRECISION (aarch64_fp16_type_node) = 16;
+    layout_type (aarch64_fp16_type_node);
+
+    (*lang_hooks.types.register_builtin_type)
+      (aarch64_fp16_type_node, "__fp16");
+  }
   aarch64_fp16_ptr_type_node = build_pointer_type (aarch64_fp16_type_node);
 }
 
