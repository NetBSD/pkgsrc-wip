$NetBSD$

* Disabling dts generation (yuku has no NetBSD binding)

--- packages/types/tsdown.config.mjs.orig	2026-10-28 21:49:13.000000000 +0000
+++ packages/types/tsdown.config.mjs
@@ -6,12 +6,12 @@ import { defineConfig } from 'tsdown';
 export default defineConfig({
   entry: 'src/index.std.ts',
   outDir: 'dist',
-  dts: true,
+  dts: false,
   sourcemap: true,
   format: {
     esm: {},
     cjs: {},
   },
-  publint: true,
-  attw: true,
+  publint: false,
+  attw: false,
 });
