$NetBSD: patch-src_mongo_util_time__support.h,v 1.1 2013/06/03 13:58:35 fhajny Exp $

This file gets included at two places, and the condition only works
properly the first time.

--- src/mongo/util/time_support.h.orig	2013-04-22 14:48:39.000000000 +0000
+++ src/mongo/util/time_support.h	2013-05-30 14:18:35.026376057 +0000
@@ -96,10 +96,6 @@ namespace mongo {
     struct tm *gmtime(const time_t *timep);
     struct tm *localtime(const time_t *timep);
 
-#if defined(MONGO_BOOST_TIME_UTC_HACK) || (BOOST_VERSION >= 105000)
 #define MONGO_BOOST_TIME_UTC boost::TIME_UTC_
-#else
-#define MONGO_BOOST_TIME_UTC boost::TIME_UTC
-#endif
 
 }  // namespace mongo
