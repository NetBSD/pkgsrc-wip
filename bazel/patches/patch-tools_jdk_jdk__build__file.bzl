$NetBSD$

--- tools/jdk/jdk_build_file.bzl.orig	2023-11-28 16:34:15.542839919 +0000
+++ tools/jdk/jdk_build_file.bzl
@@ -49,6 +49,12 @@ filegroup(
 )
 
 filegroup(
+    name = "jni_md_header-netbsd",
+    srcs = ["include/netbsd/jni_md.h"],
+    deprecation = DEPRECATION_MESSAGE,
+)
+
+filegroup(
     name = "jni_md_header-openbsd",
     srcs = ["include/openbsd/jni_md.h"],
     deprecation = DEPRECATION_MESSAGE,
