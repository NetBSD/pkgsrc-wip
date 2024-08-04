--- src/main.cpp.orig	2021-06-16 16:05:40.556415348 +0000
+++ src/main.cpp
@@ -293,8 +293,8 @@
     // Only Windows 10 has tar. Older windows versions not supported.
     zipToolPath = "tar";
 #else
-    zipToolPath = "/usr/bin/zip";
-    unzipToolPath = "/usr/bin/unzip";
+    zipToolPath = "@PREFIX@/bin/zip";
+    unzipToolPath = "@PREFIX@/bin/unzip";
 #endif
     iconPath = vymBaseDir.path() + "/icons/";
     flagsPath = vymBaseDir.path() + "/flags/";
