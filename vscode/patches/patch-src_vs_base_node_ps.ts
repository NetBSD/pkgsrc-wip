$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/base/node/ps.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ src/vs/base/node/ps.ts
@@ -208,7 +208,7 @@ export function listProcesses(rootPid: n
 
 			exec('which ps', {}, (err, stdout, stderr) => {
 				if (err || stderr) {
-					if (process.platform !== 'linux') {
+					if (process.platform !== 'linux' && process.platform !== 'freebsd' && process.platform !== 'netbsd') {
 						reject(err || new Error(stderr.toString()));
 					} else {
 						const cmd = JSON.stringify(FileAccess.asFileUri('vs/base/node/ps.sh').fsPath);
@@ -223,7 +223,8 @@ export function listProcesses(rootPid: n
 					}
 				} else {
 					const ps = stdout.toString().trim();
-					const args = '-ax -o pid=,ppid=,pcpu=,pmem=,command=';
+					//const args = '-ax -o pid=,ppid=,pcpu=,pmem=,command=';
+					const args = '-ax -o pid= -o ppid= -o pcpu= -o pmem= -o command=';
 
 					// Set numeric locale to ensure '.' is used as the decimal separator
 					exec(`${ps} ${args}`, { maxBuffer: 1000 * 1024, env: { LC_NUMERIC: 'en_US.UTF-8' } }, (err, stdout, stderr) => {
