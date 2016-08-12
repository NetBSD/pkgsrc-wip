$NetBSD$

--- src/VBox/Main/cbinding/VBoxCAPIGlue.c.orig	2016-08-12 18:06:18.000000000 +0000
+++ src/VBox/Main/cbinding/VBoxCAPIGlue.c
@@ -51,7 +51,7 @@
 /*********************************************************************************************************************************
 *   Defined Constants And Macros                                                                                                 *
 *********************************************************************************************************************************/
-#if defined(__linux__) || defined(__linux_gnu__) || defined(__sun__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__linux_gnu__) || defined(__sun__) || defined(__FreeBSD__) || defined(__NetBSD__)
 # define DYNLIB_NAME        "VBoxXPCOMC.so"
 #elif defined(__APPLE__)
 # define DYNLIB_NAME        "VBoxXPCOMC.dylib"
@@ -278,7 +278,7 @@ int VBoxCGlueInit(void)
 #elif defined(__APPLE__)
     if (tryLoadLibrary("/Applications/VirtualBox.app/Contents/MacOS", 1) == 0)
         return 0;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
     if (tryLoadLibrary("/usr/local/lib/virtualbox", 1) == 0)
         return 0;
 #elif defined(__OS2__)
@@ -337,4 +337,3 @@ void VBoxCGlueTerm(void)
     g_pfnGetFunctions = NULL;
     memset(g_szVBoxErrMsg, 0, sizeof(g_szVBoxErrMsg));
 }
-
