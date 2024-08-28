$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_store/password_store_built_in_backend.cc.orig	2024-08-21 22:46:15.752164100 +0000
+++ components/password_manager/core/browser/password_store/password_store_built_in_backend.cc
@@ -211,7 +211,7 @@ void PasswordStoreBuiltInBackend::InitBa
           std::move(clearing_undecryptable_passwords_cb)));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   background_task_runner_->PostTask(
       FROM_HERE,
       base::BindOnce(&LoginDatabaseAsyncHelper::
