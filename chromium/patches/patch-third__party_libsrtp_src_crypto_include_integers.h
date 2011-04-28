$NetBSD: patch-third__party_libsrtp_src_crypto_include_integers.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/libsrtp/src/crypto/include/integers.h.orig	2011-04-13 08:02:07.000000000 +0000
+++ third_party/libsrtp/src/crypto/include/integers.h
@@ -76,7 +76,7 @@
 #endif
 
 /* Can we do 64 bit integers? */
-#ifndef HAVE_UINT64_T
+#if !defined(HAVE_UINT64_T) && !defined(__OpenBSD__)
 # if SIZEOF_UNSIGNED_LONG == 8
 typedef unsigned long		uint64_t;
 # elif SIZEOF_UNSIGNED_LONG_LONG == 8
