$NetBSD: patch-Source_JavaScriptCore_assembler_ARMAssembler.h,v 1.1 2015/01/24 01:33:08 leot1990 Exp $

--- Source/JavaScriptCore/assembler/ARMAssembler.h.orig	2015-01-15 09:40:35.000000000 +0000
+++ Source/JavaScriptCore/assembler/ARMAssembler.h
@@ -1121,6 +1121,9 @@ namespace JSC {
             linuxPageFlush(current, end);
 #elif OS(WINCE)
             CacheRangeFlush(code, size, CACHE_SYNC_ALL);
+#elif OS(NETBSD)
+            char* begin = reinterpret_cast<char*>(code);
+            __builtin___clear_cache(begin, begin + size);
 #else
 #error "The cacheFlush support is missing on this platform."
 #endif
