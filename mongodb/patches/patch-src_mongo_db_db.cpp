$NetBSD: patch-src_mongo_db_db.cpp,v 1.1 2013/06/03 13:58:35 fhajny Exp $

Avoid ambiguous overload.
--- src/mongo/db/db.cpp.orig	2013-04-22 14:48:39.000000000 +0000
+++ src/mongo/db/db.cpp	2013-06-03 10:53:01.722318315 +0000
@@ -250,7 +250,7 @@ namespace mongo {
         toLog.append( "startTimeLocal", buf );
 
         toLog.append( "cmdLine", CmdLine::getParsedOpts() );
-        toLog.append( "pid", getpid() );
+        toLog.append( "pid", (int)getpid() );
 
 
         BSONObjBuilder buildinfo( toLog.subobjStart("buildinfo"));
