$NetBSD$

Avoid ctype(3) undefined behaviours.

Shared upstream via:
<https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/>

--- src/IO/dpi.c.orig	2026-01-06 16:25:07.223239131 +0000
+++ src/IO/dpi.c
@@ -404,7 +404,7 @@ static int Dpi_read_comm_keys(int *port)
       MSG_ERR("[Dpi_read_comm_keys] empty file: %s\n", fname);
    } else {
       *port = strtol(rcline, &tail, 10);
-      for (i = 0; *tail && isxdigit(tail[i+1]); ++i)
+      for (i = 0; *tail && isxdigit((unsigned char)tail[i+1]); ++i)
          SharedKey[i] = tail[i+1];
       SharedKey[i] = 0;
       ret = 1;
