$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/web_contents.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/web_contents.h
@@ -111,10 +111,13 @@ class BrowserPluginGuestDelegate;
 class GuestPageHolder;
 class RenderFrameHost;
 class RenderViewHost;
+class RenderViewHostDelegateView;
 class RenderWidgetHostView;
+class RenderWidgetHostViewBase;
 class ScreenOrientationDelegate;
 class SiteInstance;
 class WebContentsDelegate;
+class WebContentsView;
 class WebUI;
 struct DropData;
 struct MHTMLGenerationParams;
@@ -275,6 +278,10 @@ class WebContents : public PageNavigator
     network::mojom::WebSandboxFlags starting_sandbox_flags =
         network::mojom::WebSandboxFlags::kNone;
 
+    // Optionally specify the view and delegate view.
+    raw_ptr<content::WebContentsView> view = nullptr;
+    raw_ptr<content::RenderViewHostDelegateView> delegate_view = nullptr;
+
     // Value used to set the last time the WebContents was made active, this is
     // the value that'll be returned by GetLastActiveTimeTicks(). If this is
     // left default initialized then the value is not passed on to the
