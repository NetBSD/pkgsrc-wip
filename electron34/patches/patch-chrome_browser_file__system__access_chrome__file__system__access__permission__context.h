$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.h
@@ -21,7 +21,7 @@
 #include "chrome/browser/file_system_access/file_system_access_permission_request_manager.h"
 #include "chrome/browser/permissions/one_time_permissions_tracker.h"
 #include "chrome/browser/permissions/one_time_permissions_tracker_observer.h"
-#include "components/enterprise/buildflags/buildflags.h"
+#include "chrome/common/chrome_paths.h"
 #include "components/permissions/features.h"
 #include "components/permissions/object_permission_context_base.h"
 #include "content/public/browser/file_system_access_permission_context.h"
@@ -31,7 +31,7 @@
 #include "chrome/browser/web_applications/web_app_install_manager_observer.h"
 #endif
 
-#if BUILDFLAG(ENTERPRISE_CLOUD_CONTENT_ANALYSIS)
+#if 0
 #include "components/enterprise/common/files_scan_data.h"
 #endif
 
@@ -340,6 +340,129 @@ class ChromeFileSystemAccessPermissionCo
   // KeyedService:
   void Shutdown() override;
 
+  // Sentinel used to indicate that no PathService key is specified for a path in
+  // the struct below.
+  static constexpr const int kNoBasePathKey = -1;
+
+  enum BlockType {
+    kBlockAllChildren,
+    kBlockNestedDirectories,
+    kDontBlockChildren
+  };
+
+  static constexpr struct {
+    // base::BasePathKey value (or one of the platform specific extensions to it)
+    // for a path that should be blocked. Specify kNoBasePathKey if |path| should
+    // be used instead.
+    int base_path_key;
+
+    // Explicit path to block instead of using |base_path_key|. Set to nullptr to
+    // use |base_path_key| on its own. If both |base_path_key| and |path| are set,
+    // |path| is treated relative to the path |base_path_key| resolves to.
+    const base::FilePath::CharType* path;
+
+    // If this is set to kDontBlockChildren, only the given path and its parents
+    // are blocked. If this is set to kBlockAllChildren, all children of the given
+    // path are blocked as well. Finally if this is set to kBlockNestedDirectories
+    // access is allowed to individual files in the directory, but nested
+    // directories are still blocked.
+    // The BlockType of the nearest ancestor of a path to check is what ultimately
+    // determines if a path is blocked or not. If a blocked path is a descendent
+    // of another blocked path, then it may override the child-blocking policy of
+    // its ancestor. For example, if /home blocks all children, but
+    // /home/downloads does not, then /home/downloads/file.ext will *not* be
+    // blocked.
+    BlockType type;
+  } kBlockedPaths[] = {
+      // Don't allow users to share their entire home directory, entire desktop or
+      // entire documents folder, but do allow sharing anything inside those
+      // directories not otherwise blocked.
+      {base::DIR_HOME, nullptr, kDontBlockChildren},
+      {base::DIR_USER_DESKTOP, nullptr, kDontBlockChildren},
+      {chrome::DIR_USER_DOCUMENTS, nullptr, kDontBlockChildren},
+      // Similar restrictions for the downloads directory.
+      {chrome::DIR_DEFAULT_DOWNLOADS, nullptr, kDontBlockChildren},
+      {chrome::DIR_DEFAULT_DOWNLOADS_SAFE, nullptr, kDontBlockChildren},
+      // The Chrome installation itself should not be modified by the web.
+      {base::DIR_EXE, nullptr, kBlockAllChildren},
+      {base::DIR_MODULE, nullptr, kBlockAllChildren},
+      {base::DIR_ASSETS, nullptr, kBlockAllChildren},
+      // And neither should the configuration of at least the currently running
+      // Chrome instance (note that this does not take --user-data-dir command
+      // line overrides into account).
+      {chrome::DIR_USER_DATA, nullptr, kBlockAllChildren},
+      // ~/.ssh is pretty sensitive on all platforms, so block access to that.
+      {base::DIR_HOME, FILE_PATH_LITERAL(".ssh"), kBlockAllChildren},
+      // And limit access to ~/.gnupg as well.
+      {base::DIR_HOME, FILE_PATH_LITERAL(".gnupg"), kBlockAllChildren},
+  #if BUILDFLAG(IS_WIN)
+      // Some Windows specific directories to block, basically all apps, the
+      // operating system itself, as well as configuration data for apps.
+      {base::DIR_PROGRAM_FILES, nullptr, kBlockAllChildren},
+      {base::DIR_PROGRAM_FILESX86, nullptr, kBlockAllChildren},
+      {base::DIR_PROGRAM_FILES6432, nullptr, kBlockAllChildren},
+      {base::DIR_WINDOWS, nullptr, kBlockAllChildren},
+      {base::DIR_ROAMING_APP_DATA, nullptr, kBlockAllChildren},
+      {base::DIR_LOCAL_APP_DATA, nullptr, kBlockAllChildren},
+      {base::DIR_COMMON_APP_DATA, nullptr, kBlockAllChildren},
+      // Opening a file from an MTP device, such as a smartphone or a camera, is
+      // implemented by Windows as opening a file in the temporary internet files
+      // directory. To support that, allow opening files in that directory, but
+      // not whole directories.
+      {base::DIR_IE_INTERNET_CACHE, nullptr, kBlockNestedDirectories},
+  #endif
+  #if BUILDFLAG(IS_MAC)
+      // Similar Mac specific blocks.
+      {base::DIR_APP_DATA, nullptr, kBlockAllChildren},
+      // Block access to the current bundle directory.
+      {chrome::DIR_OUTER_BUNDLE, nullptr, kBlockAllChildren},
+      // Block access to the user's Applications directory.
+      {base::DIR_HOME, FILE_PATH_LITERAL("Applications"), kBlockAllChildren},
+      // Block access to the root Applications directory.
+      {kNoBasePathKey, FILE_PATH_LITERAL("/Applications"), kBlockAllChildren},
+      {base::DIR_HOME, FILE_PATH_LITERAL("Library"), kBlockAllChildren},
+      // Allow access to other cloud files, such as Google Drive.
+      {base::DIR_HOME, FILE_PATH_LITERAL("Library/CloudStorage"),
+       kDontBlockChildren},
+      // Allow the site to interact with data from its corresponding natively
+      // installed (sandboxed) application. It would be nice to limit a site to
+      // access only _its_ corresponding natively installed application,
+      // but unfortunately there's no straightforward way to do that. See
+      // https://crbug.com/984641#c22.
+      {base::DIR_HOME, FILE_PATH_LITERAL("Library/Containers"),
+       kDontBlockChildren},
+      // Allow access to iCloud files...
+      {base::DIR_HOME, FILE_PATH_LITERAL("Library/Mobile Documents"),
+       kDontBlockChildren},
+      // ... which may also appear at this directory.
+      {base::DIR_HOME,
+       FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
+       kDontBlockChildren},
+  #endif
+  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
+      // On Linux also block access to devices via /dev.
+      {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), kBlockAllChildren},
+      // And security sensitive data in /proc and /sys.
+      {kNoBasePathKey, FILE_PATH_LITERAL("/proc"), kBlockAllChildren},
+      {kNoBasePathKey, FILE_PATH_LITERAL("/sys"), kBlockAllChildren},
+      // And system files in /boot and /etc.
+      {kNoBasePathKey, FILE_PATH_LITERAL("/boot"), kBlockAllChildren},
+      {kNoBasePathKey, FILE_PATH_LITERAL("@PKG_SYSCONFBASE@"), kBlockAllChildren},
+      // And block all of ~/.config, matching the similar restrictions on mac
+      // and windows.
+      {base::DIR_HOME, FILE_PATH_LITERAL(".config"), kBlockAllChildren},
+      // Block ~/.dbus as well, just in case, although there probably isn't much a
+      // website can do with access to that directory and its contents.
+      {base::DIR_HOME, FILE_PATH_LITERAL(".dbus"), kBlockAllChildren},
+  #endif
+  #if BUILDFLAG(IS_ANDROID)
+      {base::DIR_ANDROID_APP_DATA, nullptr, kBlockAllChildren},
+      {base::DIR_CACHE, nullptr, kBlockAllChildren},
+  #endif
+      // TODO(crbug.com/40095723): Refine this list, for example add
+      // XDG_CONFIG_HOME when it is not set ~/.config?
+  };
+
  protected:
   SEQUENCE_CHECKER(sequence_checker_);
 
@@ -359,7 +482,7 @@ class ChromeFileSystemAccessPermissionCo
 
   void PermissionGrantDestroyed(PermissionGrantImpl* grant);
 
-#if BUILDFLAG(ENTERPRISE_CLOUD_CONTENT_ANALYSIS)
+#if 0
   void OnContentAnalysisComplete(
       std::vector<content::PathInfo> entries,
       EntriesAllowedByEnterprisePolicyCallback callback,
