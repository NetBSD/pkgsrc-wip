$NetBSD: patch-src__mongo__util__time_support.h,v 1.1 2012/11/29 14:52:39 fhajny Exp $

Make sure we stay compatible with Boost 1.50.x
--- src/mongo/util/time_support.h.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/util/time_support.h
@@ -86,10 +86,6 @@ namespace mongo {
     struct tm *gmtime(const time_t *timep);
     struct tm *localtime(const time_t *timep);
 
-#if defined(MONGO_BOOST_TIME_UTC_HACK) || (BOOST_VERSION >= 105000)
 #define MONGO_BOOST_TIME_UTC boost::TIME_UTC_
-#else
-#define MONGO_BOOST_TIME_UTC boost::TIME_UTC
-#endif
 
 }  // namespace mongo
