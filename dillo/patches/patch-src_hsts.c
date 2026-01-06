$NetBSD$

Avoid ctype(3) undefined behaviours.

--- src/hsts.c.orig	2026-01-06 16:25:07.233270206 +0000
+++ src/hsts.c
@@ -223,7 +223,7 @@ void a_Hsts_set(const char *header, cons
       /* Get the value for the attribute and store it */
       if (dStrAsciiCasecmp(attr, "max-age") == 0) {
          value = Hsts_parse_value(&header);
-         if (isdigit(*value)) {
+         if (isdigit((unsigned char)*value)) {
             errno = 0;
             max_age = strtol(value, NULL, 10);
             if (errno == ERANGE)
