$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- dpip/dpip.c.orig	2026-01-06 16:25:07.209620860 +0000
+++ dpip/dpip.c
@@ -220,7 +220,7 @@ int a_Dpip_check_auth(const char *auth_t
    } else {
       port = strtol(rcline, &tail, 10);
       if (tail && port != 0) {
-         for (i = 0; *tail && isxdigit(tail[i+1]); ++i)
+         for (i = 0; *tail && isxdigit((unsigned char)tail[i+1]); ++i)
             SharedSecret[i] = tail[i+1];
          SharedSecret[i] = 0;
          if (strcmp(msg, SharedSecret) == 0)
