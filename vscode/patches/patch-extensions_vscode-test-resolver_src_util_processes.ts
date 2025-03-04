$NetBSD$

* Add support to NetBSD and FreeBSD

--- extensions/vscode-test-resolver/src/util/processes.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ extensions/vscode-test-resolver/src/util/processes.ts
@@ -20,7 +20,7 @@ export function terminateProcess(p: cp.C
 		} catch (err) {
 			return { success: false, error: err };
 		}
-	} else if (process.platform === 'darwin' || process.platform === 'linux') {
+	} else if (process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
 		try {
 			const cmd = path.join(extensionPath, 'scripts', 'terminateProcess.sh');
 			const result = cp.spawnSync(cmd, [p.pid!.toString()]);
