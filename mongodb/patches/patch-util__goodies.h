$NetBSD: patch-util__goodies.h,v 1.1 2012/02/22 11:36:27 bartoszkuzma Exp $

--- util/goodies.h.orig	2011-12-14 17:18:48.000000000 +0000
+++ util/goodies.h
@@ -40,7 +40,7 @@ namespace mongo {
         return s.str();
     }
 
-#if !defined(_WIN32) && !defined(NOEXECINFO) && !defined(__freebsd__) && !defined(__openbsd__) && !defined(__sun__)
+#if !defined(_WIN32) && !defined(NOEXECINFO) && !defined(__freebsd__) && !defined(__netbsd__) && !defined(__openbsd__) && !defined(__sun__)
 
 } // namespace mongo
 
