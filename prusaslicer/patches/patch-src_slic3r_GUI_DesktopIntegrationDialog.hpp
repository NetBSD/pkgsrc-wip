$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/DesktopIntegrationDialog.hpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/DesktopIntegrationDialog.hpp
@@ -1,4 +1,4 @@
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #ifndef slic3r_DesktopIntegrationDialog_hpp_
 #define slic3r_DesktopIntegrationDialog_hpp_
 
@@ -42,4 +42,4 @@ private:
 } // namespace Slic3r
 
 #endif // slic3r_DesktopIntegrationDialog_hpp_
-#endif // __linux__
\ No newline at end of file
+#endif // __linux__
