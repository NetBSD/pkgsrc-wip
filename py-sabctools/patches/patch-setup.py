$NetBSD$

On NetBSD there is no need to link with -ldl for dlopen(3).

--- setup.py.orig	2023-05-01 19:17:49.000000000 +0000
+++ setup.py
@@ -95,6 +95,7 @@ class SABCToolsBuild(build_ext):
         else:
             # TODO: consider -flto - may require some extra testing
             ldflags = ["-ldl"]  # for dlopen
+            ldflags = []  # for dlopen, not needed on NetBSD
             cflags = [
                 "-Wall",
                 "-Wextra",
