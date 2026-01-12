$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- src/IO/http.c.orig	2026-01-06 16:25:07.220765195 +0000
+++ src/IO/http.c
@@ -701,7 +701,7 @@ static char *Http_get_connect_str(const 
    dstr = dStr_new("");
    auth1 = URL_AUTHORITY(url);
    auth_len = strlen(auth1);
-   if (auth_len > 0 && !isdigit(auth1[auth_len - 1]))
+   if (auth_len > 0 && !isdigit((unsigned char)auth1[auth_len - 1]))
       /* if no port number, add HTTPS port */
       auth2 = dStrconcat(auth1, ":443", NULL);
    else
