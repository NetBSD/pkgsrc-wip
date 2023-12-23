$NetBSD$

Trying to work around further Boost breakage. To be pushed upstream?
Actually, requiring C++11 and using std::bind could be another path.
Or using lambdas, which everyone tells you are much easier. C++ is great!
Muahahahahahahahahahahahahha!

--- src/c_api.cpp.orig	2022-06-20 18:26:14.096102848 +0000
+++ src/c_api.cpp
@@ -498,7 +498,7 @@ LAS_DLL LASErrorEnum LASReader_SetOutput
         
         transforms.erase( std::remove_if( transforms.begin(), 
                                   transforms.end(),
-                                  boost::bind( &IsReprojectionTransform, _1 ) ),
+                                  boost::bind( &IsReprojectionTransform, boost::placeholders::_1 ) ),
                   transforms.end());
         
         liblas::TransformPtr srs_transform = liblas::TransformPtr(new liblas::ReprojectionTransform(in_ref, *out_ref, &h));
@@ -1840,7 +1840,7 @@ LAS_DLL LASErrorEnum LASWriter_SetOutput
         
         transforms.erase( std::remove_if( transforms.begin(), 
                                   transforms.end(),
-                                  boost::bind( &IsReprojectionTransform, _1 ) ),
+                                  boost::bind( &IsReprojectionTransform, boost::placeholders::_1 ) ),
                   transforms.end());
         
         liblas::TransformPtr srs_transform = liblas::TransformPtr(new liblas::ReprojectionTransform(in_ref, *out_ref, &h));
