$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- dpi/dpiutil.c.orig	2026-01-06 16:25:07.199992497 +0000
+++ dpi/dpiutil.c
@@ -67,10 +67,10 @@ char *Unescape_uri_str(const char *s)
 
    if (strchr(s, '%')) {
       for (p = buf; (*p = *s); ++s, ++p) {
-         if (*p == '%' && isxdigit(s[1]) && isxdigit(s[2])) {
-            *p = (isdigit(s[1]) ? (s[1] - '0')
+         if (*p == '%' && isxdigit((unsigned char)s[1]) && isxdigit((unsigned char)s[2])) {
+            *p = (isdigit((unsigned char)s[1]) ? (s[1] - '0')
                                 : D_ASCII_TOUPPER(s[1]) - 'A' + 10) * 16;
-            *p += isdigit(s[2]) ? (s[2] - '0')
+            *p += isdigit((unsigned char)s[2]) ? (s[2] - '0')
                                 : D_ASCII_TOUPPER(s[2]) - 'A' + 10;
             s += 2;
          }
