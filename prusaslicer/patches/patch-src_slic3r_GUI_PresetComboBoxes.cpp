$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/PresetComboBoxes.cpp.orig	2023-06-14 14:36:02.000000000 +0000
+++ src/slic3r/GUI/PresetComboBoxes.cpp
@@ -779,7 +779,7 @@ void PlaterPresetComboBox::show_edit_men
         [this](wxCommandEvent&) { this->switch_to_tab(); }, "cog", menu, []() { return true; }, wxGetApp().plater());
 
     if (m_type == Preset::TYPE_FILAMENT) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         // To edit extruder color from the sidebar
         append_menu_item(menu, wxID_ANY, _L("Change extruder color"), "",
             [this](wxCommandEvent&) { this->change_extruder_color(); }, "funnel", menu, []() { return true; }, wxGetApp().plater());
