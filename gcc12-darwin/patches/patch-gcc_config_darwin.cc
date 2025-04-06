$NetBSD$

Fix https://github.com/iains/gcc-darwin-arm64/issues/142
Patch from https://github.com/iains/gcc-14-branch/commit/efb88eb

--- gcc/config/darwin.cc.orig	2025-04-04 11:24:26.760580197 +0000
+++ gcc/config/darwin.cc
@@ -3920,6 +3920,15 @@ darwin_override_options (void)
 
   /* The c_dialect...() macros are not available to us here.  */
   darwin_running_cxx = (strstr (lang_hooks.name, "C++") != 0);
+
+  /* We need to consume attributes on function definitions from the the SDK
+   *      headers.  */
+  if (!OPTION_SET_P (flag_allow_ext_attr_placement))
+    flag_allow_ext_attr_placement = true;
+
+  /* We need to consume some C keywords in C++.  */
+  if (!OPTION_SET_P (flag_allow_extra_keywords))
+    flag_allow_extra_keywords = true;
 }
 
 #if DARWIN_PPC
