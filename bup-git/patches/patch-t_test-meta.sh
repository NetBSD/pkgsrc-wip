$NetBSD: patch-t_test-meta.sh,v 1.2 2013/11/03 01:33:07 thomasklausner Exp $

Use more portable test(1) = comparison operator.

--- t/test-meta.sh.orig	2013-11-03 01:29:44.000000000 +0000
+++ t/test-meta.sh
@@ -478,7 +478,7 @@ src/foo/3"
 
 # Test ownership restoration (when root or fakeroot).
 (
-    if [ $(t/root-status) == none ]; then
+    if [ $(t/root-status) = none ]; then
         exit 0
     fi
 
@@ -589,7 +589,7 @@ src/foo/3"
 
 # Root-only tests that require an FS with all the trimmings: ACLs,
 # Linux attr, Linux xattr, etc.
-if [ $(t/root-status) == root ]; then
+if [ $(t/root-status) = root ]; then
     (
         # Some cleanup handled in universal-cleanup() above.
         # These tests are only likely to work under Linux for now
