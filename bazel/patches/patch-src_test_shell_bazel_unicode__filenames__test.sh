$NetBSD$

--- src/test/shell/bazel/unicode_filenames_test.sh.orig	2023-11-28 16:49:24.316954368 +0000
+++ src/test/shell/bazel/unicode_filenames_test.sh
@@ -142,7 +142,7 @@ function test_traditional_encoding_sourc
   # the traditional BSDs typically don't, so their paths can contain arbitrary
   # non-NUL bytes.
   case "$(uname -s | tr [:upper:] [:lower:])" in
-  linux|freebsd)
+  linux|freebsd|netbsd)
     ;;
   *)
     echo "Skipping test." && return
