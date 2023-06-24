$NetBSD$

Adapt example for pkgsrc paths.

--- convert.sh.orig	2011-02-15 18:57:40.000000000 +0000
+++ convert.sh
@@ -4,6 +4,7 @@
 
 set -e
 
+PATH=@PREFIX@/libexec/cvs2fossil:$PATH
 db=/home/joerg/repo/src-new
 repo=/home/joerg/repo/netbsd/src
 fossil=$db.fossil
@@ -12,7 +13,7 @@ fossil=$db.fossil
 # If you want the module name itself to be skipped, add -m.
 # Instead of e.g. src/bin/... as path, this will create only bin/...
 #
-time 01-import/01-import $db $repo
+time 01-import $db $repo
 oldest=$(echo 'SELECT datetime(r.date,"-1 second") FROM revision r ORDER BY r.date LIMIT 1;' | sqlite3 $db)
 
 #
@@ -35,14 +36,14 @@ oldest=$(echo 'SELECT datetime(r.date,"-
 #  revision IN (SELECT revision.id FROM revision WHERE date > "1998-05-01");
 #EOF
 
-time 02-vendorbranches/02-vendorbranches $db
-time 03-branchtime/03-branchtime $db
+time 02-vendorbranches $db
+time 03-branchtime $db
 rm -f $fossil
 fossil new -A root --date-override "$oldest" $fossil
 project=eeb7e06236b08dc4b57b6ab3b957fe5756c64f5b
 sqlite3 $fossil 'UPDATE config SET value="'$project'" WHERE name="project-code"'
 initial=$(sqlite3 $fossil 'SELECT uuid FROM blob WHERE rid=1')
-TMPDIR=. time 04-commit/04-commit -b $initial $db $fossil
+TMPDIR=. time 04-commit -b $initial $db $fossil
 du -h $fossil
 time fossil rebuild --noverify $fossil
 #TMPDIR=. time sqlite3 $fossil 'pragma synchronous=off; pragma journal_mode=off; vacuum'
