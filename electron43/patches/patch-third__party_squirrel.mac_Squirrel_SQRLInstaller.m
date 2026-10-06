$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLInstaller.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLInstaller.m
@@ -9,13 +9,13 @@
 #import "SQRLInstaller.h"
 
 #import <libkern/OSAtomic.h>
-#import "EXTScope.h"
-#import <ReactiveCocoa/NSEnumerator+RACSequenceAdditions.h>
-#import <ReactiveCocoa/NSObject+RACPropertySubscribing.h>
-#import <ReactiveCocoa/RACCommand.h>
-#import <ReactiveCocoa/RACSequence.h>
-#import <ReactiveCocoa/RACSignal+Operations.h>
-#import <ReactiveCocoa/RACSubscriber.h>
+#import <ReactiveObjC/EXTScope.h>
+#import <ReactiveObjC/NSEnumerator+RACSequenceAdditions.h>
+#import <ReactiveObjC/NSObject+RACPropertySubscribing.h>
+#import <ReactiveObjC/RACCommand.h>
+#import <ReactiveObjC/RACSequence.h>
+#import <ReactiveObjC/RACSignal+Operations.h>
+#import <ReactiveObjC/RACSubscriber.h>
 #import <sys/xattr.h>
 
 #import "NSBundle+SQRLVersionExtensions.h"
@@ -36,6 +36,7 @@ const NSInteger SQRLInstallerErrorMissin
 const NSInteger SQRLInstallerErrorInvalidState = -6;
 const NSInteger SQRLInstallerErrorMovingAcrossVolumes = -7;
 const NSInteger SQRLInstallerErrorChangingPermissions = -8;
+const NSInteger SQRLInstallerErrorAppStillRunning = -9;
 
 NSString * const SQRLShipItInstallationAttemptsKey = @"SQRLShipItInstallationAttempts";
 NSString * const SQRLInstallerOwnedBundleKey = @"SQRLInstallerOwnedBundle";
@@ -181,14 +182,40 @@ NSString * const SQRLInstallerOwnedBundl
 	id archiveData = CFBridgingRelease(CFPreferencesCopyValue((__bridge CFStringRef)SQRLInstallerOwnedBundleKey, (__bridge CFStringRef)self.applicationIdentifier, kCFPreferencesCurrentUser, kCFPreferencesCurrentHost));
 	if (![archiveData isKindOfClass:NSData.class]) return nil;
 
-	SQRLInstallerOwnedBundle *ownedBundle = [NSKeyedUnarchiver unarchiveObjectWithData:archiveData];
-	if (![ownedBundle isKindOfClass:SQRLInstallerOwnedBundle.class]) return nil;
+	// unarchivedObjectOfClass:fromData:error: sets secureCoding to true and we don't
+	// archive data with secureCoding enabled - use our own unarchiver to work around that.
+	NSError *error;
+	NSKeyedUnarchiver *unarchiver = [[NSKeyedUnarchiver alloc] initForReadingFromData:archiveData
+                                                                              error:&error];
+	unarchiver.requiresSecureCoding = NO;
+	SQRLInstallerOwnedBundle *ownedBundle = [unarchiver decodeObjectForKey:NSKeyedArchiveRootObjectKey];
+	[unarchiver finishDecoding];
+
+	if (error) {
+		NSLog(@"Error while unarchiving ownedBundle - %@", error.localizedDescription);
+		return nil;
+	}
+
+	if (!ownedBundle || ![ownedBundle isKindOfClass:SQRLInstallerOwnedBundle.class]) {
+		NSLog(@"Unknown error while unarchiving ownedBundle - did not conform to SQRLInstallerOwnedBundle");
+		return nil;
+	}
 
 	return ownedBundle;
 }
 
 - (void)setOwnedBundle:(SQRLInstallerOwnedBundle *)ownedBundle {
-	NSData *archiveData = (ownedBundle == nil ? nil : [NSKeyedArchiver archivedDataWithRootObject:ownedBundle]);
+	NSData *archiveData = nil;
+	if (ownedBundle != nil) {
+		NSError *error;
+		archiveData = [NSKeyedArchiver archivedDataWithRootObject:ownedBundle
+													requiringSecureCoding:NO
+																					error:&error];
+
+		if (error)
+			NSLog(@"Couldn't archive ownedBundle - %@", error.localizedDescription);
+	}
+
 	CFPreferencesSetValue((__bridge CFStringRef)SQRLInstallerOwnedBundleKey, (__bridge CFPropertyListRef)archiveData, (__bridge CFStringRef)self.applicationIdentifier, kCFPreferencesCurrentUser, kCFPreferencesCurrentHost);
 	CFPreferencesSynchronize((__bridge CFStringRef)self.applicationIdentifier, kCFPreferencesCurrentUser, kCFPreferencesCurrentHost);
 }
