$NetBSD$

Avoid ctype(3) undefined behaviours.

--- dpid/dpidc.c.orig	2026-01-06 16:25:07.204748644 +0000
+++ dpid/dpidc.c
@@ -59,7 +59,7 @@ static int Dpi_read_comm_keys(int *port)
       MSG_ERR("[Dpi_read_comm_keys] empty file: %s\n", fname);
    } else {
       *port = strtol(rcline, &tail, 10);
-      for (i = 0; *tail && isxdigit(tail[i+1]); ++i)
+      for (i = 0; *tail && isxdigit((unsigned char)tail[i+1]); ++i)
          SharedKey[i] = tail[i+1];
       SharedKey[i] = 0;
       ret = 1;
