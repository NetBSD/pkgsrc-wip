$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/Squirrel/ShipIt-main.m.orig	2021-06-18 22:08:36.000000000 +0000
+++ third_party/squirrel.mac/Squirrel/ShipIt-main.m
@@ -8,10 +8,13 @@
 
 #import <Foundation/Foundation.h>
 
-#import "EXTScope.h"
-#import <ReactiveCocoa/RACCommand.h>
-#import <ReactiveCocoa/RACSignal+Operations.h>
-#import <ReactiveCocoa/RACScheduler.h>
+#import <ReactiveObjC/EXTScope.h>
+#import <ReactiveObjC/RACCommand.h>
+#import <ReactiveObjC/RACSignal+Operations.h>
+#import <ReactiveObjC/RACScheduler.h>
+
+#include <spawn.h>
+#include <sys/wait.h>
 
 #import "NSError+SQRLVerbosityExtensions.h"
 #import "RACSignal+SQRLTransactionExtensions.h"
@@ -20,6 +23,20 @@
 #import "SQRLTerminationListener.h"
 #import "SQRLShipItRequest.h"
 
+extern char **environ;
+
+int responsibility_spawnattrs_setdisclaim(posix_spawnattr_t attrs, int disclaim)
+__attribute__((availability(macos,introduced=10.14),weak_import));
+
+#define CHECK_ERR(expr) \
+	{ \
+		int err = (expr); \
+    if (err) { \
+        fprintf(stderr, "%s: %s", #expr, strerror(err)); \
+        exit(err); \
+    } \
+	}
+
 // The maximum number of times ShipIt should run the same installation state, in
 // an attempt to update.
 //
@@ -136,19 +153,47 @@ static void installRequest(RACSignal *re
 							NSString *exe = NSProcessInfo.processInfo.arguments[0];
 							NSLog(@"Launching new ShipIt at %@ with instructions to launch %@", exe, bundleURL);
 
-							NSTask *task = [[NSTask alloc] init];
-							[task setLaunchPath: exe];
-							[task setArguments: @[launchSignal, bundleURL.path]];
-							[task launch];
-							[task waitUntilExit];
+							posix_spawnattr_t attr;
+							CHECK_ERR(posix_spawnattr_init(&attr));
+
+							// Disclaim TCC responsibilities
+							if (responsibility_spawnattrs_setdisclaim)
+									CHECK_ERR(responsibility_spawnattrs_setdisclaim(&attr, 1));
+
+							pid_t pid = 0;
+
+							const char* launchPath = [exe fileSystemRepresentation];
+							const char* signal = [launchSignal fileSystemRepresentation];
+							const char* path = [bundleURL.path fileSystemRepresentation];
+							const char* args[] = { launchPath, signal, path, 0 };
+							int status = posix_spawn(&pid, [exe UTF8String], NULL, &attr, (char *const*)args, environ);
+							if (status == 0) {
+								NSLog(@"New ShipIt pid: %i", pid);
+								do {
+									if (waitpid(pid, &status, 0) != -1) {
+										NSLog(@"ShipIt status %d", WEXITSTATUS(status));
+									} else {
+										perror("waitpid");
+										exit(1);
+									}
+								} while (!WIFEXITED(status) && !WIFSIGNALED(status));
+							} else {
+								NSLog(@"posix_spawn: %s", strerror(status));
+							}
+
+							posix_spawnattr_destroy(&attr);
 
 							NSLog(@"New ShipIt exited");
 						} else {
 							NSLog(@"Attempting to launch app on lower than 11.0");
+// TODO: https://github.com/electron/electron/issues/43168
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wdeprecated-declarations"
 							if (![NSWorkspace.sharedWorkspace launchApplicationAtURL:bundleURL options:NSWorkspaceLaunchDefault configuration:@{} error:&error]) {
 								NSLog(@"Could not launch application at %@: %@", bundleURL, error);
 								return;
 							}
+#pragma clang diagnostic pop
 
 							NSLog(@"Application launched at %@", bundleURL);
 						}
@@ -158,8 +203,14 @@ static void installRequest(RACSignal *re
 			return action;
 		}]
 		subscribeError:^(NSError *error) {
-			NSLog(@"Installation error: %@", error);
-			exit(EXIT_FAILURE);
+			if ([[error domain] isEqual:SQRLInstallerErrorDomain] && [error code] == SQRLInstallerErrorAppStillRunning) {
+				NSLog(@"Installation cancelled: %@", error);
+				clearInstallationAttempts(applicationIdentifier);
+				exit(EXIT_SUCCESS);
+			} else {
+				NSLog(@"Installation error: %@", error);
+				exit(EXIT_FAILURE);
+			}
 		} completed:^{
 			exit(EXIT_SUCCESS);
 		}];
@@ -172,7 +223,13 @@ int main(int argc, const char * argv[]) 
 		});
 
 		if (argc < 3) {
-			NSLog(@"Missing launchd job label or state path for ShipIt");
+			NSLog(@"Missing launchd job label or state path for ShipIt (%d)", argc);
+			if (argc >= 1) {
+				NSLog(@"Arg 1: {%s}", argv[0]);
+			}
+			if (argc >= 2) {
+				NSLog(@"Arg 2: {%s}", argv[1]);
+			}
 			return EXIT_FAILURE;
 		}
 
@@ -182,12 +239,16 @@ int main(int argc, const char * argv[]) 
 
 		if (strcmp(jobLabel, [launchSignal UTF8String]) == 0) {
 			NSLog(@"Detected this as a launch request");
+// TODO: https://github.com/electron/electron/issues/43168
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wdeprecated-declarations"
 			NSError *error;
 			if (![NSWorkspace.sharedWorkspace launchApplicationAtURL:shipItStateURL options:NSWorkspaceLaunchDefault configuration:@{} error:&error]) {
 				NSLog(@"Could not launch application at %@: %@", shipItStateURL, error);
 			} else {
 				NSLog(@"Successfully launched application at %@", shipItStateURL);
 			}
+#pragma clang diagnostic pop
 			exit(EXIT_SUCCESS);
 		} else {
 			NSLog(@"Detected this as an install request");
