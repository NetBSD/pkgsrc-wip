$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- dpi/cookies.c.orig	2026-01-06 16:25:07.192584702 +0000
+++ dpi/cookies.c
@@ -487,14 +487,14 @@ static int Cookies_get_timefield(const c
    int n;
    const char *s = *str;
 
-   if (!isdigit(*s))
+   if (!isdigit((unsigned char)*s))
       return -1;
 
    n = *(s++) - '0';
-   if (isdigit(*s)) {
+   if (isdigit((unsigned char)*s)) {
       n *= 10;
       n += *(s++) - '0';
-      if (isdigit(*s))
+      if (isdigit((unsigned char)*s))
          return -1;
    }
    *str = s;
@@ -550,24 +550,24 @@ static bool_t Cookies_get_year(struct tm
    int n;
    const char *s = *str;
 
-   if (isdigit(*s))
+   if (isdigit((unsigned char)*s))
       n = *(s++) - '0';
    else
       return FALSE;
-   if (isdigit(*s)) {
+   if (isdigit((unsigned char)*s)) {
       n *= 10;
       n += *(s++) - '0';
    } else
       return FALSE;
-   if (isdigit(*s)) {
+   if (isdigit((unsigned char)*s)) {
       n *= 10;
       n += *(s++) - '0';
    }
-   if (isdigit(*s)) {
+   if (isdigit((unsigned char)*s)) {
       n *= 10;
       n += *(s++) - '0';
    }
-   if (isdigit(*s)) {
+   if (isdigit((unsigned char)*s)) {
       /* Sorry, users of prehistoric software in the year 10000! */
       return FALSE;
    }
@@ -936,7 +936,7 @@ static CookieData_t *Cookies_parse(char 
          cookie->domain = value;
       } else if (dStrAsciiCasecmp(attr, "Max-Age") == 0) {
          value = Cookies_parse_value(&str);
-         if (isdigit(*value) || *value == '-') {
+         if (isdigit((unsigned char)*value) || *value == '-') {
             long age;
             time_t now = time(NULL);
             struct tm *tm = gmtime(&now);
