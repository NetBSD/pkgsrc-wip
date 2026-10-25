$NetBSD$

* Add support to NetBSD and FreeBSD

--- build/lib/propertyInitOrderChecker.ts.orig	2026-10-24 16:00:54.451696700 +0000
+++ build/lib/propertyInitOrderChecker.ts
@@ -45,7 +45,7 @@ let errorCount = 0;
 function createProgram(tsconfigPath: string): ts.Program {
 	const tsConfig = ts.readConfigFile(tsconfigPath, ts.sys.readFile);
 
-	const configHostParser: ts.ParseConfigHost = { fileExists: fs.existsSync, readDirectory: ts.sys.readDirectory, readFile: file => fs.readFileSync(file, 'utf8'), useCaseSensitiveFileNames: process.platform === 'linux' };
+	const configHostParser: ts.ParseConfigHost = { fileExists: fs.existsSync, readDirectory: ts.sys.readDirectory, readFile: file => fs.readFileSync(file, 'utf8'), useCaseSensitiveFileNames: (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd')  };
 	const tsConfigParsed = ts.parseJsonConfigFileContent(tsConfig.config, configHostParser, path.resolve(path.dirname(tsconfigPath)), { noEmit: true });
 
 	const compilerHost = ts.createCompilerHost(tsConfigParsed.options, true);
