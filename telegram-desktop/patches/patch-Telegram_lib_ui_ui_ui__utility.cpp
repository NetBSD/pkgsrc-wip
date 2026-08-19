$NetBSD$

On X11, Qt6 synthesizes pixelDelta from angleDelta with unreliable
scaling, causing one mouse wheel notch to scroll multiple screens.
Only use pixelDelta on Wayland or touchpad input; fall through to
angleDelta for mouse wheel events on X11, which normalizes to 120
per notch.

--- Telegram/lib_ui/ui/ui_utility.cpp.orig	2026-08-18 17:00:00.304299587 +0300
+++ Telegram/lib_ui/ui/ui_utility.cpp
@@ -278,7 +278,9 @@
 		&& !touch
 		&& (e->phase() == Qt::NoScrollPhase)
 		&& !e->angleDelta().isNull();
-	if (!ignorePixels && !e->pixelDelta().isNull()) {
+	if (!ignorePixels
+		&& !e->pixelDelta().isNull()
+		&& (::Platform::IsWayland() || touch)) {
 		return convert(e->pixelDelta())
 			* ((::Platform::IsWayland() && !touch)
 				? kMagicScrollMultiplier
