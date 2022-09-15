$NetBSD$

Portability.

--- azure/identity/_internal/shared_token_cache.py.orig	2022-04-27 23:35:26.000000000 +0000
+++ azure/identity/_internal/shared_token_cache.py
@@ -229,4 +229,4 @@ class SharedTokenCacheBase(ABC):
 
         :rtype: bool
         """
-        return platform.system() in {"Darwin", "Linux", "Windows"}
+        return platform.system() in {"Darwin", "Linux", "NetBSD", "Windows"}
