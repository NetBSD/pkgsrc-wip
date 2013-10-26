$NetBSD: patch-t_test-meta.sh,v 1.1 2013/10/26 23:21:09 thomasklausner Exp $

Use more portable test(1) = comparison operator.

--- t/test-meta.sh.orig	2013-10-26 13:16:20.000000000 +0000
+++ t/test-meta.sh
@@ -465,7 +465,7 @@ WVSTART 'meta --edit'
 
 # Test ownership restoration (when root or fakeroot).
 (
-    if [ $(t/root-status) == none ]; then
+    if [ $(t/root-status) = none ]; then
         exit 0
     fi
 
@@ -575,7 +575,7 @@ WVSTART 'meta --edit'
 
 # Root-only tests that require an FS with all the trimmings: ACLs,
 # Linux attr, Linux xattr, etc.
-if [ $(t/root-status) == root ]; then
+if [ $(t/root-status) = root ]; then
     (
         set -e
         # Some cleanup handled in universal-cleanup() above.
