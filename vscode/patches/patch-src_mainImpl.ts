$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/mainImpl.ts.orig	2026-10-14 09:52:01.000000000 +0000
+++ src/mainImpl.ts
@@ -168,7 +168,7 @@ if (userLocale) {
 // Pseudo Language Language Pack is being used.
 // In that case, use `en` as the Electron locale.
 
-if (process.platform === 'win32' || process.platform === 'linux') {
+if (process.platform === 'win32' || process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
 	const electronLocale = (!userLocale || userLocale === 'qps-ploc') ? 'en' : userLocale;
 	app.commandLine.appendSwitch('lang', electronLocale);
 }
@@ -266,7 +266,7 @@ function configureCommandlineSwitchesSyn
 		'remote-debugging-port'
 	];
 
-	if (process.platform === 'linux') {
+	if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
 
 		// Force enable screen readers on Linux via this flag
 		SUPPORTED_ELECTRON_SWITCHES.push('force-renderer-accessibility');
@@ -362,7 +362,7 @@ function configureCommandlineSwitchesSyn
 	// `EstablishGpuChannelAsync` - Refs https://issues.chromium.org/issues/40208065
 	// `GlobalShortcutsPortal` - Enables Electron's `globalShortcut` (system-wide keybindings) on Linux Wayland via the XDG global shortcuts portal (no-op elsewhere)
 	const featuresToEnable =
-		`NetAdapterMaxBufSizeFeature:NetAdapterMaxBufSize/8192,DocumentPolicyIncludeJSCallStacksInCrashReports,EarlyEstablishGpuChannel,EstablishGpuChannelAsync${process.platform === 'linux' ? ',GlobalShortcutsPortal' : ''},${app.commandLine.getSwitchValue('enable-features')}`;
+		`NetAdapterMaxBufSizeFeature:NetAdapterMaxBufSize/8192,DocumentPolicyIncludeJSCallStacksInCrashReports,EarlyEstablishGpuChannel,EstablishGpuChannelAsync${(process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') ? ',GlobalShortcutsPortal' : ''},${app.commandLine.getSwitchValue('enable-features')}`;
 	app.commandLine.appendSwitch('enable-features', featuresToEnable);
 
 	// Following features are disabled from the runtime:
