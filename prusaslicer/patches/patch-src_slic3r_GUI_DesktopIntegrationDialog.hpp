$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/DesktopIntegrationDialog.hpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/DesktopIntegrationDialog.hpp
@@ -1,4 +1,4 @@
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #ifndef slic3r_DesktopIntegrationDialog_hpp_
 #define slic3r_DesktopIntegrationDialog_hpp_
 
@@ -36,4 +36,4 @@ private:
 } // namespace Slic3r
 
 #endif // slic3r_DesktopIntegrationDialog_hpp_
-#endif // __linux__
\ No newline at end of file
+#endif // __linux__
