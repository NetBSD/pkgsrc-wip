$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/lib/internal/modules/esm/resolve.js.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/lib/internal/modules/esm/resolve.js
@@ -24,7 +24,7 @@ const {
 } = primordials;
 const internalFS = require('internal/fs/utils');
 const { BuiltinModule } = require('internal/bootstrap/realm');
-const { realpathSync } = require('fs');
+const fs = require('fs');
 const { getOptionValue } = require('internal/options');
 // Do not eagerly grab .manifest, it may be in TDZ
 const policy = getOptionValue('--experimental-policy') ?
@@ -36,10 +36,9 @@ const preserveSymlinksMain = getOptionVa
 const experimentalNetworkImports =
   getOptionValue('--experimental-network-imports');
 const inputTypeFlag = getOptionValue('--input-type');
-const { URL, pathToFileURL, fileURLToPath, isURL } = require('internal/url');
+const { URL, pathToFileURL, fileURLToPath, isURL, toPathIfFileURL } = require('internal/url');
 const { getCWDURL, setOwnProperty } = require('internal/util');
 const { canParse: URLCanParse } = internalBinding('url');
-const { legacyMainResolve: FSLegacyMainResolve } = internalBinding('fs');
 const {
   ERR_INPUT_TYPE_NOT_ALLOWED,
   ERR_INVALID_ARG_TYPE,
@@ -59,7 +58,7 @@ const { Module: CJSModule } = require('i
 const { getPackageScopeConfig } = require('internal/modules/esm/package_config');
 const { getConditionsSet } = require('internal/modules/esm/utils');
 const packageJsonReader = require('internal/modules/package_json_reader');
-const { internalModuleStat } = internalBinding('fs');
+const internalFsBinding = internalBinding('fs');
 
 /**
  * @typedef {import('internal/modules/esm/package_config.js').PackageConfig} PackageConfig
@@ -162,34 +161,13 @@ function emitLegacyIndexDeprecation(url,
 
 const realpathCache = new SafeMap();
 
-const legacyMainResolveExtensions = [
-  '',
-  '.js',
-  '.json',
-  '.node',
-  '/index.js',
-  '/index.json',
-  '/index.node',
-  './index.js',
-  './index.json',
-  './index.node',
-];
-
-const legacyMainResolveExtensionsIndexes = {
-  // 0-6: when packageConfig.main is defined
-  kResolvedByMain: 0,
-  kResolvedByMainJs: 1,
-  kResolvedByMainJson: 2,
-  kResolvedByMainNode: 3,
-  kResolvedByMainIndexJs: 4,
-  kResolvedByMainIndexJson: 5,
-  kResolvedByMainIndexNode: 6,
-  // 7-9: when packageConfig.main is NOT defined,
-  //      or when the previous case didn't found the file
-  kResolvedByPackageAndJs: 7,
-  kResolvedByPackageAndJson: 8,
-  kResolvedByPackageAndNode: 9,
-};
+/**
+ * @param {string | URL} url
+ * @returns {boolean}
+ */
+function fileExists(url) {
+  return internalFsBinding.internalModuleStat(toNamespacedPath(toPathIfFileURL(url))) === 0;
+}
 
 /**
  * Legacy CommonJS main resolution:
@@ -204,22 +182,44 @@ const legacyMainResolveExtensionsIndexes
  * @returns {URL}
  */
 function legacyMainResolve(packageJSONUrl, packageConfig, base) {
-  const packageJsonUrlString = packageJSONUrl.href;
-
-  if (typeof packageJsonUrlString !== 'string') {
-    throw new ERR_INVALID_ARG_TYPE('packageJSONUrl', ['URL'], packageJSONUrl);
-  }
-
-  const baseStringified = isURL(base) ? base.href : base;
-
-  const resolvedOption = FSLegacyMainResolve(packageJsonUrlString, packageConfig.main, baseStringified);
-
-  const baseUrl = resolvedOption <= legacyMainResolveExtensionsIndexes.kResolvedByMainIndexNode ? `./${packageConfig.main}` : '';
-  const resolvedUrl = new URL(baseUrl + legacyMainResolveExtensions[resolvedOption], packageJSONUrl);
-
-  emitLegacyIndexDeprecation(resolvedUrl, packageJSONUrl, base, packageConfig.main);
-
-  return resolvedUrl;
+  let guess;
+  if (packageConfig.main !== undefined) {
+    // Note: fs check redundances will be handled by Descriptor cache here.
+    if (fileExists(guess = new URL(`./${packageConfig.main}`,
+                                   packageJSONUrl))) {
+      return guess;
+    } else if (fileExists(guess = new URL(`./${packageConfig.main}.js`,
+                                          packageJSONUrl)));
+    else if (fileExists(guess = new URL(`./${packageConfig.main}.json`,
+                                        packageJSONUrl)));
+    else if (fileExists(guess = new URL(`./${packageConfig.main}.node`,
+                                        packageJSONUrl)));
+    else if (fileExists(guess = new URL(`./${packageConfig.main}/index.js`,
+                                        packageJSONUrl)));
+    else if (fileExists(guess = new URL(`./${packageConfig.main}/index.json`,
+                                        packageJSONUrl)));
+    else if (fileExists(guess = new URL(`./${packageConfig.main}/index.node`,
+                                        packageJSONUrl)));
+    else guess = undefined;
+    if (guess) {
+      emitLegacyIndexDeprecation(guess, packageJSONUrl, base,
+                                 packageConfig.main);
+      return guess;
+    }
+    // Fallthrough.
+  }
+  if (fileExists(guess = new URL('./index.js', packageJSONUrl)));
+  // So fs.
+  else if (fileExists(guess = new URL('./index.json', packageJSONUrl)));
+  else if (fileExists(guess = new URL('./index.node', packageJSONUrl)));
+  else guess = undefined;
+  if (guess) {
+    emitLegacyIndexDeprecation(guess, packageJSONUrl, base, packageConfig.main);
+    return guess;
+  }
+  // Not found.
+  throw new ERR_MODULE_NOT_FOUND(
+    fileURLToPath(new URL('.', packageJSONUrl)), fileURLToPath(base));
 }
 
 const encodedSepRegEx = /%2F|%5C/i;
@@ -257,7 +257,7 @@ function finalizeResolution(resolved, ba
     throw err;
   }
 
-  const stats = internalModuleStat(toNamespacedPath(StringPrototypeEndsWith(path, '/') ?
+  const stats = internalFsBinding.internalModuleStat(toNamespacedPath(StringPrototypeEndsWith(path, '/') ?
     StringPrototypeSlice(path, -1) : path));
 
   // Check for stats.isDirectory()
@@ -285,7 +285,7 @@ function finalizeResolution(resolved, ba
   }
 
   if (!preserveSymlinks) {
-    const real = realpathSync(path, {
+    const real = fs.realpathSync(path, {
       [internalFS.realpathCacheKey]: realpathCache,
     });
     const { search, hash } = resolved;
@@ -760,6 +760,8 @@ function packageImportsResolve(name, bas
   throw importNotDefined(name, packageJSONUrl, base);
 }
 
+const electronTypes = ['electron', 'electron/main', 'electron/common', 'electron/renderer'];
+
 /**
  * Returns the package type for a given URL.
  * @param {URL} url - The URL to get the package type for.
@@ -820,6 +822,11 @@ function packageResolve(specifier, base,
     return new URL('node:' + specifier);
   }
 
+  const electronSpecifiers = new SafeSet(electronTypes);
+  if (electronSpecifiers.has(specifier)) {
+    return new URL('electron:electron');
+  }
+
   const { packageName, packageSubpath, isScoped } =
     parsePackageName(specifier, base);
 
@@ -838,7 +845,7 @@ function packageResolve(specifier, base,
   let packageJSONPath = fileURLToPath(packageJSONUrl);
   let lastPath;
   do {
-    const stat = internalModuleStat(toNamespacedPath(StringPrototypeSlice(packageJSONPath, 0,
+    const stat = internalFsBinding.internalModuleStat(toNamespacedPath(StringPrototypeSlice(packageJSONPath, 0,
                                                                           packageJSONPath.length - 13)));
     // Check for !stat.isDirectory()
     if (stat !== 1) {
