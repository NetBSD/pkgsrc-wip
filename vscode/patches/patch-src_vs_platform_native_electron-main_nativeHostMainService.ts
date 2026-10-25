$NetBSD$

* Use own start wrapper

--- src/vs/platform/native/electron-main/nativeHostMainService.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ src/vs/platform/native/electron-main/nativeHostMainService.ts
@@ -888,31 +888,7 @@ export class NativeHostMainService exten
 
 	@memoize
 	private get cliPath(): string {
-
-		// Windows
-		if (isWindows) {
-			if (this.environmentMainService.isBuilt) {
-				return join(dirname(process.execPath), 'bin', `${this.productService.applicationName}.cmd`);
-			}
-
-			return join(this.environmentMainService.appRoot, 'scripts', 'code-cli.bat');
-		}
-
-		// Linux
-		if (isLinux) {
-			if (this.environmentMainService.isBuilt) {
-				return join(dirname(process.execPath), 'bin', `${this.productService.applicationName}`);
-			}
-
-			return join(this.environmentMainService.appRoot, 'scripts', 'code-cli.sh');
-		}
-
-		// macOS
-		if (this.environmentMainService.isBuilt) {
-			return join(this.environmentMainService.appRoot, 'bin', 'code');
-		}
-
-		return join(this.environmentMainService.appRoot, 'scripts', 'code-cli.sh');
+		return '@PREFIX@/bin/code-oss';
 	}
 
 	async getOSStatistics(): Promise<IOSStatistics> {
