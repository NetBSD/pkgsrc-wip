$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/DesktopIntegrationDialog.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/DesktopIntegrationDialog.cpp
@@ -1,4 +1,4 @@
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include "DesktopIntegrationDialog.hpp"
 #include "GUI_App.hpp"
 #include "GUI.hpp"
