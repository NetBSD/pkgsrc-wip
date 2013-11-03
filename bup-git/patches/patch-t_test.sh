$NetBSD: patch-t_test.sh,v 1.2 2013/11/03 01:33:07 thomasklausner Exp $

NetBSD's wc -l has whitespace at the start -- strip it out.

--- t/test.sh.orig	2013-11-03 01:29:44.000000000 +0000
+++ t/test.sh
@@ -617,7 +617,7 @@ if [ "$(which rdiff-backup)" != "" ]; th
     WVPASS bup tick
     WVPASS rdiff-backup $TOP/Documentation $D/rdiff-backup
     WVPASS bup import-rdiff-backup $D/rdiff-backup import-rdiff-backup
-    WVPASSEQ "$(bup ls import-rdiff-backup/ | wc -l)" "3"
+    WVPASSEQ "$(bup ls import-rdiff-backup/ | wc -l | sed "s/[ 	]*//")" "3"
     WVPASSEQ "$(bup ls import-rdiff-backup/latest/ | sort)" "$(ls $TOP/Documentation | sort)"
 fi
 
