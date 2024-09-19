$NetBSD: patch-common.h,v 1.1 2013/05/24 11:40:31 othyro Exp $

Add NetBSD support.

--- common.h.orig	2008-03-20 16:49:38.000000000 +0000
+++ common.h
@@ -25,7 +25,7 @@
 #ifndef COMMON_H
 #define COMMON_H
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 # include <sys/endian.h>
 # define bswap_16 bswap16
 # define bswap_32 bswap32
