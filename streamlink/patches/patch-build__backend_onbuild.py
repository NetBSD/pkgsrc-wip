$NetBSD$

Match the call parameters with how it is used by our py-versioningit package.

--- build_backend/onbuild.py.orig	2023-10-26 13:05:52.000000000 +0000
+++ build_backend/onbuild.py
@@ -8,8 +8,8 @@ from typing import Any, Dict, Generator,
 def onbuild(
     build_dir: Union[str, Path],
     is_source: bool,
-    template_fields: Dict[str, Any],
-    params: Dict[str, Any],
+    version: str,
+    params: Dict[str, Any] = {},
 ):
     """
     Remove the ``versioningit`` build-requirement from Streamlink's source distribution.
@@ -25,7 +25,6 @@ def onbuild(
 
     base_dir: Path = Path(build_dir).resolve()
     pkg_dir: Path = base_dir / "src" if is_source else base_dir
-    version: str = template_fields["version"]
     cmproxy: Proxy[str]
 
     # Remove versioningit from ``build-system.requires`` in ``pyproject.toml``
