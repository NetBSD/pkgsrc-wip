$NetBSD$

Provide a hook to replace correct type for time_t and suseconds_t.
See pre-configure target.

--- src/netsnmpy/netsnmp_ffi.py.orig	2025-02-19 13:40:58.000000000 +0000
+++ src/netsnmpy/netsnmp_ffi.py
@@ -20,9 +20,11 @@ typedef unsigned short u_short;
 typedef unsigned char u_char;
 typedef unsigned int u_int;
 typedef unsigned long oid;
+typedef @TIME_T@ time_t; /* @TIME_T@ substituted by pre-configure target */
+typedef @SUSECONDS_T@ suseconds_t; /* also done by pre-configure target */
 typedef struct timeval {{
-    long tv_sec;
-    long tv_usec;
+    time_t tv_sec;
+    suseconds_t tv_usec;
 }};
 
 
