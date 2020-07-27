$NetBSD$

--- chrome/browser/password_manager/password_store_factory.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/password_manager/password_store_factory.cc
@@ -193,7 +193,7 @@ PasswordStoreFactory::BuildServiceInstan
                         base::TimeDelta::FromSeconds(20));
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
   std::unique_ptr<password_manager::PasswordStoreSigninNotifier> notifier =
       std::make_unique<password_manager::PasswordStoreSigninNotifierImpl>(
           IdentityManagerFactory::GetForProfile(profile));
