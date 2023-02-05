$NetBSD: patch-caretx.c,v 1.3 2019/04/23 09:27:46 adam Exp $

NetBSD's implementation sometimes returns "/"; reject that too.

--- caretx.c.orig	2023-01-19 22:33:49.000000000 +0000
+++ caretx.c
@@ -123,7 +123,7 @@ Perl_set_caret_X(pTHX) {
        valid path has a '/' in it somewhere, so use that to validate the
        result. See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=35703
     */
-    if (len > 0 && memchr(buf, '/', len)) {
+    if (len > 1 && memchr(buf, '/', len)) {
         sv_setpvn(caret_x, buf, len);
         return;
     }
