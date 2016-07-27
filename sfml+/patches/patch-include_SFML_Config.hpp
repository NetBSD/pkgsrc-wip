$NetBSD$

--- include/SFML/Config.hpp.orig	2015-08-24 16:01:06.000000000 +0000
+++ include/SFML/Config.hpp
@@ -86,6 +86,11 @@
         // FreeBSD
         #define SFML_SYSTEM_FREEBSD
 
+    #elif defined(__NetBSD__)
+
+        // NetBSD
+        #define SFML_SYSTEM_NETBSD
+
     #else
 
         // Unsupported UNIX system
