$NetBSD$

Include stdlib.h for exit(3)

--- TheForceEngine/TFE_System/CrashHandler/crashHandlerLinux.cpp.orig	2023-05-27 05:02:04.000000000 +0000
+++ TheForceEngine/TFE_System/CrashHandler/crashHandlerLinux.cpp
@@ -3,6 +3,7 @@
 #include <TFE_FileSystem/paths.h>
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <signal.h>
 
 static void sigabrtHandler(int);
