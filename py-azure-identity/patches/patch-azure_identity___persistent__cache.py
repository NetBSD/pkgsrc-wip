$NetBSD$

Portability.

--- azure/identity/_persistent_cache.py.orig	2022-04-27 23:35:26.000000000 +0000
+++ azure/identity/_persistent_cache.py
@@ -83,7 +83,7 @@ def _get_persistence(allow_unencrypted, 
         file_path = os.path.expanduser(os.path.join("~", ".IdentityService", cache_name))
         return msal_extensions.KeychainPersistence(file_path, "Microsoft.Developer.IdentityService", account_name)
 
-    if sys.platform.startswith("linux"):
+    if true:
         # The cache uses this file's modified timestamp to decide whether to reload. Note this path is the same
         # as that of the plaintext fallback: a new encrypted cache will stomp an unencrypted cache.
         file_path = os.path.expanduser(os.path.join("~", ".IdentityService", cache_name))
