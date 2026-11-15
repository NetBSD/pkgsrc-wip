$NetBSD$

* Add Free- and NetBSD support

--- scripts/generate-preload-cache.mjs.orig	2026-10-28 21:49:13.000000000 +0000
+++ scripts/generate-preload-cache.mjs
@@ -20,7 +20,7 @@ const V8_ARGS = ['--predictable'];
 const storagePath = await mkdtemp(join(tmpdir(), 'signal-preload-cache-'));
 
 const argv = [`--js-flags=${V8_ARGS.join(' ')}`];
-if (process.platform === 'linux') {
+if (process.platform === 'linux' || process.platform === 'freebsd' || process.platform === 'netbsd') {
   argv.push('--no-sandbox');
 }
 argv.push('ci.js');
