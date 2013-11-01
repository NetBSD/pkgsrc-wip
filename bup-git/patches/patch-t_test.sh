$NetBSD: patch-t_test.sh,v 1.1 2013/11/01 23:25:09 thomasklausner Exp $

NetBSD's wc -l has whitespace at the start -- strip it out.

--- t/test.sh.orig	2013-11-01 22:54:46.000000000 +0000
+++ t/test.sh
@@ -623,7 +623,7 @@ if [ "$(which rdiff-backup)" != "" ]; th
     bup tick
     rdiff-backup $TOP/Documentation $D/rdiff-backup
     WVPASS bup import-rdiff-backup $D/rdiff-backup import-rdiff-backup
-    WVPASSEQ "$(bup ls import-rdiff-backup/ | wc -l)" "3"
+    WVPASSEQ "$(bup ls import-rdiff-backup/ | wc -l | sed "s/[ 	]*//")" "3"
     WVPASSEQ "$(bup ls import-rdiff-backup/latest/ | sort)" "$(ls $TOP/Documentation | sort)"
 fi
 
