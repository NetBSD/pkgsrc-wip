$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI_Utils.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/GUI_Utils.cpp
@@ -48,7 +48,7 @@ void on_window_geometry(wxTopLevelWindow
     // cf. https://groups.google.com/forum/#!topic/wx-users/c7ntMt6piRI
     // OTOH the geometry is available very soon, so we can call the callback right away
     callback();
-#elif defined __linux__
+#elif defined(__linux__) || defined(__NetBSD__)
     tlw->Bind(wxEVT_SHOW, [=](wxShowEvent &evt) {
         // On Linux, the geometry is only available after wxEVT_SHOW + CallAfter
         // cf. https://groups.google.com/forum/?pli=1#!topic/wx-users/fERSXdpVwAI
