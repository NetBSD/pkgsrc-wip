$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/compiler/access-info.cc.orig	2024-10-18 12:48:35.208423000 +0000
+++ v8/src/compiler/access-info.cc
@@ -924,6 +924,7 @@ PropertyAccessInfo AccessInfoFactory::Co
       return PropertyAccessInfo::NotFound(zone(), receiver_map, holder);
     }
 
+    CHECK(prototype.IsJSObject());
     holder = prototype.AsJSObject();
     map = map_prototype_map;
 
