$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/password_manager/core/browser/password_store/password_store_built_in_backend.cc.orig	2024-10-18 12:34:07.242155800 +0000
+++ components/password_manager/core/browser/password_store/password_store_built_in_backend.cc
@@ -211,7 +211,7 @@ void PasswordStoreBuiltInBackend::InitBa
           std::move(clearing_undecryptable_passwords_cb)));
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   background_task_runner_->PostTask(
       FROM_HERE,
       base::BindOnce(&LoginDatabaseAsyncHelper::
