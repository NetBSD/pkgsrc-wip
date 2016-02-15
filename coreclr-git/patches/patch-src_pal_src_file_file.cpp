$NetBSD$

--- src/pal/src/file/file.cpp.orig	2016-02-06 02:05:27.000000000 +0000
+++ src/pal/src/file/file.cpp
@@ -3943,7 +3943,7 @@ CopyFileA(
     
     LPSTR lpUnixPath = NULL;
     const int    buffer_size = 16*1024;
-    char        *buffer = (char*)alloca(buffer_size);
+    char        *buffer = (char*)Alloca(buffer_size);
     DWORD        bytes_read;
     DWORD        bytes_written;
     int          permissions;
