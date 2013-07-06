$NetBSD: patch-src_run.bash,v 1.1 2013/07/06 11:59:41 bsiegert Exp $

See https://codereview.appspot.com/10078047

--- src/run.bash.orig	2013-06-13 03:08:11.000000000 +0000
+++ src/run.bash
@@ -20,6 +20,11 @@ ulimit -c 0
 [ "$(ulimit -H -n)" == "unlimited" ] || ulimit -S -n $(ulimit -H -n)
 [ "$(ulimit -H -d)" == "unlimited" ] || ulimit -S -d $(ulimit -H -d)
 
+# Thread count limit on NetBSD 7.
+if ulimit -T &> /dev/null; then
+	[ "$(ulimit -H -T)" == "unlimited" ] || ulimit -S -T $(ulimit -H -T)
+fi
+
 # allow all.bash to avoid double-build of everything
 rebuild=true
 if [ "$1" = "--no-rebuild" ]; then
