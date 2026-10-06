$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/unrar/src/rijndael.cpp.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/unrar/src/rijndael.cpp
@@ -116,7 +116,7 @@ void Rijndael::Init(bool Encrypt,const b
 #endif
 
 #elif defined(USE_NEON_AES)
-  #ifdef _APPLE
+  #if defined(_APPLE)
     // getauxval isn't available in OS X
     uint Value=0;
     size_t Size=sizeof(Value);
@@ -126,6 +126,12 @@ void Rijndael::Init(bool Encrypt,const b
     // because "hw.optional.arm.FEAT_AES" was missing in OS X 11, but AES
     // still was supported by Neon.
     AES_Neon=RetCode!=0 || Value!=0;
+  #elif defined(__FreeBSD__)
+    // getauxval isn't available on FreeBSD
+    uint64 Reg=READ_SPECIALREG(id_aa64isar0_el1);
+    if (ID_AA64ISAR0_AES_VAL(Reg) == ID_AA64ISAR0_AES_BASE) {
+      AES_Neon=true;
+    }
   #else
     AES_Neon=(getauxval(AT_HWCAP) & HWCAP_AES)!=0;
   #endif
