$NetBSD: patch-setup_extensions.py,v 1.1 2014/04/06 21:27:39 rhialto Exp $

Correct directory name.

--- setup/extensions.py.orig	2014-04-04 02:33:40.000000000 +0000
+++ setup/extensions.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/pkg/bin/python2.7
 # vim:fileencoding=UTF-8:ts=4:sw=4:sta:et:sts=4:ai
 from __future__ import with_statement
 
@@ -567,7 +567,7 @@ class Build(Command):
             self.check_call(qmc + ['qtcurve.pro'])
             self.check_call([make]+([] if iswindows else ['-j%d'%(cpu_count()
                 or 1)]))
-            src = (glob.glob('*.so') + glob.glob('release/*.dll') +
+            src = (glob.glob('.libs/*.so') + glob.glob('release/*.dll') +
                     glob.glob('*.dylib'))
             ext = 'pyd' if iswindows else 'so'
             if not os.path.exists(dest):
