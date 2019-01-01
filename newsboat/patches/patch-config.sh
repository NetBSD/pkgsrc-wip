$NetBSD$

Remove overly "smart" detection script for ncurses.  This doesn't work on NetBSD.
If libstfl is linked against the system-wide curses, you can't later link against
ncurses.  Newsboat can use the ncursesw compat offered by NetBSD 6.x native curses.

--- config.sh.orig	2018-12-29 13:07:06.000000000 +0000
+++ config.sh
@@ -110,6 +110,8 @@ if [ `uname -s` = "Darwin" ]; then
     # rand crate needs Security framework, and rustc doesn't (can't) link it
     # into libnewsboat.a
     echo 'LDFLAGS+=-framework Security' >> config.mk
+elif [ `uname -s` = "NetBSD" ]; then
+	echo "Assuming native NetBSD curses should be used"
 elif [ `uname -s` != "OpenBSD" ]; then
 	check_pkg "ncursesw" || \
 	check_custom "ncursesw5" "ncursesw5-config" || \
