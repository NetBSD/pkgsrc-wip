$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/GUI.cpp
@@ -490,7 +490,7 @@ void desktop_open_folder(const boost::fi
 #endif
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 namespace {
 wxExecuteEnv get_appimage_exec_env()
 {
