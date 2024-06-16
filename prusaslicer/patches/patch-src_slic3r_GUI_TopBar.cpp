$NetBSD$

Treat NetBSD like linux.

--- src/slic3r/GUI/TopBar.cpp.orig	2024-06-15 08:28:06.304213704 +0000
+++ src/slic3r/GUI/TopBar.cpp
@@ -68,7 +68,7 @@ void TopBarItemsCtrl::Button::set_select
                                          wxTransparentColor;
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     this->SetBackgroundColour(m_background_color);
     this->SetForegroundColour(m_foreground_color);
 
@@ -94,7 +94,7 @@ void TopBarItemsCtrl::Button::set_hovere
                                             wxTransparentColor;
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     this->SetBackgroundColour(m_background_color);
 #endif // __linux__
 
@@ -163,7 +163,7 @@ void TopBarItemsCtrl::Button::sys_color_
     m_foreground_color = wxGetApp().get_label_clr_default();
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 const int icon_sz = 20;
 #else
 const int icon_sz = 24;
@@ -213,7 +213,7 @@ void TopBarItemsCtrl::ButtonWithPopup::S
 #endif
 
     wxString full_label = "  " + text + "  ";
-#ifndef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     full_label += down_arrow;
 #endif
     ScalableButton::SetLabel(full_label);
@@ -228,7 +228,7 @@ void TopBarItemsCtrl::UpdateAccountButto
     TopBarMenus::UserAccountInfo  user_account = m_menus->get_user_account_info();
     const wxString user_name = user_account.is_logged ? from_u8(user_account.user_name) : _L("Log in");
     m_account_btn->SetToolTip(user_name);
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     if (avatar) {
         if (user_account.is_logged) {
             ScalableBitmap new_logo(this, user_account.avatar_path, wxSize(icon_sz, icon_sz));
@@ -504,7 +504,7 @@ TopBarItemsCtrl::TopBarItemsCtrl(wxWindo
 void TopBarItemsCtrl::UpdateMode()
 {
     wxBitmapBundle bmp = *m_menus->get_workspace_bitmap();
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     m_workspace_btn->SetBitmap(bmp);
     m_workspace_btn->SetBitmapCurrent(bmp);
     m_workspace_btn->SetBitmapPressed(bmp);
