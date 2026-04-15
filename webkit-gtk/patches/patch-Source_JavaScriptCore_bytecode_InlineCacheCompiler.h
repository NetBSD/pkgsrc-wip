$NetBSD$

Post-2.52.2 release patch.
https://github.com/WebKit/WebKit/commit/346454388ab

--- Source/JavaScriptCore/bytecode/InlineCacheCompiler.h.orig	2026-04-10 11:57:50.844550600 +0000
+++ Source/JavaScriptCore/bytecode/InlineCacheCompiler.h
@@ -528,13 +528,13 @@ static constexpr size_t prologueSizeInBytesDataIC = 1;
 #if CPU(X86_64)
 static constexpr size_t prologueSizeInBytesDataIC = 1;
 #elif CPU(ARM64E)
-static constexpr size_t prologueSizeInBytesDataIC = 4;
+static constexpr size_t prologueSizeInBytesDataIC = 8;
 #elif CPU(ARM64)
-static constexpr size_t prologueSizeInBytesDataIC = 0;
+static constexpr size_t prologueSizeInBytesDataIC = 4;
 #elif CPU(ARM_THUMB2)
-static constexpr size_t prologueSizeInBytesDataIC = 0;
+static constexpr size_t prologueSizeInBytesDataIC = 6;
 #elif CPU(RISCV64)
-static constexpr size_t prologueSizeInBytesDataIC = 0;
+static constexpr size_t prologueSizeInBytesDataIC = 12;
 #else
 #error "unsupported architecture"
 #endif
