$NetBSD$

--- build-aux/find-x-server.sh.orig	2020-12-15 18:16:43.000000000 +0000
+++ build-aux/find-x-server.sh
@@ -21,6 +21,8 @@ elif test ! -h /usr/X11 -a -x /usr/X11/b
     echo "/usr/X11/bin/X"
 elif test -x /usr/X11R6/bin/X; then
     echo "/usr/X11R6/bin/X"
+elif test -x /usr/X11R7/bin/X; then
+    echo "/usr/X11R7/bin/X"
 elif test -x /usr/bin/Xorg; then
     echo "/usr/bin/Xorg"
 elif test -x /usr/X11/bin/X; then
