$NetBSD$

--- third_party/WebKit/Source/platform/fonts/FontCache.cpp.orig	2016-06-24 01:02:46.000000000 +0000
+++ third_party/WebKit/Source/platform/fonts/FontCache.cpp
@@ -59,13 +59,13 @@ using namespace WTF;
 
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
 
 typedef HashMap<FontCacheKey, OwnPtr<FontPlatformData>, FontCacheKeyHash, FontCacheKeyTraits> FontPlatformDataCache;
 typedef HashMap<FallbackListCompositeKey, OwnPtr<ShapeCache>, FallbackListCompositeKeyHash, FallbackListCompositeKeyTraits> FallbackListShaperCache;
