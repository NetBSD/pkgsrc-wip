$NetBSD$

Do not use /bin/echo, on e.g. SunOS it does not support -n.

--- src/rust-installer/test.sh.orig	2016-03-03 01:04:59.000000000 +0000
+++ src/rust-installer/test.sh
@@ -2,7 +2,7 @@
 
 set -e -u
 
-if [ -x /bin/echo ]; then
+if [ -x /bin/donotuseecho ]; then
     ECHO='/bin/echo'
 else
     ECHO='echo'
