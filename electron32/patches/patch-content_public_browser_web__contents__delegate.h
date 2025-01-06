$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/web_contents_delegate.h.orig	2024-10-18 12:34:14.438371400 +0000
+++ content/public/browser/web_contents_delegate.h
@@ -17,6 +17,7 @@
 #include "base/memory/scoped_refptr.h"
 #include "build/build_config.h"
 #include "content/common/content_export.h"
+#include "content/common/frame.mojom.h"
 #include "content/public/browser/eye_dropper.h"
 #include "content/public/browser/fullscreen_types.h"
 #include "content/public/browser/invalidate_type.h"
@@ -336,8 +337,7 @@ class CONTENT_EXPORT WebContentsDelegate
       SiteInstance* source_site_instance,
       mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url);
+      const mojom::CreateNewWindowParams& params);
 
   // Allow delegate to creates a custom WebContents when
   // WebContents::CreateNewWindow() is called. This function is only called
@@ -358,6 +358,13 @@ class CONTENT_EXPORT WebContentsDelegate
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
