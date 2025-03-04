$NetBSD$

* Add support to NetBSD and FreeBSD

--- src/vs/base/common/platform.ts.orig	2025-02-10 13:07:56.000000000 +0000
+++ src/vs/base/common/platform.ts
@@ -74,7 +74,7 @@ declare const navigator: INavigator;
 if (typeof nodeProcess === 'object') {
 	_isWindows = (nodeProcess.platform === 'win32');
 	_isMacintosh = (nodeProcess.platform === 'darwin');
-	_isLinux = (nodeProcess.platform === 'linux');
+	_isLinux = (nodeProcess.platform === 'linux' || nodeProcess.platform === 'freebsd' || nodeProcess.platform === 'netbsd');
 	_isLinuxSnap = _isLinux && !!nodeProcess.env['SNAP'] && !!nodeProcess.env['SNAP_REVISION'];
 	_isElectron = isElectronProcess;
 	_isCI = !!nodeProcess.env['CI'] || !!nodeProcess.env['BUILD_ARTIFACTSTAGINGDIRECTORY'];
@@ -100,7 +100,7 @@ else if (typeof navigator === 'object' &
 	_isWindows = _userAgent.indexOf('Windows') >= 0;
 	_isMacintosh = _userAgent.indexOf('Macintosh') >= 0;
 	_isIOS = (_userAgent.indexOf('Macintosh') >= 0 || _userAgent.indexOf('iPad') >= 0 || _userAgent.indexOf('iPhone') >= 0) && !!navigator.maxTouchPoints && navigator.maxTouchPoints > 0;
-	_isLinux = _userAgent.indexOf('Linux') >= 0;
+	_isLinux = (_userAgent.indexOf('Linux') >= 0 || _userAgent.indexOf('FreeBSD') >= 0 || _userAgent.indexOf('NetBSD') >= 0);
 	_isMobile = _userAgent?.indexOf('Mobi') >= 0;
 	_isWeb = true;
 	_language = nls.getNLSLanguage() || LANGUAGE_DEFAULT;
