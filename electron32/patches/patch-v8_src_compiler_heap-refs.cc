$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/compiler/heap-refs.cc.orig	2024-10-18 12:48:35.240422700 +0000
+++ v8/src/compiler/heap-refs.cc
@@ -1682,6 +1682,7 @@ HolderLookupResult FunctionTemplateInfoR
   if (!expected_receiver_type->IsTemplateFor(prototype.object()->map())) {
     return not_found;
   }
+  CHECK(prototype.IsJSObject());
   return HolderLookupResult(CallOptimization::kHolderFound,
                             prototype.AsJSObject());
 }
