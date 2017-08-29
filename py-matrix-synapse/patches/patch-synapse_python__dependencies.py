$NetBSD$

--- synapse/python_dependencies.py.orig	2017-07-06 17:11:49.000000000 +0000
+++ synapse/python_dependencies.py
@@ -24,7 +24,7 @@ REQUIREMENTS = {
     "unpaddedbase64>=1.1.0": ["unpaddedbase64>=1.1.0"],
     "canonicaljson>=1.0.0": ["canonicaljson>=1.0.0"],
     "signedjson>=1.0.0": ["signedjson>=1.0.0"],
-    "pynacl==0.3.0": ["nacl==0.3.0", "nacl.bindings"],
+    "pynacl>=0.3.0": ["nacl>=0.3.0", "nacl.bindings"],
     "service_identity>=1.0.0": ["service_identity>=1.0.0"],
     "Twisted>=16.0.0": ["twisted>=16.0.0"],
     "pyopenssl>=0.14": ["OpenSSL>=0.14"],
