$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/web_contents/web_contents_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/web_contents/web_contents_impl.cc
@@ -3760,6 +3760,13 @@ void WebContentsImpl::Init(const WebCont
       params.main_frame_name, GetOpener(), primary_main_frame_policy,
       base::UnguessableToken::Create());
 
+  if (params.view && params.delegate_view) {
+    view_.reset(params.view);
+    render_view_host_delegate_view_ = params.delegate_view;
+  }
+
+  if (!view_) {
+
   std::unique_ptr<WebContentsViewDelegate> delegate =
       GetContentClient()->browser()->GetWebContentsViewDelegate(this);
 
@@ -3770,6 +3777,7 @@ void WebContentsImpl::Init(const WebCont
     view_ = CreateWebContentsView(this, std::move(delegate),
                                   &render_view_host_delegate_view_);
   }
+  }  // !view_
   CHECK(render_view_host_delegate_view_);
   CHECK(view_.get());
 
@@ -4009,21 +4017,25 @@ KeyboardEventProcessingResult WebContent
     const input::NativeWebKeyboardEvent& event) {
   OPTIONAL_TRACE_EVENT0(TRACE_DISABLED_BY_DEFAULT("content.verbose"),
                         "WebContentsImpl::PreHandleKeyboardEvent");
-  auto* outermost_contents = GetOutermostWebContents();
-  // TODO(wjmaclean): Generalize this to forward all key events to the outermost
-  // delegate's handler.
-  if (outermost_contents != this && IsFullscreen() &&
-      event.windows_key_code == ui::VKEY_ESCAPE) {
-    // When an inner WebContents has focus and is fullscreen, redirect <esc>
-    // key events to the outermost WebContents so it can be handled by that
-    // WebContents' delegate.
-    if (outermost_contents->PreHandleKeyboardEvent(event) ==
-        KeyboardEventProcessingResult::HANDLED) {
+
+  auto handled = delegate_ ? delegate_->PreHandleKeyboardEvent(this, event)
+                   : KeyboardEventProcessingResult::NOT_HANDLED;
+
+  if (IsFullscreen() && event.windows_key_code == ui::VKEY_ESCAPE) {
+    if (handled == KeyboardEventProcessingResult::HANDLED)
       return KeyboardEventProcessingResult::HANDLED;
+
+    // When an inner WebContents has focus and is fullscreen, traverse through
+    // containing webcontents to any that may handle the escape key.
+    while (auto* outer_web_contents = GetOuterWebContents()) {
+      auto result = outer_web_contents->PreHandleKeyboardEvent(event);
+      if (result == KeyboardEventProcessingResult::HANDLED) {
+        return KeyboardEventProcessingResult::HANDLED;
+      }
     }
   }
-  return delegate_ ? delegate_->PreHandleKeyboardEvent(this, event)
-                   : KeyboardEventProcessingResult::NOT_HANDLED;
+
+  return handled;
 }
 
 bool WebContentsImpl::HandleMouseEvent(const blink::WebMouseEvent& event) {
@@ -4182,7 +4194,7 @@ void WebContentsImpl::EnterFullscreenMod
   OPTIONAL_TRACE_EVENT0("content", "WebContentsImpl::EnterFullscreenMode");
   DCHECK(CanEnterFullscreenMode(requesting_frame));
   DCHECK(requesting_frame->IsActive());
-  DCHECK(ContainsOrIsFocusedWebContents());
+  DCHECK(ContainsOrIsFocusedWebContents() || IsGuest());
   if (base::FeatureList::IsEnabled(
           features::kAutomaticFullscreenContentSetting)) {
     // Ensure the window is made active to take input focus. The user may have
@@ -4790,8 +4802,7 @@ FrameTree* WebContentsImpl::CreateNewWin
 
   if (delegate_ && delegate_->IsWebContentsCreationOverridden(
                        source_site_instance, params.window_container_type,
-                       opener->GetLastCommittedURL(), params.frame_name,
-                       params.target_url)) {
+                       opener->GetLastCommittedURL(), params)) {
     auto* web_contents_impl =
         static_cast<WebContentsImpl*>(delegate_->CreateCustomWebContents(
             opener, source_site_instance, is_new_browsing_instance,
@@ -4810,9 +4821,6 @@ FrameTree* WebContentsImpl::CreateNewWin
   bool renderer_started_hidden =
       params.disposition == WindowOpenDisposition::NEW_BACKGROUND_TAB;
 
-  // While some guest types do not have a guest SiteInstance, the ones that
-  // don't all override WebContents creation above.
-  CHECK_EQ(source_site_instance->IsGuest(), IsGuest());
   bool is_guest = IsGuest();
 
   // We usually create the new window in the same BrowsingInstance (group of
@@ -4895,6 +4903,12 @@ FrameTree* WebContentsImpl::CreateNewWin
   SetPartitionedPopinOpenerOnNewWindowIfNeeded(new_contents_impl, params,
                                                opener);
 
+  if (delegate_) {
+    delegate_->WebContentsCreatedWithFullParams(this, render_process_id,
+                                                opener->GetRoutingID(),
+                                                params, new_contents_impl);
+  }
+
   // If the new frame has a name, make sure any SiteInstances that can find
   // this named frame have proxies for it.  Must be called after
   // SetSessionStorageNamespace, since this calls CreateRenderView, which uses
@@ -4936,12 +4950,6 @@ FrameTree* WebContentsImpl::CreateNewWin
     AddWebContentsDestructionObserver(new_contents_impl);
   }
 
-  if (delegate_) {
-    delegate_->WebContentsCreated(this, render_process_id,
-                                  opener->GetRoutingID(), params.frame_name,
-                                  params.target_url, new_contents_impl);
-  }
-
   observers_.NotifyObservers(&WebContentsObserver::DidOpenRequestedURL,
                              new_contents_impl, opener, params.target_url,
                              params.referrer.To<Referrer>(), params.disposition,
@@ -5620,6 +5628,11 @@ TextInputManager* WebContentsImpl::GetTe
   return text_input_manager_.get();
 }
 
+void WebContentsImpl::OnCursorChanged(const ui::Cursor& cursor) {
+  observers_.NotifyObservers(&WebContentsObserver::OnCursorChanged,
+                             cursor);
+}
+
 bool WebContentsImpl::IsWidgetForPrimaryMainFrame(
     RenderWidgetHostImpl* render_widget_host) {
   return render_widget_host == GetPrimaryMainFrame()->GetRenderWidgetHost();
@@ -9381,7 +9394,7 @@ void WebContentsImpl::OnFocusedElementCh
                         "WebContentsImpl::OnFocusedElementChangedInFrame",
                         "render_frame_host", frame);
   RenderWidgetHostViewBase* root_view =
-      static_cast<RenderWidgetHostViewBase*>(GetRenderWidgetHostView());
+      static_cast<RenderWidgetHostViewBase*>(GetTopLevelRenderWidgetHostView());
   if (!root_view || !frame->GetView()) {
     return;
   }
@@ -9518,25 +9531,13 @@ void WebContentsImpl::RendererUnresponsi
     base::RepeatingClosure hang_monitor_restarter) {
   OPTIONAL_TRACE_EVENT1("content", "WebContentsImpl::RendererUnresponsive",
                         "render_widget_host", render_widget_host);
-  if (ShouldIgnoreUnresponsiveRenderer()) {
+  if (IsBeingDestroyed()) {
     return;
   }
 
   bool visible = GetVisibility() == Visibility::VISIBLE;
   RecordRendererUnresponsiveMetrics(visible, render_widget_host);
 
-  // Do not report hangs (to task manager, to hang renderer dialog, etc.) for
-  // invisible tabs (like extension background page, background tabs).  See
-  // https://crbug.com/881812 for rationale and for choosing the visibility
-  // (rather than process priority) as the signal here.
-  if (!visible) {
-    return;
-  }
-
-  if (!render_widget_host->renderer_initialized()) {
-    return;
-  }
-
   CrashRepHandlingOutcome outcome =
       base::CommandLine::ForCurrentProcess()->HasSwitch(
           switches::kNoErrorDialogs)
