$NetBSD: patch-lib_bup___helpers.c,v 1.5 2015/07/05 20:46:45 thomasklausner Exp $

--- lib/bup/_helpers.c.orig	2015-07-05 20:33:32.000000000 +0000
+++ lib/bup/_helpers.c
@@ -14,8 +14,10 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <stdio.h>
-#include <sys/mman.h>
 
+#ifdef HAVE_SYS_MMAN_H
+#include <sys/mman.h>
+#endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
@@ -1332,77 +1334,48 @@ static PyObject *bup_localtime(PyObject 
 #endif /* def HAVE_TM_TM_GMTOFF */
 
 
-#ifdef HAVE_MINCORE
-static PyObject *bup_fmincore(PyObject *self, PyObject *args)
+#ifdef BUP_MINCORE_BUF_TYPE
+static PyObject *bup_mincore(PyObject *self, PyObject *args)
 {
-    int fd, rc;
-    if (!PyArg_ParseTuple(args, "i", &fd))
-	return NULL;
+    const char *src;
+    Py_ssize_t src_ssize;
+    Py_buffer dest;
+    PyObject *py_src_n, *py_src_off, *py_dest_off;
+    if (!PyArg_ParseTuple(args, "s#OOw*O",
+                          &src, &src_ssize, &py_src_n, &py_src_off,
+                          &dest, &py_dest_off))
+	return NULL;
+
+    unsigned long long src_size, src_n, src_off, dest_size, dest_off;
+    if (!(bup_ullong_from_py(&src_n, py_src_n, "src_n")
+          && bup_ullong_from_py(&src_off, py_src_off, "src_off")
+          && bup_ullong_from_py(&dest_off, py_dest_off, "dest_off")))
+        return NULL;
 
-    struct stat st;
-    rc = fstat(fd, &st);
+    if (!INTEGRAL_ASSIGNMENT_FITS(&src_size, src_ssize))
+        return PyErr_Format(PyExc_OverflowError, "invalid src size");
+    unsigned long long src_region_end;
+
+    if (!uadd(&src_region_end, src_off, src_n))
+        return PyErr_Format(PyExc_OverflowError, "(src_off + src_n) too large");
+    if (src_region_end > src_size)
+        return PyErr_Format(PyExc_OverflowError, "region runs off end of src");
+
+    if (!INTEGRAL_ASSIGNMENT_FITS(&dest_size, dest.len))
+        return PyErr_Format(PyExc_OverflowError, "invalid dest size");
+    if (dest_off > dest_size)
+        return PyErr_Format(PyExc_OverflowError, "region runs off end of dest");
+
+    size_t length;
+    if (!INTEGRAL_ASSIGNMENT_FITS(&length, src_n))
+        return PyErr_Format(PyExc_OverflowError, "src_n overflows size_t");
+    int rc = mincore((void *)(src + src_off), src_n,
+                     (BUP_MINCORE_BUF_TYPE *) (dest.buf + dest_off));
     if (rc != 0)
         return PyErr_SetFromErrno(PyExc_OSError);
-
-    if (st.st_size == 0)
-        return Py_BuildValue("s", "");
-
-    const size_t page_size = (size_t) sysconf (_SC_PAGESIZE);
-    const off_t pref_chunk_size = 64 * 1024 * 1024;
-    off_t chunk_size = page_size;
-    if (page_size < pref_chunk_size)
-        chunk_size = page_size * (pref_chunk_size / page_size);
-    const off_t pages_per_chunk = chunk_size / page_size;
-    const off_t page_count = (st.st_size + page_size - 1) / page_size;
-    const off_t chunk_count = page_count / chunk_size > 0 ? page_count / chunk_size : 1;
-    unsigned char * const result = malloc(page_count);
-    if (result == NULL)
-        return PyErr_SetFromErrno(PyExc_OSError);
-
-    off_t ci;
-    for(ci = 0; ci < chunk_count; ci++)
-    {
-        const off_t pos = chunk_size * ci;
-        const size_t msize = chunk_size < st.st_size - pos ? chunk_size : st.st_size - pos;
-        void *m = mmap(NULL, msize, PROT_NONE, MAP_SHARED, fd, pos);
-        if (m == MAP_FAILED)
-        {
-            free(result);
-            return PyErr_SetFromErrno(PyExc_OSError);
-        }
-        rc = mincore(m, msize, &result[ci * pages_per_chunk]);
-        if (rc != 0)
-        {
-            const int errno_stash = errno;
-            rc = munmap(m, msize);
-            if (rc != 0)
-            {
-                char buf[512];
-                char *msg = strerror_r(errno, buf, 512);
-                if (rc != 0)
-                    fprintf(stderr, "%s:%d: strerror_r failed (%d)\n",
-                            __FILE__, __LINE__, rc < 0 ? errno : rc);
-                else
-                    fprintf(stderr,
-                            "%s:%d: munmap failed after mincore failed (%s)\n",
-                            __FILE__, __LINE__, msg);
-            }
-            free(result);
-            errno = errno_stash;
-            return PyErr_SetFromErrno(PyExc_OSError);
-        }
-        rc = munmap(m, msize);
-        if (rc != 0)
-        {
-            free(result);
-            return PyErr_SetFromErrno(PyExc_OSError);
-        }
-    }
-    PyObject *py_result = Py_BuildValue("s#", result, page_count);
-    free(result);
-    return py_result;
+    return Py_BuildValue("O", Py_None);
 }
-#endif /* def HAVE_MINCORE */
+#endif /* def BUP_MINCORE_BUF_TYPE */
 
 
 static PyMethodDef helper_methods[] = {
@@ -1467,9 +1440,10 @@ static PyMethodDef helper_methods[] = {
     { "localtime", bup_localtime, METH_VARARGS,
       "Return struct_time elements plus the timezone offset and name." },
 #endif
-#ifdef HAVE_MINCORE
-    { "fmincore", bup_fmincore, METH_VARARGS,
-      "Return mincore() information for the provided file descriptor." },
+#ifdef BUP_MINCORE_BUF_TYPE
+    { "mincore", bup_mincore, METH_VARARGS,
+      "For mincore(src, src_n, src_off, dest, dest_off)"
+      " call the system mincore(src + src_off, src_n, &dest[dest_off])." },
 #endif
     { NULL, NULL, 0, NULL },  // sentinel
 };
@@ -1516,6 +1490,14 @@ PyMODINIT_FUNC init_helpers(void)
         Py_DECREF(value);
     }
 #endif
+#ifdef BUP_HAVE_MINCORE_INCORE
+    {
+        PyObject *value;
+        value = INTEGER_TO_PY(MINCORE_INCORE);
+        PyObject_SetAttrString(m, "MINCORE_INCORE", value);
+        Py_DECREF(value);
+    }
+#endif
 #pragma clang diagnostic pop  // ignored "-Wtautological-compare"
 
     e = getenv("BUP_FORCE_TTY");
