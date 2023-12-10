$NetBSD$

Handle NetBSD as Linux.

--- setup.py.orig	2023-12-04 20:06:55.000000000 +0000
+++ setup.py
@@ -16,7 +16,7 @@ from setuptools import setup
 from setuptools.command.build_ext import build_ext as build_ext_orig
 
 IS_MAC = sys.platform == "darwin"
-IS_LINUX = "linux" in sys.platform
+IS_LINUX = "linux" in sys.platform or "netbsd" in sys.platform
 
 LIBBACKTRACE_LOCATION = (
     pathlib.Path(__file__).parent / "src" / "vendor" / "libbacktrace"
