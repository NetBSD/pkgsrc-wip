$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/Field.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/Field.cpp
@@ -199,7 +199,7 @@ bool Field::is_matched(const std::string
 
 static wxString na_value(bool for_spin_ctrl = false)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     if (for_spin_ctrl)
         return "";
 #endif
