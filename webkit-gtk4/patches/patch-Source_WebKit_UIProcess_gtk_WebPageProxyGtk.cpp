$NetBSD$

--- Source/WebKit/UIProcess/gtk/WebPageProxyGtk.cpp.orig	2020-09-04 06:25:12.000000000 +0000
+++ Source/WebKit/UIProcess/gtk/WebPageProxyGtk.cpp
@@ -72,9 +72,9 @@ String WebPageProxy::standardUserAgent(c
 
 void WebPageProxy::bindAccessibilityTree(const String& plugID)
 {
-    auto* accessible = gtk_widget_get_accessible(viewWidget());
-    atk_socket_embed(ATK_SOCKET(accessible), const_cast<char*>(plugID.utf8().data()));
-    atk_object_notify_state_change(accessible, ATK_STATE_TRANSIENT, FALSE);
+//    auto* accessible = gtk_widget_get_accessible(viewWidget());
+//    atk_socket_embed(ATK_SOCKET(accessible), const_cast<char*>(plugID.utf8().data()));
+//    atk_object_notify_state_change(accessible, ATK_STATE_TRANSIENT, FALSE);
 }
 
 void WebPageProxy::saveRecentSearches(const String&, const Vector<WebCore::RecentSearch>&)
