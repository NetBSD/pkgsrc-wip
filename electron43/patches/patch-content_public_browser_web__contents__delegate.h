$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/web_contents_delegate.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/web_contents_delegate.h
@@ -18,6 +18,7 @@
 #include "base/types/expected.h"
 #include "build/build_config.h"
 #include "content/common/content_export.h"
+#include "content/common/frame.mojom.h"
 #include "content/public/browser/back_forward_transition_animation_manager.h"
 #include "content/public/browser/eye_dropper.h"
 #include "content/public/browser/fullscreen_types.h"
@@ -346,8 +347,7 @@ class CONTENT_EXPORT WebContentsDelegate
       SiteInstance* source_site_instance,
       mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url);
+      const mojom::CreateNewWindowParams& params);
 
   // Allow delegate to creates a custom WebContents when
   // WebContents::CreateNewWindow() is called. This function is only called
@@ -368,6 +368,13 @@ class CONTENT_EXPORT WebContentsDelegate
       const StoragePartitionConfig& partition_config,
       SessionStorageNamespace* session_storage_namespace);
 
+  virtual void WebContentsCreatedWithFullParams(
+      WebContents* source_contents,
+      int opener_render_process_id,
+      int opener_render_frame_id,
+      const mojom::CreateNewWindowParams& params,
+      WebContents* new_contents);
+
   // Notifies the delegate about the creation of a new WebContents. This
   // typically happens when popups are created.
   virtual void WebContentsCreated(WebContents* source_contents,
