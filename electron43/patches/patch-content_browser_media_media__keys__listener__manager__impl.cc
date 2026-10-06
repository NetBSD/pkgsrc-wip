$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -88,7 +88,11 @@ bool MediaKeysListenerManagerImpl::Start
       CanActiveMediaSessionControllerReceiveEvents();
 
   // Tell the underlying MediaKeysListener to listen for the key.
-  if (should_start_watching && media_keys_listener_ &&
+  if (
+#if BUILDFLAG(IS_MAC)
+      !media_key_handling_enabled_ &&
+#endif  // BUILDFLAG(IS_MAC)
+      should_start_watching && media_keys_listener_ &&
       !media_keys_listener_->StartWatchingMediaKey(key_code)) {
     return false;
   }
@@ -333,7 +337,7 @@ void MediaKeysListenerManagerImpl::Start
     return;
   }
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) || BUILDFLAG(IS_WIN)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
       system_media_controls::SystemMediaControls::Create(
@@ -362,6 +366,20 @@ void MediaKeysListenerManagerImpl::Start
         this, ui::MediaKeysListener::Scope::kGlobal);
     DCHECK(media_keys_listener_);
   }
+
+#if BUILDFLAG(IS_MAC)
+  // Chromium's implementation of SystemMediaControls falls
+  // down into MPRemoteCommandCenter, which makes it such that an app will not
+  // will not receive remote control events until it begins playing audio.
+  // If there's not already a MediaKeysListener instance, create one so
+  // that globalShortcuts work correctly.
+  if (!media_keys_listener_) {
+    media_keys_listener_ = ui::MediaKeysListener::Create(
+        this, ui::MediaKeysListener::Scope::kGlobal);
+    DCHECK(media_keys_listener_);
+  }
+#endif
+
   EnsureAuxiliaryServices();
 }
 
@@ -413,6 +431,11 @@ void MediaKeysListenerManagerImpl::Updat
         case ui::VKEY_MEDIA_STOP:
           browser_system_media_controls_->SetIsStopEnabled(should_enable);
           break;
+        case ui::VKEY_VOLUME_DOWN:
+        case ui::VKEY_VOLUME_UP:
+        case ui::VKEY_VOLUME_MUTE:
+          // Do nothing.
+          break;
         default:
           NOTREACHED();
       }
@@ -455,6 +478,11 @@ void MediaKeysListenerManagerImpl::Updat
         case ui::VKEY_MEDIA_STOP:
           smc->SetIsStopEnabled(should_enable);
           break;
+        case ui::VKEY_VOLUME_DOWN:
+        case ui::VKEY_VOLUME_UP:
+        case ui::VKEY_VOLUME_MUTE:
+          // Do nothing.
+          break;
         default:
           NOTREACHED();
       }
