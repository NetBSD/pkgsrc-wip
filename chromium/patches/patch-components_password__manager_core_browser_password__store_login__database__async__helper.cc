$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_store/login_database_async_helper.cc.orig	2024-07-24 02:44:34.604584700 +0000
+++ components/password_manager/core/browser/password_store/login_database_async_helper.cc
@@ -149,7 +149,7 @@ LoginsResultOrError LoginDatabaseAsyncHe
     std::vector<PasswordForm> matched_forms;
     if (!login_db_ ||
         !login_db_->GetLogins(form, include_psl, &matched_forms)) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return PasswordStoreBackendError(
           OSCrypt::IsEncryptionAvailable()
               ? PasswordStoreBackendErrorType::kUncategorized
