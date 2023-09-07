$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/DesktopIntegrationDialog.hpp.orig	2023-09-06 06:42:26.000000000 +0000
+++ src/slic3r/GUI/DesktopIntegrationDialog.hpp
@@ -2,7 +2,7 @@
 ///|/
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #ifndef slic3r_DesktopIntegrationDialog_hpp_
 #define slic3r_DesktopIntegrationDialog_hpp_
 
@@ -46,4 +46,4 @@ private:
 } // namespace Slic3r
 
 #endif // slic3r_DesktopIntegrationDialog_hpp_
-#endif // __linux__
\ No newline at end of file
+#endif // __linux__
