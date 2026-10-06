$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/widget/root_view.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/widget/root_view.cc
@@ -165,7 +165,7 @@ class AnnounceTextView : public View {
 #if BUILDFLAG(IS_CHROMEOS)
     // On ChromeOS, kAlert role can invoke an unnecessary event on reparenting.
     GetViewAccessibility().SetRole(ax::mojom::Role::kStaticText);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40658933): Use live regions (do not use alerts).
     // May require setting kLiveStatus, kContainerLiveStatus to "polite".
     GetViewAccessibility().SetRole(ax::mojom::Role::kAlert);
