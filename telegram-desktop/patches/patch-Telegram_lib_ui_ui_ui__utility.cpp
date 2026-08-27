$NetBSD$

On X11, Qt6 synthesizes pixelDelta from angleDelta with unreliable
scaling, causing one mouse wheel notch to scroll multiple screens.
Upstream 7.1.x switched the check to the device PixelScroll
capability, which Qt may set for X11 mice; keep pixelDelta restricted
to Wayland or touch input so X11 mouse wheel events fall through to
angleDelta, which normalizes to 120 per notch.

--- Telegram/lib_ui/ui/ui_utility.cpp.orig	2026-08-27 22:25:26.248389791 +0300
+++ Telegram/lib_ui/ui/ui_utility.cpp	2026-08-27 22:26:08.876430172 +0300
@@ -274,7 +274,9 @@
 	};
 #if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)
 	using QInputDevice::Capability::PixelScroll;
-	if (touch || e->device()->capabilities().testFlag(PixelScroll)) {
+	if (touch
+		|| (e->device()->capabilities().testFlag(PixelScroll)
+			&& ::Platform::IsWayland())) {
 #else // Qt >= 6.2.0
 	if (!e->pixelDelta().isNull()) {
 #endif // Qt < 6.2.0
