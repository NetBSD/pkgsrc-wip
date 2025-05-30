$NetBSD$

* Add support to NetBSD and FreeBSD

--- test/smoke/src/areas/task/task.test.ts.orig	2025-05-14 21:40:56.000000000 +0000
+++ test/smoke/src/areas/task/task.test.ts
@@ -19,6 +19,6 @@ export function setup(logger: Logger) {
 		// Refs https://github.com/microsoft/vscode/issues/225250
 		// Pty spawning fails with invalid fd error in product CI while development CI
 		// works fine, we need additional logging to investigate.
-		setupTaskQuickPickTests({ skipSuite: process.platform === 'linux' });
+		setupTaskQuickPickTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') });
 	});
 }
