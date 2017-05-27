$NetBSD$

--- util/main-loop.c.orig	2017-04-25 12:42:53.000000000 +0000
+++ util/main-loop.c
@@ -56,7 +56,7 @@ static void sigfd_handler(void *opaque)
         }
 
         if (len != sizeof(info)) {
-            printf("read from sigfd returned %zd: %m\n", len);
+            printf("read from sigfd returned %zd: %s\n", len, strerror(errno));
             return;
         }
 
