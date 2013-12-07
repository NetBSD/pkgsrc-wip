$NetBSD: patch-t_test-meta.sh,v 1.4 2013/12/07 01:08:28 thomasklausner Exp $

Possible workaround patch for test failure from upstream.

--- t/test-meta.sh.orig	2013-12-06 00:00:37.000000000 +0000
+++ t/test-meta.sh
@@ -418,11 +418,20 @@ src/foo/3"
         exit 0
     fi
 
+    first_group="$(WVPASS python -c 'import os,grp; \
+      print grp.getgrgid(os.getgroups()[0])[0]')" || exit $?
+    last_group="$(python -c 'import os,grp; \
+      print grp.getgrgid(os.getgroups()[-1])[0]')" || exit $?
+
     WVSTART 'metadata (restoration of ownership)'
     WVPASS force-delete "$TOP/bupmeta.tmp"
     WVPASS mkdir "$TOP/bupmeta.tmp"
     WVPASS cd "$TOP/bupmeta.tmp"
     WVPASS touch src
+    # Some systems always assign the parent dir group to new paths
+    # (sgid).  Make sure the group is one we're in.
+    WVPASS chgrp -R "$first_group" src
+
     WVPASS bup meta -cf src.meta src
 
     WVPASS mkdir dest
@@ -436,8 +445,6 @@ src/foo/3"
     WVPASS bup xstat src | WVPASS grep -qvE '^user: root'
 
     # Make sure we can restore one of the user's groups.
-    last_group="$(python -c 'import os,grp; \
-      print grp.getgrgid(os.getgroups()[0])[0]')"
     WVPASS rm -rf src
     WVPASS bup meta --edit --set-group "$last_group" ../src.meta \
         | WVPASS bup meta -x
