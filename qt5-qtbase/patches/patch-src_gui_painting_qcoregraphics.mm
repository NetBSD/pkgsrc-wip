$NetBSD$

Use newer API.

--- src/gui/painting/qcoregraphics.mm.orig	2017-07-17 13:04:39.000000000 +0000
+++ src/gui/painting/qcoregraphics.mm
@@ -78,9 +78,9 @@ OSStatus qt_mac_drawCGImage(CGContextRef
     OSStatus err = noErr;
 
 #ifdef Q_OS_MACOS
-    require_action(inContext != NULL, InvalidContext, err = paramErr);
-    require_action(inBounds != NULL, InvalidBounds, err = paramErr);
-    require_action(inImage != NULL, InvalidImage, err = paramErr);
+    __Require_Action(inContext != NULL, InvalidContext, err = paramErr);
+    __Require_Action(inBounds != NULL, InvalidBounds, err = paramErr);
+    __Require_Action(inImage != NULL, InvalidImage, err = paramErr);
 #endif
 
     CGContextSaveGState( inContext );
