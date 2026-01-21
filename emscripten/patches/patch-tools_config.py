$NetBSD$

Default cache is in install area. Known issue.
https://github.com/emscripten-core/emscripten/issues/15374

--- tools/config.py.orig	2024-07-18 16:08:07.000000000 +0000
+++ tools/config.py
@@ -33,7 +33,7 @@ WASMER = None
 WASMTIME = None
 WASM_ENGINES: List[List[str]] = []
 FROZEN_CACHE = None
-CACHE = None
+CACHE = os.environ['HOME'] + '/.cache'
 PORTS = None
 COMPILER_WRAPPER = None
 
