$NetBSD$

https://github.com/trailofbits/pip-audit/issues/115

--- pip_audit/dependency_source/resolvelib/pypi_provider.py.orig	2021-11-09 16:11:51.000000000 +0000
+++ pip_audit/dependency_source/resolvelib/pypi_provider.py
@@ -13,7 +13,7 @@ from operator import attrgetter
 from platform import python_version
 from tarfile import TarFile
 from tempfile import TemporaryDirectory
-from typing import List, Optional, Set
+from typing import BinaryIO, List, Optional, Set, cast
 from urllib.parse import urlparse
 from zipfile import ZipFile
 
@@ -42,8 +42,8 @@ class Candidate:
         self,
         name: str,
         version: Version,
-        url: Optional[str] = None,
-        extras: bool = None,
+        url: str,
+        extras: Set[str],
         is_wheel: bool = True,
         state: Optional[AuditState] = None,
     ) -> None:
@@ -89,7 +89,7 @@ class Candidate:
         """
         Computes the dependency set for this candidate.
         """
-        deps = self.metadata.get_all("Requires-Dist", [])
+        deps: List[str] = self.metadata.get_all("Requires-Dist", [])
         extras = self.extras if self.extras else [""]
 
         for d in deps:
@@ -125,7 +125,9 @@ class Candidate:
             for n in z.namelist():
                 if n.endswith(".dist-info/METADATA"):
                     p = BytesParser()
-                    return p.parse(z.open(n), headersonly=True)
+                    # NOTE: MyPy bug? ZipFile.open is treated as IO[bytes], which
+                    # should be unified with BinaryIO but isn't.
+                    return p.parse(cast(BinaryIO, z.open(n)), headersonly=True)
 
         # If we didn't find the metadata, return an empty dict
         return EmailMessage()  # pragma: no cover
