$NetBSD$

* error: 'NT_GNU_BUILD_ID' was not declared in this scope

--- Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp.orig	2025-05-16 15:15:18.011632366 +0000
+++ Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp
@@ -66,7 +66,7 @@ uint32_t computeJSCBytecodeCacheVersion(
         }
         cacheVersion.construct(0);
         dataLogLnIf(JSCBytecodeCacheVersionInternal::verbose, "Failed to get UUID for JavaScriptCore framework");
-#elif OS(UNIX) && !PLATFORM(PLAYSTATION)
+#elif OS(UNIX) && !PLATFORM(PLAYSTATION) && !OS(NETBSD)
         auto result = ([&] -> std::optional<uint32_t> {
             Dl_info info { };
             if (!dladdr(jsFunctionAddr, &info))
