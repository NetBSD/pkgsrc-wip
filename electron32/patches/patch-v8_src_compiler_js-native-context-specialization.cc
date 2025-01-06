$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/compiler/js-native-context-specialization.cc.orig	2024-10-18 12:48:35.248422600 +0000
+++ v8/src/compiler/js-native-context-specialization.cc
@@ -880,7 +880,9 @@ JSNativeContextSpecialization::InferHasI
       // might be a different object each time, so it's much simpler to include
       // {prototype}. That does, however, mean that we must check {prototype}'s
       // map stability.
-      if (!prototype.map(broker()).is_stable()) return kMayBeInPrototypeChain;
+      if (!prototype.IsJSObject() || !prototype.map(broker()).is_stable()) {
+        return kMayBeInPrototypeChain;
+      }
       last_prototype = prototype.AsJSObject();
     }
     WhereToStart start = result == NodeProperties::kUnreliableMaps
