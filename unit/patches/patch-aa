$NetBSD$


--- src/nxt_conn_write.c.orig	2020-05-28 12:04:00.000000000 -0400
+++ src/nxt_conn_write.c	2020-08-08 16:49:50.752693316 -0400
@@ -266,6 +266,21 @@
     res = sendfile(s, fd, &pos, size);
 #endif
 
+#ifdef NXT_HAVE_NETBSD_SENDFILE
+    struct stat fileinfo;
+    void *fmem = NULL;
+    res = fstat(fd, &fileinfo);
+    if (res == 0) {
+        fmem = mmap(NULL, fileinfo.st_size, PROT_READ, MAP_FILE | MAP_SHARED, fd, 0);
+    }
+    if (fmem != NULL) {
+        res = write(s, fmem, fileinfo.st_size);
+        munmap(fmem, fileinfo.st_size);
+    } else {
+        res = -1;
+    }
+#endif 
+
     return res;
 }
 
