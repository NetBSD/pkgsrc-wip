$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/vendor/Mantle/Mantle/Mantle.h.orig	2016-02-15 11:44:36.000000000 +0000
+++ third_party/squirrel.mac/vendor/Mantle/Mantle/Mantle.h
@@ -15,7 +15,6 @@ FOUNDATION_EXPORT double MantleVersionNu
 FOUNDATION_EXPORT const unsigned char MantleVersionString[];
 
 #import <Mantle/MTLJSONAdapter.h>
-#import <Mantle/MTLManagedObjectAdapter.h>
 #import <Mantle/MTLModel.h>
 #import <Mantle/MTLModel+NSCoding.h>
 #import <Mantle/MTLValueTransformer.h>
