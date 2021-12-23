$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/PresetComboBoxes.hpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/PresetComboBoxes.hpp
@@ -111,7 +111,7 @@ protected:
     void validate_selection(bool predicate = false);
     void update_selection();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     static const char* separator_head() { return "------- "; }
     static const char* separator_tail() { return " -------"; }
 #else // __linux__ 
