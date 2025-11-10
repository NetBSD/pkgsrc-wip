$NetBSD: patch-setup_build.py,v 1.5 2022/01/20 19:03:07 rhialto Exp $

- Fix linking against native X.
- Include netbsd in various conditional building criteria.
- Patch in the directory /usr/pkg/share/sip3.9/PyQt5 for
  QtWidgets/QtWidgetsmod.sip etc.
- Define the %Platform value WS_X11, so that Q_PID gets defined in
  PyQt5/QtCore/qprocess.sip.
- Autodetection of the sip API version of PyQt5.so fails because sip 4
  does not write the QtCore.toml file with that information.

--- setup/build.py.orig	2025-11-10 11:05:21.260333637 +0000
+++ setup/build.py
@@ -17,7 +17,7 @@ import textwrap
 from functools import partial
 from typing import NamedTuple
 
-from setup import SRC, Command, isbsd, isfreebsd, ishaiku, islinux, ismacos, iswindows
+from setup import SRC, Command, isbsd, isfreebsd, ishaiku, islinux, ismacos, isnetbsd, iswindows
 
 isunix = islinux or ismacos or isbsd or ishaiku
 
@@ -120,7 +120,7 @@ def is_ext_allowed(cross_compile_for: st
         if islinux and only == cross_compile_for:
             return True
         only = set(only.split())
-        q = set(filter(lambda x: globals()['is' + x], ['bsd', 'freebsd', 'haiku', 'linux', 'macos', 'windows']))
+        q = set(filter(lambda x: globals()['is' + x], ['bsd', 'freebsd', 'haiku', 'linux', 'macos', 'netbsd', 'windows']))
         return len(q.intersection(only)) > 0
     return True
 
@@ -139,6 +139,8 @@ def parse_extension(ext, compiling_for='
         get_key = 'bsd_'
     elif isfreebsd:
         get_key = 'freebsd_'
+    elif isnetbsd:
+        get_key = 'netbsd_'
     elif ishaiku:
         get_key = 'haiku_'
     if compiling_for == 'windows':
