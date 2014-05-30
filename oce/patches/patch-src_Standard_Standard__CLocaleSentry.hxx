$NetBSD: patch-src_Standard_Standard__CLocaleSentry.hxx,v 1.1 2014/05/30 11:21:00 fhajny Exp $

SunOS just doesn't have xlocale.h.
--- src/Standard/Standard_CLocaleSentry.hxx.orig	2014-02-12 20:06:33.000000000 +0000
+++ src/Standard/Standard_CLocaleSentry.hxx
@@ -25,7 +25,7 @@
 //! Notice that this is impossible to test (_POSIX_C_SOURCE >= 200809L)
 //! since POSIX didn't declared such identifier.
 //! We check _GNU_SOURCE for glibc extensions here and it is always defined by g++ compiler.
-#if defined(__APPLE__) || defined(_GNU_SOURCE) || defined(HAVE_XLOCALE_H)
+#if defined(__APPLE__) || (defined(_GNU_SOURCE) && !defined(__sun)) || defined(HAVE_XLOCALE_H)
   #include <xlocale.h>
   #ifndef HAVE_XLOCALE_H
     #define HAVE_XLOCALE_H
