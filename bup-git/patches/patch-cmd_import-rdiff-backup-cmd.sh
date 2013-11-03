$NetBSD: patch-cmd_import-rdiff-backup-cmd.sh,v 1.2 2013/11/03 01:33:07 thomasklausner Exp $

Use -d instead of --date for date(1), since it's more portable.

--- cmd/import-rdiff-backup-cmd.sh.orig	2013-11-03 01:29:44.000000000 +0000
+++ cmd/import-rdiff-backup-cmd.sh
@@ -55,7 +55,7 @@ echo "$backups" |
 while read timestamp type; do
     tmpdir=$(must mktemp -d) || exit $?
 
-    echo "Importing backup from $(date --date=@$timestamp +%c) " \
+    echo "Importing backup from $(date -d @$timestamp +%c) " \
         "($counter / $backups_count)" 1>&2
     echo 1>&2
 
