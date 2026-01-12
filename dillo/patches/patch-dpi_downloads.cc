$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- dpi/downloads.cc.orig	2026-01-06 16:25:07.202386354 +0000
+++ dpi/downloads.cc
@@ -513,7 +513,7 @@ void DLItem::log_text_add(const char *bu
       case ST_newline:
          if (*p == ' ') {
             log_state = ST_discard;
-         } else if (isdigit(*p)) {
+         } else if (isdigit((unsigned char)*p)) {
             *q++ = *p; log_state = ST_number;
          } else if (*p == '\n') {
             *q++ = *p;
@@ -522,10 +522,10 @@ void DLItem::log_text_add(const char *bu
          }
          break;
       case ST_number:
-         if (isdigit(*q++ = *p)) {
+         if (isdigit((unsigned char)(*q++ = *p))) {
             // keep here
          } else if (*p == 'K') {
-            for (--q; isdigit(q[-1]); --q) ; 
+            for (--q; isdigit((unsigned char)q[-1]); --q) ; 
             log_state = ST_discard;
          } else {
             log_state = ST_copy;
@@ -549,9 +549,9 @@ void DLItem::log_text_add(const char *bu
    // Now scan for the length of the file
    if (total_bytesize == -1) {
       p = strstr(log_text, "\nLength: ");
-      if (p && isdigit(p[9]) && strchr(p + 9, ' ')) {
+      if (p && isdigit((unsigned char)p[9]) && strchr(p + 9, ' ')) {
          for (p += 9, d = &num[0]; *p != ' '; ++p)
-            if (isdigit(*p))
+            if (isdigit((unsigned char)*p))
                *d++ = *p;
          *d = 0;
          total_bytesize = strtol (num, NULL, 10);
