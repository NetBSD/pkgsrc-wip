$NetBSD$

Treat NetBSD like linux.

--- src/slic3r/GUI/WipeTowerDialog.cpp.orig	2024-06-15 08:31:43.070223802 +0000
+++ src/slic3r/GUI/WipeTowerDialog.cpp
@@ -379,7 +379,7 @@ WipingPanel::WipingPanel(wxWindow* paren
                                               int xpos = m_gridsizer_advanced->GetPosition().x;
                                               if (!m_page_advanced->IsEnabled()) {
                                                   dc.SetTextForeground(wxSystemSettings::GetColour(
-#if defined (__linux__) && defined (__WXGTK2__)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(__WXGTK2__)
                                                       wxSYS_COLOUR_BTNTEXT
 #else 
                                                       wxSYS_COLOUR_GRAYTEXT
@@ -420,4 +420,4 @@ void WipingDialog::enable_or_disable_pan
     m_widget_button->Enable(enable);
     m_panel_wiping->Enable(enable);
     m_panel_wiping->Refresh();
-}
\ No newline at end of file
+}
