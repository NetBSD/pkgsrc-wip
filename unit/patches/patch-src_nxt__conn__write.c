--- src/nxt_conn_write.c.orig	2020-05-28 12:04:00.000000000 -0400
+++ src/nxt_conn_write.c	2020-08-12 14:52:46.453112517 -0400
@@ -266,6 +266,21 @@
     res = sendfile(s, fd, &pos, size);
 #endif
 
+#ifdef NXT_HAVE_NETBSD_MMAP_WRITE
+    int   err;
+    void *map;
+
+    map = mmap(NULL, size, PROT_READ, MAP_FILE | MAP_SHARED, fd, pos);
+    if (nxt_slow_path(map == MAP_FAILED)) {
+        return -1;
+    }
+
+    res = write(s, map, size);
+    err = errno;
+    (void) munmap(map, size);
+    errno = err;
+#endif 
+
     return res;
 }
 
