$NetBSD$

* Use own starting wrapper

--- src/vs/platform/native/electron-main/nativeHostMainService.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ src/vs/platform/native/electron-main/nativeHostMainService.ts
@@ -644,30 +644,7 @@ export class NativeHostMainService exten
 	@memoize
 	private get cliPath(): string {
 
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
