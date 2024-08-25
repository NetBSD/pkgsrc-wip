$NetBSD$

Support *BSD.

--- module/module.cpp.orig	2024-08-18 20:31:34.039638457 +0000
+++ module/module.cpp
@@ -283,6 +283,12 @@ void mod_GetRealModuleName(const char *m
     strcat(filename, ".dll");
 #elif defined(__LINUX__)
     strcat(filename, ".so");
+#elif defined(__FreeBSD__)
+    strcat(filename, ".so");
+#elif defined(__NetBSD__)
+    strcat(filename, ".so");
+#elif defined(__OpenBSD__)
+    strcat(filename, ".so");
 #elif defined(MACOSX)
     strcat(filename, ".dylib");
 #else
@@ -299,6 +305,21 @@ void mod_GetRealModuleName(const char *m
       strcat(filename, ".so");
     else
       strcat(filename, extension);
+#elif defined(__FreeBSD__)
+    if (!stricmp(extension, ".dll") || !stricmp(extension, "msl") || !stricmp(extension, "dylib"))
+      strcat(filename, ".so");
+    else
+      strcat(filename, extension);
+#elif defined(__NetBSD__)
+    if (!stricmp(extension, ".dll") || !stricmp(extension, "msl") || !stricmp(extension, "dylib"))
+      strcat(filename, ".so");
+    else
+      strcat(filename, extension);
+#elif defined(__OpenBSD__)
+    if (!stricmp(extension, ".dll") || !stricmp(extension, "msl") || !stricmp(extension, "dylib"))
+      strcat(filename, ".so");
+    else
+      strcat(filename, extension);
 #elif defined(MACOSX)
       if (!stricmp(extension, ".dll") || !stricmp(extension, "msl") || !stricmp(extension, "so"))
         strcat(filename, ".dylib");
