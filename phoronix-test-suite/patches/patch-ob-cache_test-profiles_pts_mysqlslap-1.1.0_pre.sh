$NetBSD$

* When you run "test foo == foo" on a platform that does not support the
  "==" operator, the result will be "false" instead of "true". This can
  lead to unexpected behavior. Hence, this patch replaces the "==" operator 
  with "=".

$NetBSD$

--- ob-cache/test-profiles/pts/mysqlslap-1.1.0/pre.sh.orig	2020-05-25 13:26:05.000000000 +0000
+++ ob-cache/test-profiles/pts/mysqlslap-1.1.0/pre.sh
@@ -2,7 +2,7 @@
 
 # START SERVER
 cd $HOME/mysql_
-if [ "$(whoami)" == "root" ] ; then
+if [ "$(whoami)" = "root" ] ; then
     $HOME/mysql_/bin/mysqld_safe --user=root --no-defaults --datadir=$HOME/mysql_/.data &
 else
     $HOME/mysql_/bin/mysqld_safe --no-defaults --datadir=$HOME/mysql_/.data &
