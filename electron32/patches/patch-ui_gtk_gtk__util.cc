$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gtk/gtk_util.cc.orig	2024-10-18 12:35:12.728268900 +0000
+++ ui/gtk/gtk_util.cc
@@ -222,9 +222,13 @@ aura::Window* GetAuraTransientParent(Gtk
 }
 
 void ClearAuraTransientParent(GtkWidget* dialog, aura::Window* parent) {
+  if (!parent || !parent->GetHost()) {
+    return;
+  }
+
   g_object_set_data(G_OBJECT(dialog), kAuraTransientParent, nullptr);
-  GtkUi::GetPlatform()->ClearTransientFor(
-      parent->GetHost()->GetAcceleratedWidget());
+  gfx::AcceleratedWidget parent_id = parent->GetHost()->GetAcceleratedWidget();
+  GtkUi::GetPlatform()->ClearTransientFor(parent_id);
 }
 
 base::OnceClosure DisableHostInputHandling(GtkWidget* dialog,
