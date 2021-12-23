$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/DesktopIntegrationDialog.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/DesktopIntegrationDialog.cpp
@@ -1,4 +1,4 @@
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include "DesktopIntegrationDialog.hpp"
 #include "GUI_App.hpp"
 #include "GUI.hpp"
@@ -503,4 +503,4 @@ DesktopIntegrationDialog::~DesktopIntegr
 
 } // namespace GUI
 } // namespace Slic3r
-#endif // __linux__
\ No newline at end of file
+#endif // __linux__
