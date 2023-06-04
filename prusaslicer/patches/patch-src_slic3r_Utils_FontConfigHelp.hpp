$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/Utils/FontConfigHelp.hpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/Utils/FontConfigHelp.hpp
@@ -1,7 +1,7 @@
 #ifndef slic3r_FontConfigHelp_hpp_
 #define slic3r_FontConfigHelp_hpp_
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #define EXIST_FONT_CONFIG_INCLUDE
 #endif
 
