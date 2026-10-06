$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/crypto/crypto_keys.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/crypto/crypto_keys.cc
@@ -1239,6 +1239,7 @@ void KeyObjectHandle::GetAsymmetricKeyTy
 }
 
 bool KeyObjectHandle::CheckEcKeyData() const {
+#ifndef OPENSSL_IS_BORINGSSL
   MarkPopErrorOnReturn mark_pop_error_on_return;
 
   const ManagedEVPPKey& key = data_->GetAsymmetricKey();
@@ -1257,6 +1258,9 @@ bool KeyObjectHandle::CheckEcKeyData() c
 #else
   return EVP_PKEY_public_check(ctx.get()) == 1;
 #endif
+#else
+  return true;
+#endif
 }
 
 void KeyObjectHandle::CheckEcKeyData(const FunctionCallbackInfo<Value>& args) {
