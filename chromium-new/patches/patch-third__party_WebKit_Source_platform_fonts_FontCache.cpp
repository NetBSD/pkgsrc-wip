$NetBSD$

--- third_party/WebKit/Source/platform/fonts/FontCache.cpp.orig	2016-11-10 20:02:26.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/FontCache.cpp
@@ -61,13 +61,13 @@ using namespace WTF;
 
 namespace blink {
 
-#if !OS(WIN) && !OS(LINUX)
+#if !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD) && !OS(NETBSD)
 FontCache::FontCache()
     : m_purgePreventCount(0)
     , m_fontManager(nullptr)
 {
 }
-#endif // !OS(WIN) && !OS(LINUX)
+#endif // !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD) && !OS(NETBSD)
 
 typedef HashMap<unsigned, std::unique_ptr<FontPlatformData>, WTF::IntHash<unsigned>, WTF::UnsignedWithZeroKeyHashTraits<unsigned>> SizedFontPlatformDataSet;
 typedef HashMap<FontCacheKey, SizedFontPlatformDataSet, FontCacheKeyHash, FontCacheKeyTraits> FontPlatformDataCache;
