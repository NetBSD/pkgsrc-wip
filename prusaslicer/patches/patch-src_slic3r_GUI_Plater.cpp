$NetBSD$

Treat NetBSD like Linux.

Fix ambiguous overload errors with wxWidgets 3.2.4
http://github.com/prusa3d/PrusaSlicer/issues/11768

--- src/slic3r/GUI/Plater.cpp.orig	2025-03-10 13:20:54.000000000 +0000
+++ src/slic3r/GUI/Plater.cpp
@@ -1271,7 +1271,7 @@ std::vector<size_t> Plater::priv::load_f
     // when loading a project file. However, creating the dialog on heap causes issues on macOS, where it does not
     // appear at all. Therefore, we create the dialog on stack on Win and macOS, and on heap on Linux, which
     // is the only system that needed the workarounds in the first place.
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     auto progress_dlg = new wxProgressDialog(loading, "", 100, find_toplevel_parent(q), wxPD_APP_MODAL | wxPD_AUTO_HIDE);
     Slic3r::ScopeGuard([&progress_dlg](){ if (progress_dlg) progress_dlg->Destroy(); progress_dlg = nullptr; });
 #else
@@ -3559,7 +3559,7 @@ void Plater::priv::on_right_click(RBtnEv
         Vec2d mouse_position = evt.data.first;
         wxPoint position(static_cast<int>(mouse_position.x()),
                          static_cast<int>(mouse_position.y()));
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         // For some reason on Linux the menu isn't displayed if position is
         // specified (even though the position is sane).
         position = wxDefaultPosition;
