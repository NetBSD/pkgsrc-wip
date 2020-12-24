$NetBSD$

Fix equality test.

--- utils/build/naev.sh.orig	2020-12-17 02:23:41.000000000 +0000
+++ utils/build/naev.sh
@@ -1,7 +1,7 @@
 #!/bin/sh
 cd @source_root@
 type "gdb" > /dev/null
-if [ "$?" == 0 ]; then
+if [ "$?" = 0 ]; then
    gdb -x @source_root@/.gdbinit @naev_bin@ "$@"
 else
    @naev_bin@ "$@"
