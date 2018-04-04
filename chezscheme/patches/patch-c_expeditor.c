$NetBSD$

--- c/expeditor.c.orig	2017-10-11 22:26:23.000000000 +0000
+++ c/expeditor.c
@@ -546,7 +546,9 @@ static void s_ee_write_char(wchar_t c) {
 #include <sys/ioctl.h>
 #include <wchar.h>
 #include <locale.h>
+#ifndef __GLIBC__
 #include <xlocale.h>
+#endif
 
 #if defined(TIOCGWINSZ) && defined(SIGWINCH) && defined(EINTR)
 #define HANDLE_SIGWINCH
