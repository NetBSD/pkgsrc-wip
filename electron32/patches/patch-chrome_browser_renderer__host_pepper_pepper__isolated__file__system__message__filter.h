$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/renderer_host/pepper/pepper_isolated_file_system_message_filter.h.orig	2024-10-18 12:34:01.929061700 +0000
+++ chrome/browser/renderer_host/pepper/pepper_isolated_file_system_message_filter.h
@@ -20,7 +20,9 @@
 #include "storage/browser/file_system/isolated_context.h"
 #include "url/gurl.h"
 
+#if 0
 class Profile;
+#endif
 
 namespace content {
 class BrowserPpapiHost;
@@ -59,6 +61,7 @@ class PepperIsolatedFileSystemMessageFil
 
   ~PepperIsolatedFileSystemMessageFilter() override;
 
+#if 0
   Profile* GetProfile();
 
   // Returns filesystem id of isolated filesystem if valid, or empty string
@@ -66,18 +69,23 @@ class PepperIsolatedFileSystemMessageFil
   // allows access on that thread.
   storage::IsolatedContext::ScopedFSHandle CreateCrxFileSystem(
       Profile* profile);
+#endif
 
   int32_t OnOpenFileSystem(ppapi::host::HostMessageContext* context,
                            PP_IsolatedFileSystemType_Private type);
+#if 0
   int32_t OpenCrxFileSystem(ppapi::host::HostMessageContext* context);
 
   const int render_process_id_;
+#endif
   // Keep a copy from original thread.
   const base::FilePath profile_directory_;
   const GURL document_url_;
 
+#if 0
   // Set of origins that can use CrxFs private APIs from NaCl.
   std::set<std::string> allowed_crxfs_origins_;
+#endif
 };
 
 #endif  // CHROME_BROWSER_RENDERER_HOST_PEPPER_PEPPER_ISOLATED_FILE_SYSTEM_MESSAGE_FILTER_H_
