$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/Plater.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/Plater.cpp
@@ -4214,7 +4214,7 @@ void Plater::priv::on_right_click(RBtnEv
     }
 
     if (q != nullptr && menu) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         // For some reason on Linux the menu isn't displayed if position is specified
         // (even though the position is sane).
         q->PopupMenu(menu);
