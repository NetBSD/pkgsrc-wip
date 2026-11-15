$NetBSD$

* Add Free- and NetBSD support

--- app/main.main.ts.orig	2026-10-28 21:49:13.000000000 +0000
+++ app/main.main.ts
@@ -638,7 +638,7 @@ const rootDir = getAppRootDir();
 
 if (OS.isWindows()) {
   windowIcon = join(rootDir, 'build', 'icons', 'win', 'icon.ico');
-} else if (OS.isLinux()) {
+} else if (OS.isLinux() || OS.isFreeBSD() || OS.isNetBSD()) {
   windowIcon = join(rootDir, 'images', 'signal-logo-desktop-linux.png');
 } else {
   windowIcon = join(rootDir, 'build', 'icons', 'png', '512x512.png');
@@ -1046,7 +1046,7 @@ async function createWindow() {
     }
   };
 
-  if (OS.isLinux() && OS.isWaylandEnabled()) {
+  if ((OS.isLinux() || OS.isFreeBSD() || OS.isNetBSD()) && OS.isWaylandEnabled()) {
     mainWindow.webContents.once('did-finish-load', async () => {
       log.info('main window webContents did-finish-load');
       drop(maybeShowMainWindow());
@@ -1256,7 +1256,7 @@ async function readyForUpdates() {
     );
     await updater.start({
       canRunSilently: async () => {
-        const canRestartInTray = OS.isLinux()
+        const canRestartInTray = (OS.isLinux() || OS.isFreeBSD() || OS.isNetBSD())
           ? (await systemTraySettingCache.get()) ===
             SystemTraySetting.MinimizeToAndStartInSystemTray
           : true;
@@ -1735,13 +1735,15 @@ function generateSQLKey(): string {
 function getSQLKey(): string {
   let update = false;
   const isLinux = OS.isLinux();
+  const isFreeBSD = OS.isFreeBSD();
+  const isNetBSD = OS.isNetBSD();
   const legacyKeyValue = userConfig.get('key');
   const modernKeyValue = userConfig.get('encryptedKey');
-  const previousBackend = isLinux
+  const previousBackend = (isLinux || isFreeBSD || isNetBSD)
     ? userConfig.get('safeStorageBackend')
     : undefined;
 
-  const safeStorageBackend: string | undefined = isLinux
+  const safeStorageBackend: string | undefined = (isLinux || isFreeBSD || isNetBSD)
     ? safeStorage.getSelectedStorageBackend()
     : undefined;
   const isEncryptionAvailable =
@@ -1751,12 +1753,12 @@ function getSQLKey(): string {
       (!process.env.GENERATE_PRELOAD_CACHE &&
         !isTestEnvironment(getEnvironment()))) &&
     safeStorage.isEncryptionAvailable() &&
-    (!isLinux || safeStorageBackend !== 'basic_text');
+    (!(isLinux || isFreeBSD || isNetBSD) || safeStorageBackend !== 'basic_text');
 
   // On Linux the backend can change based on desktop environment and command line flags.
   // If the backend changes we won't be able to decrypt the key.
   if (
-    isLinux &&
+    (isLinux || isFreeBSD || isNetBSD) &&
     typeof previousBackend === 'string' &&
     previousBackend !== safeStorageBackend
   ) {
@@ -1796,7 +1798,7 @@ function getSQLKey(): string {
       }
     }
 
-    if (isLinux && previousBackend == null) {
+    if ((isLinux || isFreeBSD || isNetBSD) && previousBackend == null) {
       log.info(`getSQLKey: saving safeStorageBackend: ${safeStorageBackend}`);
       userConfig.set('safeStorageBackend', safeStorageBackend);
     }
@@ -1832,7 +1834,7 @@ function getSQLKey(): string {
       userConfig.set('key', undefined);
     }
 
-    if (isLinux && safeStorageBackend) {
+    if ((isLinux || isFreeBSD || isNetBSD) && safeStorageBackend) {
       log.info(`getSQLKey: saving safeStorageBackend: ${safeStorageBackend}`);
       userConfig.set('safeStorageBackend', safeStorageBackend);
     }
@@ -2795,7 +2797,7 @@ ipc.on('draw-attention', () => {
     return;
   }
 
-  if (OS.isWindows() || OS.isLinux()) {
+  if (OS.isWindows() || OS.isLinux() || OS.isFreeBSD() || OS.isNetBSD()) {
     mainWindow.flashFrame(true);
   }
 });
