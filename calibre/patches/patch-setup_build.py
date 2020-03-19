$NetBSD: patch-setup_build.py,v 1.3 2018/02/01 16:05:56 wiz Exp $

Fix linking against native X.

--- setup/build.py.orig	2020-02-21 03:27:12.000000000 +0000
+++ setup/build.py
@@ -412,6 +412,7 @@ class Build(Command):
             INCLUDEPATH += {freetype}
             DESTDIR = {destdir}
             CONFIG -= create_cmake  # Prevent qmake from generating a cmake build file which it puts in the calibre src directory
+            QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
             ''').format(
                 headers=' '.join(headers), sources=' '.join(sources), others=' '.join(others), destdir=self.d(
                     target), freetype=' '.join(ft_inc_dirs))
@@ -472,6 +473,7 @@ class Build(Command):
         SOURCES = {sources}
         INCLUDEPATH += {sipinc} {pyinc}
         VERSION = {ver}
+        QMAKE_LFLAGS += $(COMPILER_RPATH_FLAG)$(X11BASE)/lib
         win32 {{
             LIBS += {py_lib}
             TARGET_EXT = .dll
