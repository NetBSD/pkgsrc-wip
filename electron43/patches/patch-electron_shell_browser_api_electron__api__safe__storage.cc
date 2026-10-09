$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/api/electron_api_safe_storage.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/api/electron_api_safe_storage.cc
@@ -70,7 +70,7 @@ gin::ObjectTemplateBuilder SafeStorage::
       .SetMethod("decryptString", &SafeStorage::DecryptString)
       .SetMethod("encryptStringAsync", &SafeStorage::encryptStringAsync)
       .SetMethod("decryptStringAsync", &SafeStorage::decryptStringAsync)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       .SetMethod("getSelectedStorageBackend",
                  &SafeStorage::GetSelectedLinuxBackend)
 #endif
@@ -148,7 +148,7 @@ const char* SafeStorage::GetTypeName() {
 bool SafeStorage::IsEncryptionAvailable() {
   if (!electron::Browser::Get()->is_ready())
     return false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return OSCrypt::IsEncryptionAvailable() ||
          (use_password_v10_ &&
           static_cast<BrowserProcessImpl*>(g_browser_process)
@@ -168,7 +168,7 @@ v8::Local<v8::Promise> SafeStorage::IsAs
     return handle;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (use_password_v10_ && static_cast<BrowserProcessImpl*>(g_browser_process)
                                    ->linux_storage_backend() == "basic_text") {
     promise.Resolve(true);
@@ -191,7 +191,7 @@ void SafeStorage::SetUsePasswordV10(bool
   use_password_v10_ = use;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string SafeStorage::GetSelectedLinuxBackend() {
   if (!electron::Browser::Get()->is_ready())
     return "unknown";
