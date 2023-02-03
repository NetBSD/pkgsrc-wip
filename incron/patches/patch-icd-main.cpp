$NetBSD$

Fix build on non-Linux systems.

--- icd-main.cpp.orig	2012-04-06 22:19:27.000000000 +0000
+++ icd-main.cpp
@@ -18,7 +18,7 @@
 
 #include <map>
 #include <signal.h>
-#include <wait.h>
+#include <unistd.h>
 #include <fcntl.h>
 #include <pwd.h>
 #include <dirent.h>
