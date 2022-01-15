$NetBSD: patch-setup_build.py,v 1.3 2018/02/01 16:05:56 wiz Exp $

- Fix linking against native X.
- Include netbsd in various conditional building criteria.
- Patch in the directory /usr/pkg/share/sip3.9/PyQt5 for
  QtWidgets/QtWidgetsmod.sip etc.

--- setup/build.py.orig	2021-12-17 00:40:19.000000000 +0000
+++ setup/build.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/pkg/bin/python
 # vim:fileencoding=UTF-8:ts=4:sw=4:sta:et:sts=4:ai
 
 __license__   = 'GPL v3'
@@ -8,7 +8,7 @@ __docformat__ = 'restructuredtext en'
 import textwrap, os, shlex, subprocess, glob, shutil, sys, json, errno, sysconfig
 from collections import namedtuple
 
-from setup import Command, islinux, isbsd, isfreebsd, ismacos, ishaiku, SRC, iswindows
+from setup import Command, islinux, isbsd, isfreebsd, ismacos, ishaiku, SRC, iswindows, isnetbsd
 isunix = islinux or ismacos or isbsd or ishaiku
 
 py_lib = os.path.join(sys.prefix, 'libs', 'python%d%d.lib' % sys.version_info[:2])
@@ -116,7 +116,7 @@ def is_ext_allowed(ext):
     only = ext.get('only', '')
     if only:
         only = set(only.split())
-        q = set(filter(lambda x: globals()["is" + x], ["bsd", "freebsd", "haiku", "linux", "macos", "windows"]))
+        q = set(filter(lambda x: globals()["is" + x], ["bsd", "freebsd", "haiku", "linux", "macos", "windows", "netbsd"]))
         return len(q.intersection(only)) > 0
     return True
 
@@ -137,6 +137,8 @@ def parse_extension(ext):
             ans = ext.pop('bsd_' + k, ans)
         elif isfreebsd:
             ans = ext.pop('freebsd_' + k, ans)
+        elif isnetbsd:
+            ans = ext.pop('netbsd_' + k, ans)
         elif ishaiku:
             ans = ext.pop('haiku_' + k, ans)
         else:
@@ -197,6 +199,8 @@ def init_env(debug=False, sanitize=False
         if sanitize:
             cflags.append('-fsanitize-address')
             ldflags.append('-shared-libasan')
+        # QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
+        # ldflags.append('$(COMPILER_RPATH_FLAG)$(X11BASE)/lib')
 
     if islinux:
         cflags.append('-pthread')
@@ -496,6 +500,7 @@ class Build(Command):
             INCLUDEPATH += {freetype}
             DESTDIR = {destdir}
             CONFIG -= create_cmake  # Prevent qmake from generating a cmake build file which it puts in the calibre src directory
+            QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
             ''').format(
                 headers=' '.join(headers), sources=' '.join(sources), others=' '.join(others), destdir=self.d(
                     target), freetype=' '.join(ft_inc_dirs))
@@ -523,6 +528,7 @@ class Build(Command):
             abi_version = f'abi-version = "{pyqt_sip_abi_version()}"'
         sipf = ext.sip_files[0]
         needs_exceptions = 'true' if ext.needs_exceptions else 'false'
+        sip_include_dirs = [os.getenv('SIP_DIR')]
         with open(os.path.join(src_dir, 'pyproject.toml'), 'w') as f:
             f.write(f'''
 [build-system]
@@ -538,6 +544,7 @@ project-factory = "pyqtbuild:PyQtProject
 
 [tool.sip.project]
 sip-files-dir = "."
+sip-include-dirs = {sip_include_dirs}
 {abi_version}
 
 [tool.sip.bindings.pictureflow]