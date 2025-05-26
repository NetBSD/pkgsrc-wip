$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/win/hwnd_message_handler.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/win/hwnd_message_handler.cc
@@ -656,7 +656,8 @@ void HWNDMessageHandler::Show(ui::mojom:
     SetWindowPlacement(hwnd(), &placement);
     native_show_state = SW_SHOWMAXIMIZED;
   } else {
-    const bool is_maximized = IsMaximized();
+    const bool is_maximized_or_arranged =
+        IsMaximized() || IsWindowArranged(hwnd());
 
     // Use SW_SHOW/SW_SHOWNA instead of SW_SHOWNORMAL/SW_SHOWNOACTIVATE so that
     // the window is not restored to its original position if it is maximized.
@@ -666,7 +667,8 @@ void HWNDMessageHandler::Show(ui::mojom:
     // position, some do not. See crbug.com/1296710
     switch (show_state) {
       case ui::mojom::WindowShowState::kInactive:
-        native_show_state = is_maximized ? SW_SHOWNA : SW_SHOWNOACTIVATE;
+        native_show_state =
+            is_maximized_or_arranged ? SW_SHOWNA : SW_SHOWNOACTIVATE;
         break;
       case ui::mojom::WindowShowState::kMaximized:
         native_show_state = SW_SHOWMAXIMIZED;
@@ -677,9 +679,11 @@ void HWNDMessageHandler::Show(ui::mojom:
       case ui::mojom::WindowShowState::kNormal:
         if ((GetWindowLong(hwnd(), GWL_EXSTYLE) & WS_EX_TRANSPARENT) ||
             (GetWindowLong(hwnd(), GWL_EXSTYLE) & WS_EX_NOACTIVATE)) {
-          native_show_state = is_maximized ? SW_SHOWNA : SW_SHOWNOACTIVATE;
+          native_show_state =
+              is_maximized_or_arranged ? SW_SHOWNA : SW_SHOWNOACTIVATE;
         } else {
-          native_show_state = is_maximized ? SW_SHOW : SW_SHOWNORMAL;
+          native_show_state =
+              is_maximized_or_arranged ? SW_SHOW : SW_SHOWNORMAL;
         }
         break;
       case ui::mojom::WindowShowState::kFullscreen:
@@ -908,13 +912,13 @@ void HWNDMessageHandler::FrameTypeChange
 
 void HWNDMessageHandler::PaintAsActiveChanged() {
   if (!delegate_->HasNonClientView() || !delegate_->CanActivate() ||
-      !delegate_->HasFrame() ||
+      (!delegate_->HasFrame() && !is_translucent_) ||
       (delegate_->GetFrameMode() == FrameMode::CUSTOM_DRAWN)) {
     return;
   }
 
   DefWindowProcWithRedrawLock(WM_NCACTIVATE, delegate_->ShouldPaintAsActive(),
-                              0);
+                              delegate_->HasFrame() ? 0 : -1);
 }
 
 void HWNDMessageHandler::SetWindowIcons(const gfx::ImageSkia& window_icon,
@@ -961,8 +965,11 @@ void HWNDMessageHandler::SetFullscreen(b
 
 void HWNDMessageHandler::SetAspectRatio(float aspect_ratio,
                                         const gfx::Size& excluded_margin) {
-  // If the aspect ratio is not in the valid range, do nothing.
-  DCHECK_GT(aspect_ratio, 0.0f);
+  // If the aspect ratio is 0, reset it to null.
+  if (aspect_ratio == 0.0f) {
+    aspect_ratio_.reset();
+    return;
+  }
 
   aspect_ratio_ = aspect_ratio;
 
@@ -1733,7 +1740,23 @@ LRESULT HWNDMessageHandler::OnCreate(CRE
   SendMessage(hwnd(), WM_CHANGEUISTATE, MAKELPARAM(UIS_CLEAR, UISF_HIDEFOCUS),
               0);
 
-  if (!delegate_->HasFrame()) {
+  LONG is_popup =
+      GetWindowLong(hwnd(), GWL_STYLE) & static_cast<LONG>(WS_POPUP);
+
+  // For transparent windows, Electron removes the WS_CAPTION style,
+  // so we continue to remove it here. If we didn't, an opaque rectangle
+  // would show up.
+  // For non-transparent windows, Electron keeps the WS_CAPTION style,
+  // so we don't remove it in that case. If we did, a Windows 7 frame
+  // would show up.
+  // We also need this block for frameless popup windows. When the user opens
+  // a dropdown in an Electron app, the internal popup menu from
+  // third_party/blink/renderer/core/html/forms/internal_popup_menu.h
+  // is rendered. That menu is actually an HTML page inside of a frameless popup window.
+  // A new popup window is created every time the user opens the dropdown,
+  // and this code path is run. The code block below runs SendFrameChanged,
+  // which gives the dropdown options the proper layout.
+  if (!delegate_->HasFrame() && (is_translucent_ || is_popup)) {
     SetWindowLong(hwnd(), GWL_STYLE,
                   GetWindowLong(hwnd(), GWL_STYLE) & ~WS_CAPTION);
     SendFrameChanged();
@@ -2237,17 +2260,18 @@ LRESULT HWNDMessageHandler::OnNCActivate
   if (IsVisible())
     delegate_->SchedulePaint();
 
-  // Calling DefWindowProc is only necessary if there's a system frame being
-  // drawn. Otherwise it can draw an incorrect title bar and cause visual
-  // corruption.
-  if (!delegate_->HasFrame() ||
+  // If the window is translucent, it may have the Mica background.
+  // In that case, it's necessary to call |DefWindowProc|, but we can
+  // pass -1 in the lParam to prevent any non-client area elements from
+  // being displayed.
+  if ((!delegate_->HasFrame() && !is_translucent_) ||
       delegate_->GetFrameMode() == FrameMode::CUSTOM_DRAWN) {
     SetMsgHandled(TRUE);
     return TRUE;
   }
 
   return DefWindowProcWithRedrawLock(WM_NCACTIVATE, paint_as_active || active,
-                                     0);
+                                     delegate_->HasFrame() ? 0 : -1);
 }
 
 LRESULT HWNDMessageHandler::OnNCCalcSize(BOOL mode, LPARAM l_param) {
@@ -3039,15 +3063,19 @@ LRESULT HWNDMessageHandler::HandleMouseE
       SetMsgHandled(FALSE);
     // We must let Windows handle the caption buttons if it's drawing them, or
     // they won't work.
+    bool simulate_mouse_event_for_caption = false;
     if (delegate_->GetFrameMode() == FrameMode::SYSTEM_DRAWN &&
         (hittest == HTCLOSE || hittest == HTMINBUTTON ||
          hittest == HTMAXBUTTON)) {
-      SetMsgHandled(FALSE);
+      simulate_mouse_event_for_caption =
+          delegate_->HandleMouseEventForCaption(message);
+      if (!simulate_mouse_event_for_caption)
+        SetMsgHandled(FALSE);
     }
     // Let resize events fall through. Ignore everything else, as we're either
     // letting Windows handle it above or we've already handled the equivalent
     // touch message.
-    if (!IsHitTestOnResizeHandle(hittest))
+    if (!IsHitTestOnResizeHandle(hittest) && !simulate_mouse_event_for_caption)
       return 0;
   }
 
@@ -3075,7 +3103,17 @@ LRESULT HWNDMessageHandler::HandleMouseE
     w_param = static_cast<WPARAM>(SendMessage(
         hwnd(), WM_NCHITTEST, 0, MAKELPARAM(screen_point.x, screen_point.y)));
     if (w_param == HTCAPTION || w_param == HTSYSMENU) {
-      ShowSystemMenuAtScreenPixelLocation(hwnd(), gfx::Point(screen_point));
+      LONG message_time = GetMessageTime();
+      CHROME_MSG msg = {hwnd(),
+                        message,
+                        w_param,
+                        l_param,
+                        static_cast<DWORD>(message_time),
+                        {CR_GET_X_LPARAM(l_param), CR_GET_Y_LPARAM(l_param)}};
+      ui::MouseEvent event(msg);
+      event.set_is_system_menu(true);
+      if (!delegate_->HandleMouseEvent(&event))
+        ShowSystemMenuAtScreenPixelLocation(hwnd(), gfx::Point(screen_point));
       return 0;
     }
   } else if (message == WM_NCLBUTTONDOWN &&
@@ -3593,14 +3631,29 @@ void HWNDMessageHandler::SizeWindowToAsp
   delegate_->GetMinMaxSize(&min_window_size, &max_window_size);
   min_window_size = delegate_->DIPToScreenSize(min_window_size);
   max_window_size = delegate_->DIPToScreenSize(max_window_size);
+  // Add the native frame border size to the minimum and maximum size if the
+  // view reports its size as the client size.
+  if (delegate_->WidgetSizeIsClientSize()) {
+    RECT client_rect, rect;
+    GetClientRect(hwnd(), &client_rect);
+    GetWindowRect(hwnd(), &rect);
+    CR_DEFLATE_RECT(&rect, &client_rect);
+    min_window_size.Enlarge(rect.right - rect.left,
+                            rect.bottom - rect.top);
+    // Either axis may be zero, so enlarge them independently.
+    if (max_window_size.width())
+      max_window_size.Enlarge(rect.right - rect.left, 0);
+    if (max_window_size.height())
+      max_window_size.Enlarge(0, rect.bottom - rect.top);
+  }
 
   std::optional<gfx::Size> max_size_param;
   if (!max_window_size.IsEmpty())
     max_size_param = max_window_size;
 
-  gfx::SizeRectToAspectRatioWithExcludedMargin(
+  gfx::SizeRectToAspectRatio(
       GetWindowResizeEdge(param), aspect_ratio_.value(), min_window_size,
-      max_size_param, excluded_margin_, *window_rect);
+      max_size_param, window_rect);
 }
 
 POINT HWNDMessageHandler::GetCursorPos() const {
