$NetBSD$

error: expected identifier before numeric constant Success,


--- Source/bmalloc/bmalloc/EligibilityResultInlines.h.orig	2025-05-16 15:56:41.704679027 +0000
+++ Source/bmalloc/bmalloc/EligibilityResultInlines.h
@@ -41,7 +41,7 @@ EligibilityResult<Config>::EligibilityRe
 
 template<typename Config>
 EligibilityResult<Config>::EligibilityResult(IsoPage<Config>* page)
-    : kind(EligibilityKind::Success)
+    : kind(EligibilityKind::BmSuccess)
     , page(page)
 {
 }
