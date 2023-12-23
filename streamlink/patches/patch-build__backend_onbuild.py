$NetBSD$

Match the call parameters with how it is used by our py-versioningit package.

--- build_backend/onbuild.py.orig	2023-12-16 06:18:37.000000000 +0000
+++ build_backend/onbuild.py
@@ -18,11 +18,12 @@ except ImportError:  # pragma: no cover
 def onbuild(
     *,
     is_source: bool,
-    template_fields: Dict[str, Any],
-    params: Dict[str, Any],
+    template_fields: Optional[Dict[str, Any]] = {},
+    params: Optional[Dict[str, Any]] = {},
     # backward compatibility for `versioningit <3.0.0`
     build_dir: Optional[Union[str, Path]] = None,
     file_provider: Optional[SetuptoolsFileProvider] = None,
+    version: Optional[str] = None
 ):
     """
     Remove the ``versioningit`` build-requirement from Streamlink's source distribution.
@@ -45,7 +46,8 @@ def onbuild(
         raise RuntimeError("Missing file_provider or build_dir")
 
     pkg_dir: Path = base_dir / "src" if is_source else base_dir
-    version: str = template_fields["version"]
+    if version == None:
+        version = template_fields["version"]
     cmproxy: Proxy[str]
 
     # Remove versioningit from ``build-system.requires`` in ``pyproject.toml``
