$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/password_store/login_database.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ components/password_manager/core/browser/password_store/login_database.cc
@@ -1030,7 +1030,7 @@ bool ShouldDeleteUndecryptablePasswords(
     bool is_user_data_dir_policy_set,
     bool is_enabled_by_policy,
     IsAccountStore is_account_store) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> environment(base::Environment::Create());
   // On Linux user data directory ca be specified using an env variable. If it
   // exists, passwords shouldn't be deleted.
@@ -1048,7 +1048,7 @@ bool ShouldDeleteUndecryptablePasswords(
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch(password_manager::kPasswordStore)) {
     RecordShouldDeleteUndecryptablePasswordsMetric(
         ShouldDeleteUndecryptablePasswordsResult::
