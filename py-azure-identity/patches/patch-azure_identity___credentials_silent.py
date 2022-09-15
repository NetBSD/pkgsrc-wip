$NetBSD$

Portability.

--- azure/identity/_credentials/silent.py.orig	2022-04-27 23:35:26.000000000 +0000
+++ azure/identity/_credentials/silent.py
@@ -61,7 +61,7 @@ class SilentAuthenticationCredential(obj
         return self._acquire_token_silent(*scopes, **kwargs)
 
     def _initialize(self):
-        if not self._cache and platform.system() in {"Darwin", "Linux", "Windows"}:
+        if not self._cache and platform.system() in {"Darwin", "Linux", "NetBSD", "Windows"}:
             try:
                 # This credential accepts the user's default cache regardless of whether it's encrypted. It doesn't
                 # create a new cache. If the default cache exists, the user must have created it earlier. If it's
