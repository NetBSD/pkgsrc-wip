$NetBSD$

--- psutil/__init__.py.orig	2017-12-09 11:29:06.000000000 +0000
+++ psutil/__init__.py
@@ -81,6 +81,7 @@ from ._common import FREEBSD  # NOQA
 from ._common import LINUX
 from ._common import NETBSD  # NOQA
 from ._common import OPENBSD  # NOQA
+from ._common import DRAGONFLY # NOQA
 from ._common import OSX
 from ._common import POSIX  # NOQA
 from ._common import SUNOS
@@ -201,7 +202,7 @@ __all__ = [
     "POWER_TIME_UNKNOWN", "POWER_TIME_UNLIMITED",
 
     "BSD", "FREEBSD", "LINUX", "NETBSD", "OPENBSD", "OSX", "POSIX", "SUNOS",
-    "WINDOWS", "AIX",
+    "WINDOWS", "AIX", "DRAGONFLY"
 
     # classes
     "Process", "Popen",
