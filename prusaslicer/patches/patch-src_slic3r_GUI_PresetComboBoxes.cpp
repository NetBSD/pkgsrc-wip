$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/PresetComboBoxes.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/PresetComboBoxes.cpp
@@ -584,7 +584,7 @@ PlaterPresetComboBox::PlaterPresetComboB
     {
         // In a case of a physical printer, for its editing open PhysicalPrinterDialog
         if (m_type == Preset::TYPE_PRINTER
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
             // To edit extruder color from the sidebar
             || m_type == Preset::TYPE_FILAMENT
 #endif //__linux__
@@ -716,7 +716,7 @@ void PlaterPresetComboBox::show_edit_men
     append_menu_item(menu, wxID_ANY, _L("Edit preset"), "",
         [this](wxCommandEvent&) { this->switch_to_tab(); }, "cog", menu, []() { return true; }, wxGetApp().plater());
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     // To edit extruder color from the sidebar
     if (m_type == Preset::TYPE_FILAMENT) {
         append_menu_item(menu, wxID_ANY, _L("Change extruder color"), "",
