$NetBSD$

--- third_party/WebKit/Source/platform/fonts/FontCache.cpp.orig	2017-02-02 02:03:10.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/FontCache.cpp
@@ -62,9 +62,9 @@ using namespace WTF;
 
 namespace blink {
 
-#if !OS(WIN) && !OS(LINUX)
+#if !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD) && !OS(NETBSD)
 FontCache::FontCache() : m_purgePreventCount(0), m_fontManager(nullptr) {}
-#endif  // !OS(WIN) && !OS(LINUX)
+#endif  // !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD)
 
 typedef HashMap<unsigned,
                 std::unique_ptr<FontPlatformData>,
