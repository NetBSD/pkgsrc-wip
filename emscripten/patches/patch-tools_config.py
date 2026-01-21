$NetBSD$

Default cache is in install area. Known issue.
https://github.com/emscripten-core/emscripten/issues/15374

--- tools/config.py.orig	2026-01-21 05:22:06.504048502 +0000
+++ tools/config.py
@@ -24,7 +24,7 @@ LLVM_ADD_VERSION = None
 CLANG_ADD_VERSION = None
 CLOSURE_COMPILER = None
 FROZEN_CACHE = None
-CACHE = None
+CACHE = os.environ['HOME'] + '/.cache'
 PORTS = None
 COMPILER_WRAPPER = None
 
