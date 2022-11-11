$NetBSD$

# Fix for clang

--- inc/globals.h.orig	2022-11-10 21:07:28 UTC
+++ inc/globals.h
@@ -21,6 +21,7 @@
 //#include <ctime>
 //#include <list>
 #include <map>
+#include <array>
 #include <vector>
 #include <numeric>
 
