$NetBSD$

--- third_party/xnnpack.buck.bzl.orig	2022-07-22 04:45:56.384678786 +0000
+++ third_party/xnnpack.buck.bzl
@@ -822,7 +822,7 @@ def define_xnnpack(third_party, labels =
         labels = labels,
         platform_compiler_flags = [
             (
-                "^(i[3-6]86|x86|x86_64|AMD64)$",
+                "^(i[3-6]86|x86|x86_64|amd64)$",
                 [
                     "-mfma",
                     "-mf16c",
@@ -873,7 +873,7 @@ def define_xnnpack(third_party, labels =
         labels = labels,
         platform_compiler_flags = [
             (
-                "^(i[3-6]86|x86|x86_64|AMD64)$",
+                "^(i[3-6]86|x86|x86_64|amd64)$",
                 [
                     "-mfma",
                     "-mf16c",
@@ -1108,7 +1108,7 @@ def define_xnnpack(third_party, labels =
         labels = labels,
         platform_compiler_flags = [
             (
-                "^(i[3-6]86|x86|x86_64|AMD64)$",
+                "^(i[3-6]86|x86|x86_64|amd64)$",
                 [
                     "-mavx512f",
                     "-mavx512cd",
@@ -1171,7 +1171,7 @@ def define_xnnpack(third_party, labels =
         labels = labels,
         platform_compiler_flags = [
             (
-                "^(i[3-6]86|x86|x86_64|AMD64)$",
+                "^(i[3-6]86|x86|x86_64|amd64)$",
                 [
                     "-mavx512f",
                     "-mavx512cd",
