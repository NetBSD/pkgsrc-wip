$NetBSD$

Use posix_fadvise and pread instead of readahead for greater portability.

--- src/readahead.c.orig	2008-10-23 01:08:21.000000000 +0000
+++ src/readahead.c
@@ -152,7 +152,15 @@ process_file(const char *path, size_t of
 	   );
   if (fd >= 0)
     {
-      readahead(fd, offset, length);
+      char buf[4096];
+      size_t end = offset + length;
+
+      posix_fadvise(fd, offset, length, POSIX_FADV_WILLNEED);
+      for (size_t i = offset; i < end; i += 4096)
+	{
+	  size_t unread = end - i, nbytes = unread < 4096 ? unread : 4096;
+	  pread(fd, buf, nbytes, i);
+	}
 
       close (fd);
     }
