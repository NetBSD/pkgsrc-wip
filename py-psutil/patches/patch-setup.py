$NetBSD$

--- setup.py.orig	2017-11-08 11:29:08.000000000 +0000
+++ setup.py
@@ -33,6 +33,7 @@ from _common import FREEBSD  # NOQA
 from _common import LINUX  # NOQA
 from _common import NETBSD  # NOQA
 from _common import OPENBSD  # NOQA
+from _common import DRAGONFLY  # NOQA
 from _common import OSX  # NOQA
 from _common import POSIX  # NOQA
 from _common import SUNOS  # NOQA
@@ -194,6 +195,17 @@ elif NETBSD:
         ],
         define_macros=macros,
         libraries=["kvm"])
+
+elif DRAGONFLY:
+    macros.append(("PSUTIL_DRAGONFLY", 1))
+    ext = Extension(
+        'psutil._psutil_bsd',
+        sources=sources + [
+            'psutil/_psutil_bsd.c',
+            'psutil/arch/bsd/dragonfly.c',
+        ],
+        define_macros=macros,
+        libraries=["kvm"])
 
 elif LINUX:
     def get_ethtool_macro():
