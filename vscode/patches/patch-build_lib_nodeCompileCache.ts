$NetBSD$

* Disable generate node compile cache

--- build/lib/nodeCompileCache.ts.orig	2026-10-27 20:18:03.000000000 +0000
+++ build/lib/nodeCompileCache.ts
@@ -29,7 +29,8 @@ export function shouldGenerateNodeCompil
 		return false;
 	}
 
-	return platform === 'darwin' ? arch === 'arm64' : (platform === 'linux' || platform === 'win32') && arch === 'x64';
+//	return platform === 'darwin' ? arch === 'arm64' : (platform === 'linux' || platform === 'win32') && arch === 'x64';
+	return false;
 }
 
 export function getNodeCompileCachePaths(platform: string, outputDirectory: string, versionedResourcesFolder: string, product: INodeCompileCacheProduct): INodeCompileCachePaths {
