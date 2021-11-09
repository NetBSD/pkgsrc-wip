$NetBSD$

Adapt for CacheControl 0.12.10.
https://github.com/trailofbits/pip-audit/commit/185c7a27ee40bfe333b95deeb71f937680d8ed8c

--- pip_audit/service/pypi.py.orig	2021-11-09 16:12:41.000000000 +0000
+++ pip_audit/service/pypi.py
@@ -44,7 +44,7 @@ class _SafeFileCache(FileCache):
                 self._logged_warning = True
             return None
 
-    def set(self, key: str, value: bytes) -> None:
+    def set(self, key: str, value: bytes, expires: Optional[Any] = None) -> None:
         try:
             self._set_impl(key, value)
         except Exception as e:  # pragma: no cover
