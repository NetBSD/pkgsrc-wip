$NetBSD$

Add NetBSD.

--- src/vde_router/vde_headers.h.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/vde_router/vde_headers.h
@@ -22,7 +22,7 @@
 #define PROTO_TCP 6
 #define PROTO_UDP 17
 
-#if defined(VDE_FREEBSD) || defined(VDE_DARWIN)
+#if defined(VDE_FREEBSD) || defined(VDE_DARWIN) || defined(VDE_NETBSD)
 struct iphdr
 {
 #if BYTE_ORDER == LITTLE_ENDIAN
