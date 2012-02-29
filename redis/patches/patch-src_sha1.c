$NetBSD: patch-src_sha1.c,v 1.1 2012/02/29 11:34:43 fhajny Exp $

Set endianness properly on 64bit archs.

--- src/sha1.c.orig	2012-01-11 19:30:55.000000000 +0000
+++ src/sha1.c
@@ -41,6 +41,7 @@ A million repetitions of "a"
 #define	PDP_ENDIAN	3412	/* LSB first in word, MSW first in long (pdp)*/
 
 #if defined(vax) || defined(ns32000) || defined(sun386) || defined(__i386__) || \
+    defined(__x86_64) || defined(__amd64) || \
     defined(MIPSEL) || defined(_MIPSEL) || defined(BIT_ZERO_ON_RIGHT) || \
     defined(__alpha__) || defined(__alpha)
 #define BYTE_ORDER	LITTLE_ENDIAN
