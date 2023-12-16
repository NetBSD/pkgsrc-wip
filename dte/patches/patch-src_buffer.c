$NetBSD$

memcpy needs a source

--- src/buffer.c.orig	2023-03-01 23:29:00.000000000 +0000
+++ src/buffer.c
@@ -459,7 +459,7 @@ String dump_buffer(const Buffer *buffer)
     char modestr[12];
     char timestr[64];
     if (!timespec_to_str(&file->mtime, timestr, sizeof(timestr))) {
-        memcpy(timestr, STRN("[error]") + 1);
+        memcpy(timestr, "[error]", 8);
     }
 
     string_sprintf (
