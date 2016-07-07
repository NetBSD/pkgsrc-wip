$NetBSD$

--- src/VBox/Main/cbinding/VBoxCAPIGlue.c.orig	2016-03-04 19:29:35.000000000 +0000
+++ src/VBox/Main/cbinding/VBoxCAPIGlue.c
@@ -50,7 +50,7 @@
 /*********************************************************************************************************************************
 *   Defined Constants And Macros                                                                                                 *
 *********************************************************************************************************************************/
-#if defined(__linux__) || defined(__linux_gnu__) || defined(__sun__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__linux_gnu__) || defined(__sun__) || defined(__FreeBSD__) || defined(__NetBSD__)
 # define DYNLIB_NAME        "VBoxXPCOMC.so"
 #elif defined(__APPLE__)
 # define DYNLIB_NAME        "VBoxXPCOMC.dylib"
@@ -280,6 +280,9 @@ int VBoxCGlueInit(void)
 #elif defined(__FreeBSD__)
     if (tryLoadLibrary("/usr/local/lib/virtualbox", 1) == 0)
         return 0;
+#elif defined(__NetBSD__)
+    if (tryLoadLibrary("/usr/local/lib/virtualbox", 1) == 0)
+        return 0;
 #elif defined(__OS2__)
     if (tryLoadLibrary("C:/Apps/VirtualBox", 1) == 0)
         return 0;
@@ -336,4 +339,3 @@ void VBoxCGlueTerm(void)
     g_pfnGetFunctions = NULL;
     memset(g_szVBoxErrMsg, 0, sizeof(g_szVBoxErrMsg));
 }
-
