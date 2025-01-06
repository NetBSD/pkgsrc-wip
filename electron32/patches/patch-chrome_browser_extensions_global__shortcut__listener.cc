$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/extensions/global_shortcut_listener.cc.orig	2024-10-18 12:34:01.581256000 +0000
+++ chrome/browser/extensions/global_shortcut_listener.cc
@@ -8,6 +8,7 @@
 #include "base/not_fatal_until.h"
 #include "base/notreached.h"
 #include "content/public/browser/browser_thread.h"
+#include "content/public/browser/media_keys_listener_manager.h"
 #include "ui/base/accelerators/accelerator.h"
 
 using content::BrowserThread;
@@ -67,6 +68,22 @@ void GlobalShortcutListener::UnregisterA
     StopListening();
 }
 
+// static
+void GlobalShortcutListener::SetShouldUseInternalMediaKeyHandling(bool should_use) {
+  if (content::MediaKeysListenerManager::
+            IsMediaKeysListenerManagerEnabled()) {
+    content::MediaKeysListenerManager* media_keys_listener_manager =
+        content::MediaKeysListenerManager::GetInstance();
+    DCHECK(media_keys_listener_manager);
+
+    if (should_use) {
+      media_keys_listener_manager->EnableInternalMediaKeyHandling();
+    } else {
+      media_keys_listener_manager->DisableInternalMediaKeyHandling();
+    }
+  }
+}
+
 void GlobalShortcutListener::UnregisterAccelerators(Observer* observer) {
   CHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
   if (IsShortcutHandlingSuspended())
