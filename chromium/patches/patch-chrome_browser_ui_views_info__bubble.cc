$NetBSD: patch-chrome_browser_ui_views_info__bubble.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/info_bubble.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/info_bubble.cc
@@ -314,7 +314,7 @@ void InfoBubble::AnimationProgressed(con
 
 InfoBubble::InfoBubble()
     :
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
       WidgetGtk(TYPE_WINDOW),
       border_contents_(NULL),
 #elif defined(OS_WIN)
@@ -386,7 +386,7 @@ void InfoBubble::Init(views::Widget* par
   WidgetWin::Init(border_->GetNativeView(), gfx::Rect());
 
   SetWindowText(GetNativeView(), delegate_->accessible_name().c_str());
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_USES_GTK)
   MakeTransparent();
   make_transient_to_parent();
   WidgetGtk::InitWithWidget(parent, gfx::Rect());
@@ -462,7 +462,7 @@ void InfoBubble::Init(views::Widget* par
   ShowWindow(SW_SHOW);
   if (fade_in)
     FadeIn();
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_USES_GTK)
   views::WidgetGtk::Show();
 #endif
 }
@@ -502,7 +502,7 @@ void InfoBubble::OnActivate(UINT action,
     GetRootView()->GetChildViewAt(0)->RequestFocus();
   }
 }
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
 void InfoBubble::IsActiveChanged() {
   if (!IsActive())
     Close();
@@ -521,7 +521,7 @@ void InfoBubble::DoClose(bool closed_by_
 #if defined(OS_WIN)
   border_->Close();
   WidgetWin::Close();
-#elif defined(OS_LINUX)
+#elif defined(TOOLKIT_GTK)
   WidgetGtk::Close();
 #endif
 }
