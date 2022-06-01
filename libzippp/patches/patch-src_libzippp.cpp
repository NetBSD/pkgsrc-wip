$NetBSD$

Fix handling of error format
From upstream:
https://github.com/ctabin/libzippp/commit/22df3bb79597b0a9587a31143bf05006bca9c70d

--- src/libzippp.cpp.orig	2022-05-31 18:51:45.141506061 +0000
+++ src/libzippp.cpp
@@ -228,7 +228,7 @@ bool ZipArchive::open(OpenMode om, bool 
         char* errorStr = new char[256];
         zip_error_to_str(errorStr, 255, errorFlag, errno);
         errorStr[255] = '\0';
-        LIBZIPPP_ERROR_DEBUG("Unable to open archive", errorStr)
+        LIBZIPPP_ERROR_DEBUG("Unable to open archive: %s", errorStr)
         delete[] errorStr;
         errorStr = nullptr;
         
@@ -290,7 +290,7 @@ int ZipArchive::close(void) {
             
                 bufferLength = newLength;
             } else {
-                LIBZIPPP_ERROR_DEBUG("can't read back from source", "changes were not pushed by in the buffer")
+                LIBZIPPP_ERROR_DEBUG("can't read back from source: %s", "changes were not pushed by in the buffer")
                 return srcOpen;
             }
         }
