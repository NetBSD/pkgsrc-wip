$NetBSD$

--- src/Main/MainPy.cpp.orig	2016-04-07 01:39:34.000000000 +0000
+++ src/Main/MainPy.cpp
@@ -76,6 +76,9 @@ BOOL APIENTRY DllMain(HANDLE hModule, DW
 #   define GNU_SOURCE
 # endif
 # include <dlfcn.h>
+#elif defined(FC_OS_BSD)
+# include <link.h>
+# include <dlfcn.h>
 #elif defined(FC_OS_CYGWIN)
 # include <windows.h>
 #endif
@@ -100,7 +103,12 @@ extern "C"
         char** argv;
         argv = (char**)malloc(sizeof(char*)* (argc+1));
 
-#if defined(FC_OS_WIN32)
+#if defined(HOMEDIR)
+	App::Application::Config()["AppHomePath"] = HOMEDIR;
+	argv[0] = (char*)malloc(PATH_MAX);
+	strncpy(argv[0], HOMEDIR, PATH_MAX);
+	argv[0][PATH_MAX-1] = '\0'; // ensure null termination
+#elif defined(FC_OS_WIN32)
         argv[0] = (char*)malloc(MAX_PATH);
         strncpy(argv[0],App::Application::Config()["AppHomePath"].c_str(),MAX_PATH);
         argv[0][MAX_PATH-1] = '\0'; // ensure null termination
@@ -111,7 +119,7 @@ extern "C"
         argv[0] = (char*)malloc(MAX_PATH);
         strncpy(argv[0],szFileName,MAX_PATH);
         argv[0][MAX_PATH-1] = '\0'; // ensure null termination
-#elif defined(FC_OS_LINUX)
+#elif defined(FC_OS_BSD) || defined(FC_OS_LINUX)
         putenv("LANG=C");
         putenv("LC_ALL=C");
         // get whole path of the library
