$NetBSD: patch-config.sh,v 1.1 2013/05/19 19:52:00 airhead Exp $

Remove overly "smart" detection script for ncurses.  This doesn't work on NetBSD.
If libstfl is linked against the system-wide curses, you can't later link against
ncurses.  Newsbeuter can use the ncursesw compat offered by NetBSD 6.x native curses.

--- config.sh.orig	2013-03-19 10:58:39.000000000 +0000
+++ config.sh
@@ -103,6 +103,8 @@ check_pkg "json" || fail "json"
 
 if [ `uname -s` = "Darwin" ]; then
 	check_custom "ncurses5.4" "ncurses5.4-config" || fail "ncurses5.4"
+elif [ `uname -s` = "NetBSD" ]; then
+	echo "Assuming native NetBSD curses should be used"
 else 
 	check_custom "ncursesw5" "ncursesw5-config" || fail "ncursesw5"
 fi
