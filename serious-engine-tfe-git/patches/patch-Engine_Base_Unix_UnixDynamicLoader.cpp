$NetBSD$

 1) Check for an error (in the handle), instead of just the error string.
    (Otherwise transient errors are detected as a loading error.)
 2) Use the package directory to find the game libraries.

--- Engine/Base/Unix/UnixDynamicLoader.cpp.orig	2020-09-26 18:29:18.000000000 +0000
+++ Engine/Base/Unix/UnixDynamicLoader.cpp
@@ -65,7 +65,9 @@ void *CUnixDynamicLoader::FindSymbol(con
 void CUnixDynamicLoader::DoOpen(const char *lib)
 {
     module = ::dlopen(lib, RTLD_LAZY | RTLD_GLOBAL);
-    SetError();
+    if (module == NULL) {
+        SetError();
+    }
 }
 
 
@@ -78,7 +80,8 @@ CTFileName CDynamicLoader::ConvertLibNam
     #endif
     CTFileName fnm = CTString(libname);
     CTString libstr((strncmp("lib", fnm.FileName(), 3) == 0) ? "" : "lib");
-    return(fnm.FileDir() + libstr + fnm.FileName() + DLLEXTSTR);
+    // use the pkgsrc path to find libraries, not the path name
+    return(libstr + fnm.FileName() + DLLEXTSTR);
 }
 
 
@@ -94,9 +97,7 @@ CUnixDynamicLoader::CUnixDynamicLoader(c
         // Always try to dlopen from inside the game dirs before trying
         //  system libraries...
         if (fnm.FileDir() == "") {
-            char buf[MAX_PATH];
-            _pFileSystem->GetExecutablePath(buf, sizeof (buf));
-            CTFileName fnmDir = CTString(buf);
+            CTFileName fnmDir = CTString(PACKAGE_LIBDIR);
             fnmDir = fnmDir.FileDir() + fnm;
             DoOpen(fnmDir);
             if (module != NULL) {
