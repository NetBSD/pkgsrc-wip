$NetBSD$

# Temporary fix
--- src/FileUtils.cpp.orig	2017-08-02 23:43:24.000000000 +0000
+++ src/FileUtils.cpp
@@ -275,7 +275,7 @@ namespace FileUtils {
     uint Layout = (flags>>2)&0xf; cout << "Layout: " << Layout << endl;
     assert(Layout==1 || Layout==2); // REQUIRE Layout==1 or Layout==2
 
-    uint SampleIdentifiers = flags>>31; //cout << "SampleIdentifiers: " << SampleIdentifiers << endl;
+    // uint SampleIdentifiers = flags>>31; cout << "SampleIdentifiers: " << SampleIdentifiers << endl;
     fseek(fin, offset+4, SEEK_SET);
 
     // check first SNP
