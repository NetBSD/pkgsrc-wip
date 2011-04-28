$NetBSD: patch-chrome_renderer_pepper__devices.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/pepper_devices.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/pepper_devices.cc
@@ -52,7 +52,7 @@ NPError Graphics2DDeviceContext::Initial
   uint32 buffer_size = width * height * kBytesPerPixel;
 
   // Allocate the transport DIB and the PlatformCanvas pointing to it.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // On the Mac, shared memory has to be created in the browser in order to
   // work in the sandbox.  Do this by sending a message to the browser
   // requesting a TransportDIB (see also
