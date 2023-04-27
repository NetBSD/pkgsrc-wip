$NetBSD$

--- src/common/platform/posix/sdl/i_system.cpp.orig	2022-12-04 14:35:20.000000000 +0000
+++ src/common/platform/posix/sdl/i_system.cpp
@@ -62,6 +62,7 @@
 #include "i_sound.h"
 #include "i_interface.h"
 #include "v_font.h"
+#include "c_console.h"
 #include "c_cvars.h"
 #include "palutil.h"
 #include "st_start.h"
@@ -408,7 +409,8 @@ FString I_GetFromClipboard (bool use_pri
 
 FString I_GetCWD()
 {
-	char* curdir = get_current_dir_name();
+	char* curdir;
+	curdir = getcwd(NULL, 0);
 	if (!curdir) 
 	{
 		return "";
@@ -447,8 +449,9 @@ unsigned int I_MakeRNGSeed()
 
 void I_OpenShellFolder(const char* infolder)
 {
-	char* curdir = get_current_dir_name();
+	char* curdir;
 
+	curdir = getcwd(NULL, 0);
 	if (!chdir(infolder))
 	{
 		Printf("Opening folder: %s\n", infolder);
