$NetBSD: patch-cmd_import-rdiff-backup-cmd.sh,v 1.1 2013/11/01 23:25:09 thomasklausner Exp $

Use -d instead of --date for date(1), since it's more portable.

--- cmd/import-rdiff-backup-cmd.sh.orig	2013-11-01 22:50:37.000000000 +0000
+++ cmd/import-rdiff-backup-cmd.sh
@@ -45,7 +45,7 @@ echo "$backups" |
 while read timestamp type; do
     tmpdir=$(mktemp -d)
 
-    echo "Importing backup from $(date --date=@$timestamp +%c) " \
+    echo "Importing backup from $(date -d @$timestamp +%c) " \
         "($counter / $backups_count)" 1>&2
     echo 1>&2
 
