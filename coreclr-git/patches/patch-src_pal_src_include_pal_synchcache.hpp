$NetBSD$

--- src/pal/src/include/pal/synchcache.hpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/include/pal/synchcache.hpp
@@ -143,7 +143,7 @@ namespace CorUnix
                 return;
             }
 
-            pobj->~T();
+//            pobj->~T();
             
             Lock(pthrCurrent);
             if (m_iDepth < m_iMaxDepth)
@@ -394,4 +394,3 @@ namespace CorUnix
 }
 
 #endif // _SYNCH_CACHE_H_
-
