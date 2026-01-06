$NetBSD$

Avoid ctype(3) undefined behaviours.

--- dlib/dlib.c.orig	2026-01-06 16:25:07.189521259 +0000
+++ dlib/dlib.c
@@ -525,7 +525,7 @@ const char *dStr_printable(Dstr *in, int
       out = dStr_sized_new(in->len);
 
    for (i = 0; (i < in->len) && (out->len < maxlen); ++i) {
-      if (isprint(in->str[i]) || (in->str[i] == '\n')) {
+      if (isprint((unsigned char)in->str[i]) || (in->str[i] == '\n')) {
          dStr_append_c(out, in->str[i]);
       } else {
          dStr_append_l(out, "\\x", 2);
