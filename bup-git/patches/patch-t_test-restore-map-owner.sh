$NetBSD: patch-t_test-restore-map-owner.sh,v 1.1 2013/11/11 10:10:47 thomasklausner Exp $

From upstream.

--- t/test-restore-map-owner.sh.orig	2013-11-11 08:52:33.000000000 +0000
+++ t/test-restore-map-owner.sh
@@ -31,6 +31,8 @@ WVPASS cd "$tmpdir"
 WVSTART "restore --map-user/group/uid/gid (control)"
 WVPASS mkdir src
 WVPASS touch src/foo
+# Some systems assign the parent dir group to new paths.
+WVPASS chgrp -R "$group" src
 WVPASS bup index src
 WVPASS bup save -n src src
 WVPASS bup restore -C dest "src/latest/$(pwd)/src/"
