$NetBSD$

* Remove the `-e' option of echo as it is not portable

--- pts-core/static/root-access.sh.orig	2020-07-09 17:06:29.000000000 +0000
+++ pts-core/static/root-access.sh
@@ -14,9 +14,14 @@ fi
 
 TMPRUN=`mktemp`
 
-/bin/echo -e "#!/bin/sh\n\n$@" > $TMPRUN
+/bin/echo "#!/bin/sh" > $TMPRUN
+/bin/echo >> $TMPRUN
+/bin/echo >> $TMPRUN
+/bin/echo "$@" >> $TMPRUN
 chmod +x $TMPRUN
 
-/bin/echo -e "\nThis test requires root access to run.\n" 1>&2
+/bin/echo 1>&2
+/bin/echo "This test requires root access to run." 1>&2
+/bin/echo 1>&2
 $ROOT $TMPRUN
 rm -f $TMPRUN
