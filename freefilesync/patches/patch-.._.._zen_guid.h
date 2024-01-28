$NetBSD$

Support non-glibc. getentropy exists on NetBSD.

--- ../../zen/guid.h.orig	2024-01-28 13:48:13.764500122 +0000
+++ ../../zen/guid.h
@@ -21,7 +21,7 @@ std::string generateGUID() //creates a 1
     std::string guid(16, '\0');
 
 #ifndef __GLIBC_PREREQ
-#error Where is Glibc?
+#define __GLIBC_PREREQ(x, y) 1
 #endif
 
 #if __GLIBC_PREREQ(2, 25) //getentropy() requires Glibc 2.25 (ldd --version) PS: CentOS 7 is on 2.17
