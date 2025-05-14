$NetBSD$

Use the new way of dealing with different-sized
time_t types in FFI.

--- src/netsnmpy/netsnmp_ffi.py.orig	2025-05-14 09:52:14.408968553 +0000
+++ src/netsnmpy/netsnmp_ffi.py
@@ -20,9 +20,11 @@ typedef unsigned short u_short;
 typedef unsigned char u_char;
 typedef unsigned int u_int;
 typedef unsigned long oid;
+typedef int... time_t;
+typedef int... suseconds_t;
 typedef struct timeval {{
-    long tv_sec;
-    long tv_usec;
+    time_t tv_sec;
+    suseconds_t tv_usec;
 }};
 
 
