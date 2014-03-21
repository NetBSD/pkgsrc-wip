$NetBSD: patch-t_test-ls.sh,v 1.1 2014/03/21 21:03:44 thomasklausner Exp $

Fix group test, from upstream.

--- t/test-ls.sh.orig	2014-03-21 01:16:29.000000000 +0000
+++ t/test-ls.sh
@@ -132,9 +132,10 @@ symlink_date="$(WVPASS echo "$symlink_da
     || exit $?
 
 uid="$(id -u)" || exit $?
-gid="$(id -g)" || exit $?
+gid="$(python -c 'import os; print os.stat("src").st_gid')" || exit $?
 user="$(id -un)" || exit $?
-group="$(id -gn)" || exit $?
+group="$(python -c 'import grp, os, stat                                                                                                                                                                         
+print grp.getgrgid(os.stat("src").st_gid)[0]')"
 
 WVPASSEQ "$(bup ls -l src/latest"$tmpdir"/src | tr -s ' ' ' ')" \
 "-rwx------ $user/$group 0 1969-07-20 20:18 executable
