$NetBSD$

Treat NetBSD like Linux.

--- src/imgui/imgui_demo.cpp.orig	2023-11-23 14:51:47.000000000 +0000
+++ src/imgui/imgui_demo.cpp
@@ -5678,6 +5678,9 @@ void ImGui::ShowAboutWindow(bool* p_open
 #ifdef __linux__
         ImGui::Text("define: __linux__");
 #endif
+#ifdef __NetBSD__
+        ImGui::Text("define: __NetBSD__");
+#endif
 #ifdef __APPLE__
         ImGui::Text("define: __APPLE__");
 #endif
