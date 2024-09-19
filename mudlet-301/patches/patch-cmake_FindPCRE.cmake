$NetBSD$
Swap out /usr/local with @PREFIX@
--- cmake/FindPCRE.cmake.orig	2017-07-11 00:01:53.000000000 +0000
+++ cmake/FindPCRE.cmake
@@ -12,7 +12,7 @@ FIND_PATH(PCRE_INCLUDE_DIR pcre.h
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw # Fink
   /opt/local # DarwinPorts
@@ -28,7 +28,7 @@ FIND_LIBRARY(PCRE_LIBRARY_RELEASE 
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw
   /opt/local
@@ -44,7 +44,7 @@ FIND_LIBRARY(PCRE_LIBRARY_DEBUG 
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw
   /opt/local
@@ -60,7 +60,7 @@ FIND_LIBRARY(PCRECPP_LIBRARY_RELEASE 
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw
   /opt/local
@@ -76,7 +76,7 @@ FIND_LIBRARY(PCRECPP_LIBRARY_DEBUG 
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw
   /opt/local
@@ -92,7 +92,7 @@ FIND_LIBRARY(PCREPOSIX_LIBRARY_RELEASE 
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw
   /opt/local
@@ -108,7 +108,7 @@ FIND_LIBRARY(PCREPOSIX_LIBRARY_DEBUG 
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw
   /opt/local
