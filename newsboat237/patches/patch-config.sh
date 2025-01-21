$NetBSD$

Disable ncurses detection.  We will override this to avoid mixing
system libcurses from devel/stfl with libncurses.

--- config.sh.orig	2024-09-22 15:05:50.000000000 +0000
+++ config.sh
@@ -129,7 +129,7 @@ if [ `uname -s` = "Darwin" ]; then
     # gettext-sys crate needs CoreFoundation framework, and rustc doesn't
     # (can't) link it into libnewsboat.a
     echo 'LDFLAGS+=-framework CoreFoundation' >> config.mk
-elif [ `uname -s` != "OpenBSD" ]; then
+elif false && [ `uname -s` != "OpenBSD" ]; then
 	check_pkg "ncursesw" || \
 	check_custom "ncursesw5" "ncursesw5-config" || \
 		check_custom "ncursesw6" "ncursesw6-config" || fail "ncursesw"
