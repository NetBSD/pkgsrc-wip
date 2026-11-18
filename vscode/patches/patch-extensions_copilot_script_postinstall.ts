$NetBSD$

* No copilot-cli on NetBSD

--- extensions/copilot/script/postinstall.ts.orig	2026-11-10 19:27:51.000000000 +0000
+++ extensions/copilot/script/postinstall.ts
@@ -293,15 +293,6 @@ async function main() {
 		'node_modules/@github/blackbird-external-ingest-utils/pkg/nodejs/external_ingest_utils_bg.wasm',
 	], 'dist');
 
-	const copilotCliSourceDir = await materializeCopilotCliSdkLayout();
-	await removeCopilotCLIShim();
-	await removeCopilotCliWorkerFiles();
-	await copyCopilotCliDefinitionFiles(copilotCliSourceDir);
-	await copyCopilotCliSkillsFiles(copilotCliSourceDir);
-	await copyCopilotCliTGrepFiles(copilotCliSourceDir);
-	await copyCopilotCliQueryFiles(copilotCliSourceDir);
-	await copyCopilotCliPrebuildFiles(copilotCliSourceDir);
-
 	// Check if the base cache file exists (dev-only sanity check, non-fatal in CI)
 	const baseCachePath = path.join('test', 'simulation', 'cache', 'base.sqlite');
 	if (!fs.existsSync(baseCachePath)) {
