$NetBSD$

dont try to run git, specifying date with MAKE_ENV instead.

--- irssi-version.sh.orig	2016-02-08 20:18:04.000000000 +0000
+++ irssi-version.sh
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-DATE=`GIT_DIR=$1/.git git log -1 --pretty=format:%ai HEAD`
+#DATE=`GIT_DIR=$1/.git git log -1 --pretty=format:%ai HEAD`
 
 VERSION_DATE=`echo $DATE | cut -f 1 -d ' ' | tr -d -`
 VERSION_TIME=`echo $DATE | cut -f 2 -d ' ' | awk -F: '{printf "%d", $1$2}'`
