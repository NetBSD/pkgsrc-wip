$NetBSD$

Fix build on non-Linux systems.

--- ict-main.cpp.orig	2012-04-06 22:19:27.000000000 +0000
+++ ict-main.cpp
@@ -18,7 +18,6 @@
  */
 
 
-#include <argp.h>
 #include <pwd.h>
 #include <string>
 #include <unistd.h>
