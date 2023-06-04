$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI_ObjectManipulation.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/GUI_ObjectManipulation.cpp
@@ -490,7 +490,7 @@ void ObjectManipulation::Show(const bool
         const Selection& selection = wxGetApp().plater()->canvas3D()->get_selection();
         bool show_world_local_combo = wxGetApp().get_mode() != comSimple && (selection.is_single_full_instance() || selection.is_single_volume_or_modifier());
         if (selection.is_single_volume_or_modifier() && m_word_local_combo->GetCount() < 3) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
             m_word_local_combo->Insert(coordinate_type_str(ECoordinatesType::Local), 2);
 #else
             m_word_local_combo->Insert(coordinate_type_str(ECoordinatesType::Local), wxNullBitmap, 2);
