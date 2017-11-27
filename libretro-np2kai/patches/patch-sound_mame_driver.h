$NetBSD$

Fix build on NetBSD (symbol collisions...)

--- sound/mame/driver.h.orig	2017-10-21 10:00:34.000000000 +0000
+++ sound/mame/driver.h
@@ -8,17 +8,7 @@
 #define HAS_Y8950  1
 #define HAS_YMF262 1
 
-#if defined(_MSC_VER)
-#pragma warning(disable: 4244)
-#pragma warning(disable: 4245)
-#define INLINE __inline static
-#elif defined(__BORLANDC__)
-#define INLINE __inline
-#elif defined(__GNUC__)
-#define INLINE __inline__
-#else
-#define INLINE static
-#endif
+#define INLINE static inline
 
 #define logerror(x,y,z)
 //typedef signed int stream_sample_t;
