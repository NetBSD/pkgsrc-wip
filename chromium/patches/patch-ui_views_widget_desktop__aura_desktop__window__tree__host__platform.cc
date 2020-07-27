$NetBSD$

--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc.orig	2020-07-15 18:56:49.000000000 +0000
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform.cc
@@ -787,7 +787,7 @@ void DesktopWindowTreeHostPlatform::AddA
 // DesktopWindowTreeHost:
 
 // Linux subclasses this host and adds some Linux specific bits.
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 // static
 DesktopWindowTreeHost* DesktopWindowTreeHost::Create(
     internal::NativeWidgetDelegate* native_widget_delegate,
