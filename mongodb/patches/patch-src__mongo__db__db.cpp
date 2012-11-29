$NetBSD: patch-src__mongo__db__db.cpp,v 1.1 2012/11/29 14:52:38 fhajny Exp $

Backport Boost 1.50.x support based on
https://github.com/mongodb/mongo/commit/b3b1949de30b5dc1bde3d91aa197a8587d17d193
--- src/mongo/db/db.cpp.orig	2012-08-28 05:28:11.000000000 +0000
+++ src/mongo/db/db.cpp
@@ -348,7 +348,7 @@ namespace mongo {
         boost::filesystem::path path( dbpath );
         for ( boost::filesystem::directory_iterator i( path );
                 i != boost::filesystem::directory_iterator(); ++i ) {
-            string fileName = boost::filesystem::path(*i).leaf();
+            string fileName = boost::filesystem::path(*i).leaf().string();
             if ( boost::filesystem::is_directory( *i ) &&
                     fileName.length() && fileName[ 0 ] == '$' )
                 boost::filesystem::remove_all( *i );
@@ -748,11 +748,6 @@ static int mongoDbMain(int argc, char* a
     dbExecCommand = argv[0];
 
     srand(curTimeMicros());
-#if( BOOST_VERSION >= 104500 )
-    boost::filesystem::path::default_name_check( boost::filesystem2::no_check );
-#else
-    boost::filesystem::path::default_name_check( boost::filesystem::no_check );
-#endif
 
     {
         unsigned x = 0x12345678;
@@ -1083,7 +1078,7 @@ static int mongoDbMain(int argc, char* a
         if (params.count("shutdown")){
             bool failed = false;
 
-            string name = ( boost::filesystem::path( dbpath ) / "mongod.lock" ).native_file_string();
+            string name = ( boost::filesystem::path( dbpath ) / "mongod.lock" ).string();
             if ( !boost::filesystem::exists( name ) || boost::filesystem::file_size( name ) == 0 )
                 failed = true;
 
