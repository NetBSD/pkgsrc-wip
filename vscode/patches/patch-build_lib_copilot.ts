$NetBSD$

* Copilot sdk/cli is linux/macos/windows only

--- build/lib/copilot.ts.orig	2026-11-10 19:27:51.000000000 +0000
+++ build/lib/copilot.ts
@@ -230,6 +230,7 @@ export function getCopilotRuntimePrebuil
  * can cross-build targets such as darwin-x64 on arm64 hosts.
  */
 export function ensureCopilotPlatformPackage(platform: string, arch: string, nodeModulesRoot = 'node_modules', options: EnsureNpmPackageOptions = {}): void {
+	return;
 	const copilotPackagePlatformArch = toCopilotPackagePlatformArch(platform, arch);
 	if (!copilotPlatforms.includes(copilotPackagePlatformArch)) {
 		return;
@@ -266,6 +267,7 @@ export function ensureCopilotPlatformPac
  * this artifact is present.
  */
 export function prepareBuiltInCopilotRipgrepShim(platform: string, arch: string, builtInCopilotExtensionDir: string, appNodeModulesDir: string, options: PrepareBuiltInCopilotOptions = {}): void {
+	return;
 	const { nodePlatform, nodeArch } = toNodePlatformArch(platform, arch);
 	const platformArch = `${nodePlatform}-${nodeArch}`;
 	const copilotPackagePlatformArch = toCopilotPackagePlatformArch(platform, arch);
