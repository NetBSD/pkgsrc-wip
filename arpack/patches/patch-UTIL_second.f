$NetBSD: patch-UTIL_second.f,v 1.2 2012/03/23 02:26:48 outpaddling Exp $

#

--- UTIL/second.f.orig	1995-10-02 18:56:44.000000000 +0000
+++ UTIL/second.f
@@ -20,8 +20,9 @@
       REAL               TARRAY( 2 )
 *     ..
 *     .. External Functions ..
-      REAL               ETIME
-      EXTERNAL           ETIME
+*  ETIME is intrinsic, so this causes undefined reference errors in newer gcc
+*      REAL               ETIME
+*      EXTERNAL           ETIME
 *     ..
 *     .. Executable Statements ..
 *
