$NetBSD$

In file included from /scratch/wip/webkit-gtk-2.46/work/webkitgtk-2.50.0/cmake-pkgsrc-build/JavaScriptCore/DerivedSources/unified-sources/UnifiedSource-f2e18ffc-20.cpp:5:
/scratch/wip/webkit-gtk-2.46/work/webkitgtk-2.50.0/Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp: In lambda function:
/scratch/wip/webkit-gtk-2.46/work/webkitgtk-2.50.0/Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp:122:49: error: 'NT_GNU_BUILD_ID' was not declared in this scope
  122 |                             if (note->n_type == NT_GNU_BUILD_ID && note->n_descsz != 0 && note->n_namesz == 4 && memcmp(name, "GNU", 4) == 0) {
      |                                                 ^~~~~~~~~~~~~~~


--- Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp.orig	2025-09-23 16:42:34.984982333 +0000
+++ Source/JavaScriptCore/runtime/JSCBytecodeCacheVersion.cpp
@@ -66,7 +66,7 @@ uint32_t computeJSCBytecodeCacheVersion(
         }
         cacheVersion.construct(0);
         dataLogLnIf(JSCBytecodeCacheVersionInternal::verbose, "Failed to get UUID for JavaScriptCore framework");
-#elif OS(UNIX) && !PLATFORM(PLAYSTATION) && !OS(HAIKU)
+#elif OS(UNIX) && !PLATFORM(PLAYSTATION) && !OS(HAIKU) && !OS(NETBSD)
         auto result = ([&] -> std::optional<uint32_t> {
             Dl_info info { };
             if (!dladdr(jsFunctionAddr, &info))
