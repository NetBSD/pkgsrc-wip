$NetBSD$

* TODO: imported from FreeBSD ports, pkgsrc's vscode hasn't test make target

--- test/smoke/src/areas/terminal/terminal.test.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ test/smoke/src/areas/terminal/terminal.test.ts
@@ -39,15 +39,15 @@ export function setup(logger: Logger) {
 		// https://github.com/microsoft/vscode/issues/216564
 		// The pty host can crash on Linux in smoke tests for an unknown reason. We need more user
 		// reports to investigate
-		setupTerminalEditorsTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalInputTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalPersistenceTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalProfileTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalTabsTests({ skipSuite: process.platform === 'linux' });
-		setupTerminalShellIntegrationTests({ skipSuite: process.platform === 'linux' });
+		setupTerminalEditorsTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') });
+		setupTerminalInputTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') });
+		setupTerminalPersistenceTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') });
+		setupTerminalProfileTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') });
+		setupTerminalTabsTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') });
+		setupTerminalShellIntegrationTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') });
 		setupTerminalStickyScrollTests({ skipSuite: true });
 		// https://github.com/microsoft/vscode/pull/141974
 		// Windows is skipped here as well as it was never enabled from the start
-		setupTerminalSplitCwdTests({ skipSuite: process.platform === 'linux' || process.platform === 'win32' });
+		setupTerminalSplitCwdTests({ skipSuite: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd' || process.platform === 'win32') });
 	});
 }
