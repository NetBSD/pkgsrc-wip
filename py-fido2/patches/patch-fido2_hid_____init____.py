$NetBSD$

--- fido2/hid/__init__.py.orig	2022-10-17 13:36:35.000000000 +0000
+++ fido2/hid/__init__.py
@@ -49,6 +49,8 @@ elif sys.platform.startswith("darwin"):
     from . import macos as backend
 elif sys.platform.startswith("freebsd"):
     from . import freebsd as backend
+elif sys.platform.startswith('netbsd'):
+    from . import netbsd as backend
 elif sys.platform.startswith("openbsd"):
     from . import openbsd as backend
 else:
