$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/root_view.cc.orig	2024-07-24 02:45:10.968106700 +0000
+++ ui/views/widget/root_view.cc
@@ -128,7 +128,7 @@ class AnnounceTextView : public View {
 #if BUILDFLAG(IS_CHROMEOS)
     // On ChromeOS, kAlert role can invoke an unnecessary event on reparenting.
     node_data->role = ax::mojom::Role::kStaticText;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40658933): Use live regions (do not use alerts).
     // May require setting kLiveStatus, kContainerLiveStatus to "polite".
     node_data->role = ax::mojom::Role::kAlert;
