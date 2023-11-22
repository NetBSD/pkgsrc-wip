$NetBSD$

Install manpages in ${PKGMANDIR}.

--- setup.py.orig	2023-10-26 13:06:48.891519800 +0000
+++ setup.py
@@ -1,5 +1,5 @@
 #!/usr/bin/env python
-from os import path
+from os import getenv, path
 from sys import argv, exit, version_info
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