@@ -249,6 +276,7 @@ NSString * const SQRLInstallerOwnedBundl
 		] reduce:^(NSURL *directoryURL, SQRLCodeSignature *codeSignature) {
 			NSURL *targetBundleURL = request.targetBundleURL;
 			NSURL *newBundleURL = [directoryURL URLByAppendingPathComponent:targetBundleURL.lastPathComponent];
+			[NSFileManager.defaultManager createDirectoryAtURL:newBundleURL withIntermediateDirectories:FALSE attributes:nil error:nil];
 
 			return [[SQRLInstallerOwnedBundle alloc] initWithOriginalURL:request.targetBundleURL temporaryURL:newBundleURL codeSignature:codeSignature];
 		}]
@@ -285,6 +313,19 @@ NSString * const SQRLInstallerOwnedBundl
 			return [[[[self
 				renameIfNeeded:request updateBundleURL:updateBundleURL]
 				flattenMap:^(SQRLShipItRequest *request) {
+					// Final validation that the application is not running again;
+					NSArray *apps = [[NSRunningApplication runningApplicationsWithBundleIdentifier:request.bundleIdentifier] filteredArrayUsingPredicate:[NSPredicate predicateWithBlock:^BOOL(NSRunningApplication *app, NSDictionary *bindings) {
+						return [[[app bundleURL] URLByStandardizingPath] isEqual:request.targetBundleURL];
+					}]];
+					if ([apps count] != 0) {
+						NSLog(@"Aborting update attempt because there are %lu running instances of the target app", [apps count]);
+						NSDictionary *errorInfo = @{
+							NSLocalizedDescriptionKey: NSLocalizedString(@"App Still Running Error", nil),
+							NSLocalizedRecoverySuggestionErrorKey: NSLocalizedString(@"All instances of the target application should be quit during the update process", nil),
+						};
+						return [RACSignal error:[NSError errorWithDomain:SQRLInstallerErrorDomain code:SQRLInstallerErrorAppStillRunning userInfo:errorInfo]];
+					}
+
 					return [[self acquireTargetBundleURLForRequest:request] concat:[RACSignal return:request]];
 				}]
 				flattenMap:^(SQRLShipItRequest *request) {
@@ -481,10 +522,50 @@ NSString * const SQRLInstallerOwnedBundl
 	NSParameterAssert(targetURL != nil);
 	NSParameterAssert(sourceURL != nil);
 
+	NSLog(@"Moving bundle from %@ to %@", sourceURL, targetURL);
+
+	// If both the sourceURL and the targetURL exist we can try to skip a permissions check
+	// by moving Thing.app/Contents directly.  This allows us to update applications without
+	// permission to write files into the parent directory of Thing.app
+	//
+	// There is no known case where these directories don't exist but in order to handle
+	// edge cases / race conditions we'll handle it anyway.
+	//
+	// This exists check is non-atomic with the rename call below but that's OK
+	BOOL canRenameContentsDirectly = FALSE;
+	// For now while this is tested at scale this new option is behind a user default, this
+	// can be set by applications wishing to test this feature at runtime.  If it causes issues
+	// it can be opted out by individual users by setting this key to false explicitly.
+	// Once this has bene tested at scale it will become the default for all Squirrel.Mac
+	// users.
+	NSUserDefaults *defaults = [[NSUserDefaults alloc] init];
+	[defaults addSuiteNamed:_applicationIdentifier];
+	// In cases where this code is being executed under the ShipIt executable it's running
+	// under an application identifier equal to {parent_identifier}.ShipIt
+	// In this case we need to use the true parent identifier too as that is 99% of the time
+	// where the key will be set.
+	if ([_applicationIdentifier hasSuffix:@".ShipIt"]) {
+		[defaults addSuiteNamed:[_applicationIdentifier substringToIndex:[_applicationIdentifier length] - 7]];
+	}
+
+	if ([defaults boolForKey:@"SquirrelMacEnableDirectContentsWrite"]) {
+		canRenameContentsDirectly = [NSFileManager.defaultManager fileExistsAtPath:targetURL.path] && [NSFileManager.defaultManager fileExistsAtPath:sourceURL.path];
+
+		if (canRenameContentsDirectly) {
+			NSLog(@"Moving bundles via 'Contents' folder rename");
+		} else {
+			NSLog(@"Moving bundles directly as one of source / target does not exist.  This is unexpected.");
+		}
+	} else {
+		NSLog(@"Moving bundles directly as SquirrelMacEnableDirectContentsWrite is disabled for app: %@", _applicationIdentifier);
+	}
+	NSURL *targetContentsURL = canRenameContentsDirectly ? [targetURL URLByAppendingPathComponent:@"Contents"] : targetURL;
+	NSURL *sourceContentsURL = canRenameContentsDirectly ? [sourceURL URLByAppendingPathComponent:@"Contents"] : sourceURL;
+
 	return [[[[RACSignal
 		defer:^{
 			// rename() is atomic, NSFileManager sucks.
-			if (rename(sourceURL.path.fileSystemRepresentation, targetURL.path.fileSystemRepresentation) == 0) {
+			if (rename(sourceContentsURL.path.fileSystemRepresentation, targetContentsURL.path.fileSystemRepresentation) == 0) {
 				return [RACSignal empty];
 			} else {
 				int code = errno;
@@ -497,24 +578,24 @@ NSString * const SQRLInstallerOwnedBundl
 			}
 		}]
 		doCompleted:^{
-			NSLog(@"Moved bundle from %@ to %@", sourceURL, targetURL);
+			NSLog(@"Moved bundle contents from %@ to %@", sourceContentsURL, targetContentsURL);
 		}]
 		catch:^(NSError *error) {
 			if (![error.domain isEqual:NSPOSIXErrorDomain] || error.code != EXDEV) return [RACSignal error:error];
 
 			// If the locations lie on two different volumes, remove the
 			// destination by hand, then perform a move.
-			[NSFileManager.defaultManager removeItemAtURL:targetURL error:NULL];
+			[NSFileManager.defaultManager removeItemAtURL:targetContentsURL error:NULL];
 
-			if ([NSFileManager.defaultManager moveItemAtURL:sourceURL toURL:targetURL error:&error]) {
-				NSLog(@"Moved bundle across volumes from %@ to %@", sourceURL, targetURL);
+			if ([NSFileManager.defaultManager moveItemAtURL:sourceContentsURL toURL:targetContentsURL error:&error]) {
+				NSLog(@"Moved bundle contents across volumes from %@ to %@", sourceContentsURL, targetContentsURL);
 				return [RACSignal empty];
 			} else {
-				NSString *description = [NSString stringWithFormat:NSLocalizedString(@"Couldn't move bundle %@ across volumes to %@", nil), sourceURL, targetURL];
+				NSString *description = [NSString stringWithFormat:NSLocalizedString(@"Couldn't move bundle contents %@ across volumes to %@", nil), sourceContentsURL, targetContentsURL];
 				return [RACSignal error:[self errorByAddingDescription:description code:SQRLInstallerErrorMovingAcrossVolumes toError:error]];
 			}
 		}]
-		setNameWithFormat:@"%@ -installItemAtURL: %@ fromURL: %@", self, targetURL, sourceURL];
+		setNameWithFormat:@"%@ -installItemAtURL: %@ fromURL: %@", self, targetContentsURL, sourceContentsURL];
 }
 
 #pragma mark Quarantine Bit Removal
