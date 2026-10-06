$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLCodeSignature.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLCodeSignature.m
@@ -10,8 +10,8 @@
 
 #import "EXTKeyPathCoding.h"
 #import "EXTScope.h"
-#import <ReactiveCocoa/RACSignal+Operations.h>
-#import <ReactiveCocoa/RACSubscriber.h>
+#import <ReactiveObjC/RACSignal+Operations.h>
+#import <ReactiveObjC/RACSubscriber.h>
 #import <Security/Security.h>
 
 NSString * const SQRLCodeSignatureErrorDomain = @"SQRLCodeSignatureErrorDomain";
@@ -124,7 +124,7 @@ const NSInteger SQRLCodeSignatureErrorCo
 		}
 		
 		CFErrorRef validityError = NULL;
-		result = SecStaticCodeCheckValidityWithErrors(staticCode, kSecCSCheckAllArchitectures, (__bridge SecRequirementRef)self.requirement, &validityError);
+		result = SecStaticCodeCheckValidityWithErrors(staticCode, kSecCSCheckNestedCode | kSecCSStrictValidate | kSecCSCheckAllArchitectures, (__bridge SecRequirementRef)self.requirement, &validityError);
 		@onExit {
 			if (validityError != NULL) CFRelease(validityError);
 		};
