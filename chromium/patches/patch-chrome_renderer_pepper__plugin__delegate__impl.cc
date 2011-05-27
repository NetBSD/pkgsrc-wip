$NetBSD: patch-chrome_renderer_pepper__plugin__delegate__impl.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/renderer/pepper_plugin_delegate_impl.cc.orig	2011-05-24 08:01:44.000000000 +0000
+++ chrome/renderer/pepper_plugin_delegate_impl.cc
@@ -54,7 +54,7 @@
 #include "webkit/plugins/ppapi/ppb_flash_impl.h"
 #include "webkit/plugins/ppapi/ppb_flash_net_connector_impl.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include "chrome/renderer/render_thread.h"
 #endif
 
@@ -81,7 +81,7 @@ class PlatformImage2DImpl
         dib_(dib) {
   }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // On Mac, we have to tell the browser to free the transport DIB.
   virtual ~PlatformImage2DImpl() {
     if (dib_.get()) {
@@ -99,7 +99,7 @@ class PlatformImage2DImpl
     *byte_count = dib_->size();
 #if defined(OS_WIN)
     return reinterpret_cast<intptr_t>(dib_->handle());
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
     return static_cast<intptr_t>(dib_->handle().fd);
 #elif defined(OS_LINUX)
     return static_cast<intptr_t>(dib_->handle());
@@ -499,7 +499,7 @@ PepperPluginDelegateImpl::CreateImage2D(
   uint32 buffer_size = width * height * 4;
 
   // Allocate the transport DIB and the PlatformCanvas pointing to it.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // On the Mac, shared memory has to be created in the browser in order to
   // work in the sandbox.  Do this by sending a message to the browser
   // requesting a TransportDIB (see also
