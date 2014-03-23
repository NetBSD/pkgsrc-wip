$NetBSD: patch-t_test-ls.sh,v 1.2 2014/03/23 13:54:43 thomasklausner Exp $

Symlink size varies in some cases, ignore it.
From upstream.

--- t/test-ls.sh.orig	2014-03-23 13:40:22.000000000 +0000
+++ t/test-ls.sh
@@ -123,14 +123,22 @@ d--------- ?/? 0 1970-01-01 00:00 src/"
 
 symlink_mode="$(WVPASS ls -l src/symlink | cut -b -10)" || exit $?
 
-symlink_size="$(WVPASS python -c "import os
-print os.lstat('src/symlink').st_size")" || exit $?
-
-symlink_date="$(WVPASS bup ls -l src/latest"$tmpdir"/src | grep symlink)" || exit $?
-symlink_date="$(WVPASS echo "$symlink_date" \
+symlink_bup_info="$(WVPASS bup ls -l src/latest"$tmpdir"/src | grep symlink)" \
+    || exit $?
+symlink_date="$(WVPASS echo "$symlink_bup_info" \
   | WVPASS perl -ne 'm/.*? (\d+) (\d\d\d\d-\d\d-\d\d \d\d:\d\d)/ and print $2')" \
     || exit $?
 
+if test "$(uname -s)" != NetBSD; then
+    symlink_size="$(WVPASS python -c "import os
+print os.lstat('src/symlink').st_size")" || exit $?
+else
+    # NetBSD appears to return varying sizes, so for now, just ignore it.
+    symlink_size="$(WVPASS echo "$symlink_bup_info" \
+      | WVPASS perl -ne 'm/.*? (\d+) (\d\d\d\d-\d\d-\d\d \d\d:\d\d)/ and print $1')" \
+        || exit $?
+fi
+
 uid="$(id -u)" || exit $?
 gid="$(python -c 'import os; print os.stat("src").st_gid')" || exit $?
 user="$(id -un)" || exit $?
