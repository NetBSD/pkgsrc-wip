--- src/mainwindow.cpp.orig	2021-06-16 16:05:40.556415348 +0000
+++ src/mainwindow.cpp
@@ -6572,6 +6572,7 @@
     searchList << "doc"; // relative path for easy testing in tarball
     searchList << "/usr/share/doc/vym";      // Debian
     searchList << "/usr/share/doc/packages"; // Knoppix
+    searchList << "@PREFIX@/share/doc/vym";
 
     bool found = false;
     QFile docfile;
