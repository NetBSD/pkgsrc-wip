$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/ExtraRenderers.cpp.orig	2026-06-25 15:30:20.000000000 +0000
+++ src/slic3r/GUI/ExtraRenderers.cpp
@@ -370,7 +370,7 @@ wxWindow* BitmapChoiceRenderer::CreateEd
     }
 
     
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     c_editor->Bind(wxEVT_COMBOBOX, [this](wxCommandEvent& evt) {
         // to avoid event propagation to other sidebar items
         evt.StopPropagation();
