$NetBSD: patch-chrome_renderer_pepper__plugin__delegate__impl.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/renderer/pepper_plugin_delegate_impl.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/renderer/pepper_plugin_delegate_impl.cc
@@ -48,7 +48,7 @@
 #include "webkit/plugins/ppapi/ppapi_plugin_instance.h"
 #include "webkit/plugins/ppapi/ppb_flash_impl.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include "chrome/common/render_messages.h"
 #include "chrome/renderer/render_thread.h"
 #endif
@@ -76,7 +76,7 @@ class PlatformImage2DImpl
         dib_(dib) {
   }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // On Mac, we have to tell the browser to free the transport DIB.
   virtual ~PlatformImage2DImpl() {
     if (dib_.get()) {
@@ -94,7 +94,7 @@ class PlatformImage2DImpl
     *byte_count = dib_->size();
 #if defined(OS_WIN)
     return reinterpret_cast<intptr_t>(dib_->handle());
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
     return static_cast<intptr_t>(dib_->handle().fd);
 #elif defined(OS_LINUX)
     return static_cast<intptr_t>(dib_->handle());
@@ -494,7 +494,7 @@ PepperPluginDelegateImpl::CreateImage2D(
   uint32 buffer_size = width * height * 4;
 
   // Allocate the transport DIB and the PlatformCanvas pointing to it.
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // On the Mac, shared memory has to be created in the browser in order to
   // work in the sandbox.  Do this by sending a message to the browser
   // requesting a TransportDIB (see also
