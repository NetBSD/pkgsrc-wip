$NetBSD$

Remove types defined with reserved names, breaks build with musl-libc
where those names are already defined in sys/types.h.

--- rpc/types.h.orig	2009-01-12 15:55:23.000000000 +0000
+++ rpc/types.h
@@ -41,9 +41,6 @@ typedef unsigned char u_char;
 typedef uint16_t      u_short;
 typedef uint32_t      u_int;
 typedef unsigned long u_long;
-typedef uint64_t      u_quad_t;
-typedef int64_t       quad_t;
-typedef char *        caddr_t;
 
 #ifndef TRUE
 #define TRUE 1
