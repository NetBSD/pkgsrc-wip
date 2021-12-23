$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/HintNotification.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/HintNotification.cpp
@@ -715,8 +715,11 @@ void NotificationManager::HintNotificati
 	if (is_finished())
 		return;
 
+	// stix
+	// wxGetApp().imgui()->new_frame();
 	count_spaces();
 	count_lines();
+	// ImGui::EndFrame();
 
 	m_multiline = true;
 
@@ -1058,4 +1061,4 @@ void NotificationManager::HintNotificati
     }
 }
 } //namespace Slic3r 
-} //namespace GUI 
\ No newline at end of file
+} //namespace GUI 
