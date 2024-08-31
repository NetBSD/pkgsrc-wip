$NetBSD$

Install manpages in ${PKGMANDIR}.

--- setup.py.orig	2024-08-12 13:19:52.995938500 +0000
+++ setup.py
@@ -1,6 +1,6 @@
 #!/usr/bin/env python
 import sys
-from os import path
+from os import getenv, path
 from textwrap import dedent
 
 
@@ -64,7 +64,7 @@ data_files = [
     # man page
     #  requires pre-built man page file via sphinx (docs-requirements.txt)
     #  `make --directory=docs clean man`
-    ("share/man/man1", ["docs/_build/man/streamlink.1"]),
+    (getenv("PKGMANDIR") + "/man1", ["docs/_build/man/streamlink.1"]),
 ]
 data_files = [
     (destdir, [file for file in srcfiles if path.exists(file)])
