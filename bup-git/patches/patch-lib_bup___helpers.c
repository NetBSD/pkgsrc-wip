$NetBSD: patch-lib_bup___helpers.c,v 1.3 2015/06/21 20:08:51 thomasklausner Exp $

--- lib/bup/_helpers.c.orig	2015-06-21 15:07:36.000000000 +0000
+++ lib/bup/_helpers.c
@@ -14,6 +14,7 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <sys/mman.h>
 
 #ifdef HAVE_SYS_TYPES_H
@@ -1355,7 +1356,7 @@ static PyObject *bup_fmincore(PyObject *
     const off_t pages_per_chunk = chunk_size / page_size;
     const off_t page_count = (st.st_size + page_size - 1) / page_size;
     const off_t chunk_count = page_count / chunk_size > 0 ? page_count / chunk_size : 1;
-    unsigned char * const result = malloc(page_count);
+    char * result = malloc(page_count);
     if (result == NULL)
         return PyErr_SetFromErrno(PyExc_OSError);
 
@@ -1378,14 +1379,14 @@ static PyObject *bup_fmincore(PyObject *
             if (rc != 0)
             {
                 char buf[512];
-                char *msg = strerror_r(errno, buf, 512);
+                rc = strerror_r(errno, buf, sizeof(buf));
                 if (rc != 0)
                     fprintf(stderr, "%s:%d: strerror_r failed (%d)\n",
                             __FILE__, __LINE__, rc < 0 ? errno : rc);
                 else
                     fprintf(stderr,
                             "%s:%d: munmap failed after mincore failed (%s)\n",
-                            __FILE__, __LINE__, msg);
+                            __FILE__, __LINE__, buf);
             }
             free(result);
             errno = errno_stash;
