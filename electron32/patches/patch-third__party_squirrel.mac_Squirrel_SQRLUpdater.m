$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/SQRLUpdater.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/SQRLUpdater.m
@@ -18,8 +18,8 @@
 #import "SQRLUpdate.h"
 #import "SQRLZipArchiver.h"
 #import "SQRLShipItRequest.h"
-#import <ReactiveCocoa/EXTScope.h>
-#import <ReactiveCocoa/ReactiveCocoa.h>
+#import <ReactiveObjC/EXTScope.h>
+#import <ReactiveObjC/ReactiveObjC.h>
 #import <sys/mount.h>
 
 NSString * const SQRLUpdaterErrorDomain = @"SQRLUpdaterErrorDomain";
@@ -42,6 +42,18 @@ const NSTimeInterval SQURLUpdaterZipDown
 // followed by a random string of characters.
 static NSString * const SQRLUpdaterUniqueTemporaryDirectoryPrefix = @"update.";
 
+BOOL isVersionStandard(NSString* version) {
+	NSCharacterSet *alphaNums = [NSCharacterSet decimalDigitCharacterSet];
+
+	NSArray* versionParts = [version componentsSeparatedByString:@"."];
+	BOOL versionBad = [versionParts count] != 3;
+	for (NSString* part in versionParts) {
+		versionBad = versionBad || [alphaNums isSupersetOfSet:[NSCharacterSet characterSetWithCharactersInString:part]];
+	}
+
+	return !versionBad;
+}
+
 @interface SQRLUpdater ()
 
 @property (atomic, readwrite) SQRLUpdaterState state;
@@ -59,6 +71,8 @@ static NSString * const SQRLUpdaterUniqu
 // Sends completed or error.
 @property (nonatomic, strong, readonly) RACSignal *shipItLauncher;
 
++ (bool) isVersionAllowedForUpdate:(NSString*)targetVersion from:(NSString*)currentVersion;
+
 // Parses an update model from downloaded data.
 //
 // data - JSON data representing an update manifest. This must not be nil.
@@ -329,7 +343,12 @@ static NSString * const SQRLUpdaterUniqu
 
 			BOOL targetWritable = [self canWriteToURL:targetURL];
 			BOOL parentWritable = [self canWriteToURL:targetURL.URLByDeletingLastPathComponent];
-			return [SQRLShipItLauncher launchPrivileged:!targetWritable || !parentWritable];
+			BOOL launchPrivileged = !targetWritable || !parentWritable;
+			if ([[NSUserDefaults standardUserDefaults] boolForKey:@"SquirrelMacEnableDirectContentsWrite"]) {
+				// If SquirrelMacEnableDirectContentsWrite is enabled we don't care if the parent directory is writeable or not
+				BOOL launchPrivileged = !targetWritable;
+			}
+			return [SQRLShipItLauncher launchPrivileged:launchPrivileged];
 		}]
 		replayLazily]
 		setNameWithFormat:@"shipItLauncher"];
@@ -367,6 +386,10 @@ static NSString * const SQRLUpdaterUniqu
 		connect];
 }
 
++ (bool) isVersionAllowedForUpdate:(NSString*)targetVersion from:(NSString*)currentVersion {
+	return [currentVersion compare:targetVersion options:NSNumericSearch] != NSOrderedDescending;
+}
+
 - (RACSignal *)updateFromJSONData:(NSData *)data {
 	NSParameterAssert(data != nil);
 
@@ -706,6 +729,50 @@ static NSString * const SQRLUpdaterUniqu
 	return [[[[self.signature
 		verifyBundleAtURL:updateBundle.bundleURL]
 		then:^{
+			NSRunningApplication *currentApplication = NSRunningApplication.currentApplication;
+			NSBundle *appBundle = [NSBundle bundleWithURL:currentApplication.bundleURL];
+			BOOL preventDowngrades = [[appBundle objectForInfoDictionaryKey:@"ElectronSquirrelPreventDowngrades"] boolValue];
+
+			if (preventDowngrades == YES) {
+				NSString* currentVersion = [appBundle objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
+				NSString* updateVersion = [updateBundle objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
+				if (!currentVersion || !updateVersion) {
+					NSDictionary *errorInfo = @{
+						NSLocalizedDescriptionKey: NSLocalizedString(@"Cannot update to a bundle with a lower version number", nil),
+						NSLocalizedRecoverySuggestionErrorKey: NSLocalizedString(@"The application has ElectronSquirrelPreventDowngrades enabled and is missing a valid version string in either the current bundle or the target bundle", nil),
+					};
+					NSError *error = [NSError errorWithDomain:SQRLUpdaterErrorDomain code:SQRLUpdaterErrorMissingUpdateBundle userInfo:errorInfo];
+					return [RACSignal error:error];
+				}
+
+				if (!isVersionStandard(currentVersion)) {
+					NSDictionary *errorInfo = @{
+						NSLocalizedDescriptionKey: NSLocalizedString(@"Cannot update to a bundle with a lower version number", nil),
+						NSLocalizedRecoverySuggestionErrorKey: [NSString stringWithFormat:NSLocalizedString(@"The application has ElectronSquirrelPreventDowngrades enabled and is trying to update from '%@' which is not a valid version string", nil), currentVersion],
+					};
+					NSError *error = [NSError errorWithDomain:SQRLUpdaterErrorDomain code:SQRLUpdaterErrorMissingUpdateBundle userInfo:errorInfo];
+					return [RACSignal error:error];
+				}
+
+				if (!isVersionStandard(updateVersion)) {
+					NSDictionary *errorInfo = @{
+						NSLocalizedDescriptionKey: NSLocalizedString(@"Cannot update to a bundle with a lower version number", nil),
+						NSLocalizedRecoverySuggestionErrorKey: [NSString stringWithFormat:NSLocalizedString(@"The application has ElectronSquirrelPreventDowngrades enabled and is trying to update to '%@' which is not a valid version string", nil), updateVersion],
+					};
+					NSError *error = [NSError errorWithDomain:SQRLUpdaterErrorDomain code:SQRLUpdaterErrorMissingUpdateBundle userInfo:errorInfo];
+					return [RACSignal error:error];
+				}
+
+				if (![SQRLUpdater isVersionAllowedForUpdate:updateVersion from:currentVersion]) {
+					NSDictionary *errorInfo = @{
+						NSLocalizedDescriptionKey: NSLocalizedString(@"Cannot update to a bundle with a lower version number", nil),
+						NSLocalizedRecoverySuggestionErrorKey: [NSString stringWithFormat:NSLocalizedString(@"The application has ElectronSquirrelPreventDowngrades enabled and is trying to update from '%@' to '%@' which appears to be a downgrade", nil), currentVersion, updateVersion],
+					};
+					NSError *error = [NSError errorWithDomain:SQRLUpdaterErrorDomain code:SQRLUpdaterErrorMissingUpdateBundle userInfo:errorInfo];
+					return [RACSignal error:error];
+				}
+			}
+
 			SQRLDownloadedUpdate *downloadedUpdate = [[SQRLDownloadedUpdate alloc] initWithUpdate:update bundle:updateBundle];
 			return [RACSignal return:downloadedUpdate];
 		}]
