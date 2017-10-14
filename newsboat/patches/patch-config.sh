$NetBSD$

Remove overly "smart" detection script for ncurses.  This doesn't work on NetBSD.
If libstfl is linked against the system-wide curses, you can't later link against
ncurses.  Newsboat can use the ncursesw compat offered by NetBSD 6.x native curses.

--- config.sh.orig	2017-09-22 20:01:50.000000000 +0000
+++ config.sh
@@ -106,6 +106,8 @@ check_pkg "stfl" || fail "stfl"
 
 if [ `uname -s` = "Darwin" ]; then
 	check_custom "ncurses5.4" "ncurses5.4-config" || fail "ncurses5.4"
+elif [ `uname -s` = "NetBSD" ]; then
+       echo "Assuming native NetBSD curses should be used"
 elif [ `uname -s` != "OpenBSD" ]; then
 	check_pkg "ncursesw" || \
 	check_custom "ncursesw5" "ncursesw5-config" ||  fail "ncursesw"
