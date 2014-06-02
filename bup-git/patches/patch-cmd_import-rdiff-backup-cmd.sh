$NetBSD: patch-cmd_import-rdiff-backup-cmd.sh,v 1.4 2014/06/02 13:12:32 lexort Exp $

--- cmd/import-rdiff-backup-cmd.sh.orig	2014-06-02 11:49:33.000000000 +0000
+++ cmd/import-rdiff-backup-cmd.sh
@@ -55,7 +55,7 @@ backups_count=$(echo "$backups" | must w
 counter=1
 echo "$backups" |
 while read timestamp type; do
-    tmpdir=$(must mktemp -d) || exit $?
+    tmpdir=$(must mktemp -d import-rdiff-backup-XXXXXXX) || exit $?
 
     echo "Importing backup from $(date -d @$timestamp +%c) " \
         "($counter / $backups_count)" 1>&2
@@ -66,7 +66,7 @@ while read timestamp type; do
     echo 1>&2
 
     echo "Importing into bup..." 1>&2
-    TMPIDX=$(must mktemp -u) || exit $?
+    TMPIDX=$(must mktemp -u import-rdiff-backup-idx-XXXXXXX) || exit $?
     must bup index -ux -f "$tmpidx" "$tmpdir"
     must bup save --strip --date="$timestamp" -f "$tmpidx" -n "$branch" "$tmpdir"
     must rm -f "$tmpidx"
