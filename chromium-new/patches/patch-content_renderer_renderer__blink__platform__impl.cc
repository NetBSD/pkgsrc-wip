$NetBSD$

--- content/renderer/renderer_blink_platform_impl.cc.orig	2016-06-24 01:02:21.000000000 +0000
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -116,7 +116,7 @@
 
 #if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 #include <map>
 #include <string>
 
@@ -207,7 +207,7 @@ class RendererBlinkPlatformImpl::FileUti
   scoped_refptr<ThreadSafeSender> thread_safe_sender_;
 };
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 class RendererBlinkPlatformImpl::SandboxSupport
     : public blink::WebSandboxSupport {
  public:
@@ -253,7 +253,7 @@ RendererBlinkPlatformImpl::RendererBlink
       web_scrollbar_behavior_(new WebScrollbarBehaviorImpl),
       renderer_scheduler_(renderer_scheduler),
       blink_service_registry_(new BlinkServiceRegistryImpl(service_registry)) {
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FREEBSD) && !defined(OS_NETBSD)
   if (g_sandbox_enabled && sandboxEnabled()) {
     sandbox_support_.reset(new RendererBlinkPlatformImpl::SandboxSupport);
   } else {
@@ -284,7 +284,7 @@ RendererBlinkPlatformImpl::~RendererBlin
 }
 
 void RendererBlinkPlatformImpl::Shutdown() {
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_FREEBSD) && !defined(OS_NETBSD)
   // SandboxSupport contains a map of WebFontFamily objects, which hold
   // WebCStrings, which become invalidated when blink is shut down. Hence, we
   // need to clear that map now, just before blink::shutdown() is called.
@@ -334,7 +334,7 @@ blink::WebFileUtilities* RendererBlinkPl
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::sandboxSupport() {
-#if defined(OS_ANDROID) || defined(OS_WIN)
+#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_FREEBSD) || defined(OS_NETBSD)
   // These platforms do not require sandbox support.
   return NULL;
 #else
@@ -562,7 +562,7 @@ bool RendererBlinkPlatformImpl::SandboxS
   return FontLoader::CGFontRefFromBuffer(font_data, font_data_size, out);
 }
 
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 
 void RendererBlinkPlatformImpl::SandboxSupport::getFallbackFontForCharacter(
     blink::WebUChar32 character,
