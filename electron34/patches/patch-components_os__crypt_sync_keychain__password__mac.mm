$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/os_crypt/sync/keychain_password_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/os_crypt/sync/keychain_password_mac.mm
@@ -13,6 +13,7 @@
 #include "base/rand_util.h"
 #include "build/branding_buildflags.h"
 #include "crypto/apple_keychain.h"
+#include "electron/mas.h"
 
 using crypto::AppleKeychain;
 
@@ -22,6 +23,12 @@ using KeychainNameContainerType = base::
 using KeychainNameContainerType = const base::NoDestructor<std::string>;
 #endif
 
+#if IS_MAS_BUILD()
+const char kAccountNameSuffix[] = " App Store Key";
+#else
+const char kAccountNameSuffix[] = " Key";
+#endif
+
 namespace {
 
 // These two strings ARE indeed user facing.  But they are used to access
@@ -81,11 +88,18 @@ KeychainPassword::~KeychainPassword() = 
 std::string KeychainPassword::GetPassword() const {
   UInt32 password_length = 0;
   void* password_data = nullptr;
+  KeychainPassword::KeychainNameType service_name = GetServiceName();
+  KeychainPassword::KeychainNameType account_name = GetAccountName();
+  const std::string account_name_suffix = kAccountNameSuffix;
+  const std::string suffixed_account_name = account_name + account_name_suffix;
+
+  // We should check if the suffixed account exists first
   OSStatus error = keychain_->FindGenericPassword(
-      GetServiceName().size(), GetServiceName().c_str(),
-      GetAccountName().size(), GetAccountName().c_str(), &password_length,
+      service_name.size(), service_name.c_str(),
+      suffixed_account_name.size(), suffixed_account_name.c_str(), &password_length,
       &password_data, /*item=*/nullptr);
 
+  // If it exists we can return it immediately
   if (error == noErr) {
     std::string password =
         std::string(static_cast<char*>(password_data), password_length);
@@ -93,6 +107,49 @@ std::string KeychainPassword::GetPasswor
     return password;
   }
 
+  // If the error was anything other than "it does not exist" we should error out here
+  // This normally means the account exists but we were deniged access to it
+  if (error != errSecItemNotFound) {
+    OSSTATUS_LOG(ERROR, error) << "Keychain lookup for suffixed key failed";
+    return std::string();
+  }
+
+  // If the suffixed account didn't exist, we should check if the legacy non-suffixed account
+  // exists. If it does we can use that key and migrate it to the new account
+  base::apple::ScopedCFTypeRef<SecKeychainItemRef> item_ref;
+  error = keychain_->FindGenericPassword(
+      service_name.size(), service_name.c_str(),
+      account_name.size(), account_name.c_str(), &password_length,
+      &password_data, item_ref.InitializeInto());
+
+  if (error == noErr) {
+    std::string password =
+        std::string(static_cast<char*>(password_data), password_length);
+
+    // If we found the legacy account name we should copy it over to
+    // the new suffixed account
+    error = keychain_->AddGenericPassword(
+        service_name.size(), service_name.data(), suffixed_account_name.size(),
+        suffixed_account_name.data(), password.size(), password_data, NULL);
+
+    if (error == noErr) {
+      // If we successfully made the suffixed account we can delete the old
+      // account to ensure new apps don't try to use it and run into IAM
+      // issues
+      error = keychain_->ItemDelete(item_ref.get());
+      if (error != noErr) {
+        OSSTATUS_DLOG(ERROR, error) << "Keychain delete for legacy key failed";
+      }
+    } else {
+      OSSTATUS_DLOG(ERROR, error) << "Keychain add for suffixed key failed";
+    }
+
+    keychain_->ItemFreeContent(password_data);
+    return password;
+  }
+
+  // If the legacy account name was not found, make a new account in the
+  // with the suffixed name
   if (error == errSecItemNotFound) {
     std::string password = AddRandomPasswordToKeychain(
         *keychain_, GetServiceName(), GetAccountName());
