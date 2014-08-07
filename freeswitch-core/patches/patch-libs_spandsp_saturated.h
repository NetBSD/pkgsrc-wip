$NetBSD: patch-libs_spandsp_saturated.h,v 1.1 2014/08/07 17:40:11 darcycain Exp $

- Horrible kludge

--- libs/spandsp/src/spandsp/saturated.h.orig	2012-09-19 14:44:54.000000000 +0000
+++ libs/spandsp/src/spandsp/saturated.h
@@ -37,6 +37,8 @@
 
 */
 
+long long lrintl(long double);
+
 #if defined(__cplusplus)
 extern "C"
 {
