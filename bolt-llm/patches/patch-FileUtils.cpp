$NetBSD$

# Unused variable
--- FileUtils.cpp.orig	2017-09-20 10:29:18 UTC
+++ FileUtils.cpp
@@ -275,7 +275,7 @@ namespace FileUtils {
     uint Layout = (flags>>2)&0xf; cout << "Layout: " << Layout << endl;
     assert(Layout==1 || Layout==2); // REQUIRE Layout==1 or Layout==2
 
-    uint SampleIdentifiers = flags>>31; //cout << "SampleIdentifiers: " << SampleIdentifiers << endl;
+    // uint SampleIdentifiers = flags>>31; cout << "SampleIdentifiers: " << SampleIdentifiers << endl;
     fseek(fin, offset+4, SEEK_SET);
 
     // check first SNP
