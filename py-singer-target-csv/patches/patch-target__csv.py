$NetBSD$

Add support for Python >= 3.4.

--- target_csv.py.orig	2024-03-24 10:58:29.672667873 +0000
+++ target_csv.py
@@ -10,9 +10,14 @@ import threading
 import http.client
 import urllib
 from datetime import datetime
-import collections
 import pkg_resources
 
+try:
+   # Since Python 3.3 MutableMapping is part of collections.abc.
+   import collections.abc as collections
+except ModuleNotFoundError:
+   import collections
+
 from jsonschema.validators import Draft4Validator
 import singer
 
