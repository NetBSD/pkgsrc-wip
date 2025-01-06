$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/renderer_host/pepper/pepper_isolated_file_system_message_filter.cc.orig	2024-10-18 12:34:01.929061700 +0000
+++ chrome/browser/renderer_host/pepper/pepper_isolated_file_system_message_filter.cc
@@ -7,17 +7,21 @@
 #include <stddef.h>
 
 #include "base/task/sequenced_task_runner.h"
+#if 0
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/profiles/profile.h"
 #include "chrome/browser/profiles/profile_manager.h"
 #include "chrome/common/chrome_switches.h"
 #include "chrome/common/pepper_permission_util.h"
+#endif
 #include "content/public/browser/browser_ppapi_host.h"
 #include "content/public/browser/browser_task_traits.h"
 #include "content/public/browser/browser_thread.h"
 #include "content/public/browser/child_process_security_policy.h"
 #include "content/public/browser/render_view_host.h"
+#if 0
 #include "extensions/buildflags/buildflags.h"
+#endif
 #include "ppapi/c/pp_errors.h"
 #include "ppapi/host/dispatch_host_message.h"
 #include "ppapi/host/host_message_context.h"
@@ -26,12 +30,11 @@
 #include "ppapi/shared_impl/file_system_util.h"
 #include "storage/browser/file_system/isolated_context.h"
 
-#if BUILDFLAG(ENABLE_EXTENSIONS)
+#if 0
 #include "extensions/browser/extension_registry.h"
 #include "extensions/common/constants.h"
 #include "extensions/common/extension.h"
 #include "extensions/common/extension_set.h"
-#endif
 
 namespace {
 
@@ -41,6 +44,7 @@ const char* kPredefinedAllowedCrxFsOrigi
 };
 
 }  // namespace
+#endif
 
 // static
 PepperIsolatedFileSystemMessageFilter*
@@ -64,11 +68,16 @@ PepperIsolatedFileSystemMessageFilter::P
     const base::FilePath& profile_directory,
     const GURL& document_url,
     ppapi::host::PpapiHost* ppapi_host)
+#if 0
     : render_process_id_(render_process_id),
       profile_directory_(profile_directory),
       document_url_(document_url) {
   for (size_t i = 0; i < std::size(kPredefinedAllowedCrxFsOrigins); ++i)
     allowed_crxfs_origins_.insert(kPredefinedAllowedCrxFsOrigins[i]);
+#else
+    : profile_directory_(profile_directory),
+      document_url_(document_url) {
+#endif
 }
 
 PepperIsolatedFileSystemMessageFilter::
@@ -93,6 +102,7 @@ int32_t PepperIsolatedFileSystemMessageF
   return PP_ERROR_FAILED;
 }
 
+#if 0
 Profile* PepperIsolatedFileSystemMessageFilter::GetProfile() {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
   ProfileManager* profile_manager = g_browser_process->profile_manager();
@@ -117,6 +127,7 @@ PepperIsolatedFileSystemMessageFilter::C
   return storage::IsolatedContext::ScopedFSHandle();
 #endif
 }
+#endif
 
 int32_t PepperIsolatedFileSystemMessageFilter::OnOpenFileSystem(
     ppapi::host::HostMessageContext* context,
@@ -125,7 +136,7 @@ int32_t PepperIsolatedFileSystemMessageF
     case PP_ISOLATEDFILESYSTEMTYPE_PRIVATE_INVALID:
       break;
     case PP_ISOLATEDFILESYSTEMTYPE_PRIVATE_CRX:
-      return OpenCrxFileSystem(context);
+      return PP_ERROR_NOTSUPPORTED;
   }
   NOTREACHED_IN_MIGRATION();
   context->reply_msg =
@@ -133,6 +144,7 @@ int32_t PepperIsolatedFileSystemMessageF
   return PP_ERROR_FAILED;
 }
 
+#if 0
 int32_t PepperIsolatedFileSystemMessageFilter::OpenCrxFileSystem(
     ppapi::host::HostMessageContext* context) {
 #if BUILDFLAG(ENABLE_EXTENSIONS)
@@ -173,3 +185,4 @@ int32_t PepperIsolatedFileSystemMessageF
   return PP_ERROR_NOTSUPPORTED;
 #endif
 }
+#endif
