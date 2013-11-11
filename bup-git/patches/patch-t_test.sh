$NetBSD: patch-t_test.sh,v 1.4 2013/11/11 20:14:16 thomasklausner Exp $

From upstream.

--- t/test.sh.orig	2013-11-11 08:52:33.000000000 +0000
+++ t/test.sh
@@ -635,7 +635,7 @@ if [ "$(type -p rdiff-backup)" != "" ]; 
     WVPASS rdiff-backup $TOP/Documentation $D/rdiff-backup
     WVPASS bup import-rdiff-backup $D/rdiff-backup import-rdiff-backup
     WVPASSEQ $(bup ls import-rdiff-backup/ | wc -l) 3
-    WVPASSEQ "$(bup ls import-rdiff-backup/latest/ | sort)" "$(ls $TOP/Documentation | sort)"
+    WVPASSEQ "$(bup ls -a import-rdiff-backup/latest/ | sort)" "$(ls -A $TOP/Documentation | sort)"
 fi
 
 
