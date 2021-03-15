$NetBSD$

--- src/3rdparty/chromium/content/browser/scheduler/responsiveness/native_event_observer.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/browser/scheduler/responsiveness/native_event_observer.cc
@@ -15,7 +15,7 @@
 
 #include "ui/events/platform/platform_event_source.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/aura/env.h"
 #include "ui/events/event.h"
 #endif
@@ -39,7 +39,7 @@ NativeEventObserver::~NativeEventObserve
   DeregisterObserver();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void NativeEventObserver::RegisterObserver() {
   aura::Env::GetInstance()->AddWindowEventDispatcherObserver(this);
 }
