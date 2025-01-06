$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/web_contents.h.orig	2024-10-18 12:34:14.438371400 +0000
+++ content/public/browser/web_contents.h
@@ -109,10 +109,13 @@ class BrowserContext;
 class BrowserPluginGuestDelegate;
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
@@ -259,6 +262,10 @@ class WebContents : public PageNavigator
     network::mojom::WebSandboxFlags starting_sandbox_flags =
         network::mojom::WebSandboxFlags::kNone;
 
+    // Optionally specify the view and delegate view.
+    raw_ptr<content::WebContentsView> view = nullptr;
+    raw_ptr<content::RenderViewHostDelegateView> delegate_view = nullptr;
+
     // Value used to set the last time the WebContents was made active, this is
     // the value that'll be returned by GetLastActiveTime(). If this is left
     // default initialized then the value is not passed on to the WebContents
