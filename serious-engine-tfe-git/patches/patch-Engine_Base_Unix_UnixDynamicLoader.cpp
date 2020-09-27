$NetBSD$

Don't override the search paths for libraries, the rpath is correct.

--- Engine/Base/Unix/UnixDynamicLoader.cpp.orig	2020-09-26 18:29:18.000000000 +0000
+++ Engine/Base/Unix/UnixDynamicLoader.cpp
@@ -78,7 +78,8 @@ CTFileName CDynamicLoader::ConvertLibNam
     #endif
     CTFileName fnm = CTString(libname);
     CTString libstr((strncmp("lib", fnm.FileName(), 3) == 0) ? "" : "lib");
-    return(fnm.FileDir() + libstr + fnm.FileName() + DLLEXTSTR);
+    // use the rpath to find libraries, not the path name
+    return(libstr + fnm.FileName() + DLLEXTSTR);
 }
 
 
@@ -91,6 +92,7 @@ CUnixDynamicLoader::CUnixDynamicLoader(c
     } else {
         CTFileName fnm = ConvertLibNameToPlatform(libname);
 
+#if 0
         // Always try to dlopen from inside the game dirs before trying
         //  system libraries...
         if (fnm.FileDir() == "") {
@@ -103,6 +105,7 @@ CUnixDynamicLoader::CUnixDynamicLoader(c
                 return;
             }
         }
+#endif
 
         DoOpen(fnm);
     }
