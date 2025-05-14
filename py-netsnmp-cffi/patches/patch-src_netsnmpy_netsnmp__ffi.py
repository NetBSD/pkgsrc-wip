$NetBSD$

Use the new way of dealing with different-sized
time_t types in FFI.

Also handle the difference in sockaddr layout on Linux & BSDs.

--- src/netsnmpy/netsnmp_ffi.py.orig	2025-05-14 09:52:14.408968553 +0000
+++ src/netsnmpy/netsnmp_ffi.py
@@ -12,6 +12,17 @@ typedef struct _callback_data {
     void          *reserved;
     unsigned long  session_id;
 } _callback_data;
+typedef struct linux_sockaddr_in {
+     unsigned short sa_family;
+     unsigned short sa_port;
+     char           sa_data[14];
+} linux_sockaddr_in;
+typedef struct bsd_sockaddr_in {
+     uint8_t  sa_len;
+     uint8_t  sa_family;
+     unsigned short sa_port;
+     char     sa_data[14];
+} bsd_sockaddr_in;
 """
 _CDEF = f"""
 /* Typedefs and structs we will be needing access to */
@@ -20,9 +31,11 @@ typedef unsigned short u_short;
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
 
 
