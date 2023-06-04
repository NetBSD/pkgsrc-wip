$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI.hpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/GUI.hpp
@@ -84,7 +84,7 @@ extern void desktop_open_datadir_folder(
 // Ask the destop to open the directory specified by path using the default file explorer.
 void desktop_open_folder(const boost::filesystem::path& path);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 // Calling wxExecute on Linux with proper handling of AppImage's env vars.
 // argv example: { "xdg-open", path.c_str(), nullptr }
 void desktop_execute(const char* argv[]);
