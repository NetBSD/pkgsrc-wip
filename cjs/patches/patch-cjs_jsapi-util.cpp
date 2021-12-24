$NetBSD$

--- cjs/jsapi-util.cpp.orig	2021-11-15 11:51:30.000000000 +0000
+++ cjs/jsapi-util.cpp
@@ -26,7 +26,7 @@
 
 #include <stdio.h>   // for sscanf
 #include <string.h>  // for strlen
-
+#include <cstdarg>
 #ifdef _WIN32
 #    define WIN32_LEAN_AND_MEAN
 #    include <windows.h>
