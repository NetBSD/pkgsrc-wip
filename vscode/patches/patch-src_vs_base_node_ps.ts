$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/base/node/ps.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ src/vs/base/node/ps.ts
@@ -217,7 +217,7 @@ export function listProcesses(rootPid: n
 					}
 				} else {
 					const ps = stdout.toString().trim();
-					const args = '-ax -o pid=,ppid=,pcpu=,pmem=,command=';
+					const args = '-ax -o pid= -o ppid= -o pcpu= -o pmem= -o command=';
 
 					// Set numeric locale to ensure '.' is used as the decimal separator
 					exec(`${ps} ${args}`, { maxBuffer: 1000 * 1024, env: { LC_NUMERIC: 'en_US.UTF-8' } }, (err, stdout, stderr) => {
