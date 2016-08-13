$NetBSD$

Do not use the FindHomePath mechanism, initially taken from
http://forum.freecadweb.org/viewtopic.php?f=4&t=12890&sid=d37a7267d64c17f325d8cb1e503c63d7

--- src/App/Application.cpp.orig	2016-04-07 01:39:34.000000000 +0000
+++ src/App/Application.cpp
@@ -527,7 +527,7 @@ std::string Application::getUserAppDataD
 std::string Application::getUserMacroDir()
 {
     std::string path("Macro/");
-    return mConfig["UserAppData"] + path;
+    return mConfig["UserAppData"];
 }
 
 std::string Application::getResourceDir()
@@ -1148,7 +1148,13 @@ void Application::initTypes(void)
 void Application::initConfig(int argc, char ** argv)
 {
     // find the home path....
+#if defined(HOMEDIR)
+    std::string path(HOMEDIR);
+    path.append("/");
+    mConfig["AppHomePath"] = path;
+#else
     mConfig["AppHomePath"] = FindHomePath(argv[0]);
+#endif
 
     // Version of the application extracted from SubWCRef into src/Build/Version.h
     // We only set these keys if not yet defined. Therefore it suffices to search
@@ -2058,6 +2064,11 @@ std::string Application::FindHomePath(co
     // Python interpreter is already initialized.
     std::string absPath;
     std::string homePath;
+#ifdef HOMEDIR
+    std::string path(HOMEDIR);
+    path.append("/");
+    absPath = path;
+#else
     if (Py_IsInitialized()) {
         // Note: realpath is known to cause a buffer overflow because it
         // expands the given path to an absolute path of unknown length.
@@ -2081,6 +2092,7 @@ std::string Application::FindHomePath(co
         resolved[nchars] = '\0'; // enfore null termination
         absPath = resolved;
     }
+#endif
 
     // should be an absolute path now
     std::string::size_type pos = absPath.find_last_of("/");
