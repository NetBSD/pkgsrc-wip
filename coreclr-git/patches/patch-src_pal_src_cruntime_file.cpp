$NetBSD$

--- src/pal/src/cruntime/file.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/cruntime/file.cpp
@@ -844,6 +844,15 @@ PAL_fgetpos (
     // TODO: implement for Linux if required
     ASSERT(FALSE);
     return -1;
+#elif defined(__NetBSD__)
+    off_t native_pos;
+
+    if ((native_pos = ftello(f->bsdFilePtr)) == -1)
+        return -1;
+
+    *pos = native_pos;
+
+    return 0;
 #else
     int    nRetVal = -1;
     fpos_t native_pos;
@@ -890,6 +899,14 @@ PAL_fsetpos (
     // TODO: implement for Linux if required
     ASSERT(FALSE);
     return  -1;
+#elif defined(__NetBSD__)
+    off_t native_pos;
+
+    native_pos = *pos;
+    if (fseeko(f->bsdFilePtr, native_pos, SEEK_SET) == -1)
+        return -1;
+
+    return 0;
 #else
     int    nRetVal = -1;
     fpos_t native_pos;
