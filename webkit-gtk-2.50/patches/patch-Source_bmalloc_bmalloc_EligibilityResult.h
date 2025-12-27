$NetBSD$

error: expected identifier Success

--- Source/bmalloc/bmalloc/EligibilityResult.h.orig	2025-05-17 12:08:50.761060597 +0000
+++ Source/bmalloc/bmalloc/EligibilityResult.h
@@ -39,7 +39,7 @@
 namespace bmalloc {
 
 enum class EligibilityKind {
-    Success,
+    BmSuccess,
     Full,
     OutOfMemory
 };
@@ -51,7 +51,7 @@ struct EligibilityResult {
     EligibilityResult(EligibilityKind);
     EligibilityResult(IsoPage<Config>*);
     
-    EligibilityKind kind { EligibilityKind::Success };
+    EligibilityKind kind { EligibilityKind::BmSuccess };
     IsoPage<Config>* page { nullptr };
 };
 
