$NetBSD$

* Don't package os-proxy-resolver (diagnostic/telemetry)

--- build/lib/osProxyResolver.ts.orig	2026-11-10 19:27:51.000000000 +0000
+++ build/lib/osProxyResolver.ts
@@ -47,6 +47,7 @@ export function getOSProxyResolverExclud
 }
 
 export function ensureOSProxyResolverPlatformPackage(platform: string, arch: string, nodeModulesRoot = 'node_modules', options: EnsureNpmPackageOptions = {}): void {
+	return;
 	const target = toOSProxyResolverPlatform(platform, arch);
 	if (target) {
 		ensureNpmPackage(`@vscode/os-proxy-resolver-${target}`, nodeModulesRoot, options);
