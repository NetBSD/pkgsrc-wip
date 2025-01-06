$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/password_manager/core/browser/password_store/login_database_unittest.cc.orig	2024-10-18 12:34:07.242155800 +0000
+++ components/password_manager/core/browser/password_store/login_database_unittest.cc
@@ -2207,7 +2207,7 @@ INSTANTIATE_TEST_SUITE_P(MigrationToVCur
                                           testing::Bool()));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 class LoginDatabaseUndecryptableLoginsTest : public testing::Test {
  protected:
   LoginDatabaseUndecryptableLoginsTest() = default;
