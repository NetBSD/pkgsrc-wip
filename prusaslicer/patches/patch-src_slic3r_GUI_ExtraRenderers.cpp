$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/ExtraRenderers.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/ExtraRenderers.cpp
@@ -320,7 +320,7 @@ wxWindow* BitmapChoiceRenderer::CreateEd
     c_editor->SetSelection(atoi(data.GetText().c_str()));
 
     
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     c_editor->Bind(wxEVT_COMBOBOX, [this](wxCommandEvent& evt) {
         // to avoid event propagation to other sidebar items
         evt.StopPropagation();
