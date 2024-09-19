$NetBSD: patch-setup.py,v 1.1 2015/01/18 21:33:00 jihbed Exp $

--- setup.py.orig	2015-01-18 21:14:29.000000000 +0100
+++ setup.py	2015-01-18 21:14:56.000000000 +0100
@@ -56,14 +56,14 @@
         'Topic :: Office/Business :: News/Diary',
         'Topic :: Office/Business :: Scheduling'],
     packages=['etmTk'],
-    scripts=['etm'],
+    scripts=['etm'+sys.version[0:3]],
     # install_requires=REQUIRES,
     # extras_require={"icalendar": EXTRAS},
     # package_data={'etmTk': ['etmlogo.*', 'CHANGES', 'etmtk.desktop', 'etmtk.1', 'etmtk.xpm']},
     package_data={'etmTk': ['etm.desktop', 'etm.appdata.xml', 'CHANGES', 'etm.1', 'etm.xpm'],
                   'etmTk/help' : ['help/UserManual.html', ]},
     data_files=[
-        ('share/man/man1', ['etmTk/etm.1']),
+        ('man/man1', ['etmTk/etm.1']),
         ('share/doc/etm', ['etmTk/CHANGES']),
         ('share/pixmaps', ['etmTk/etm.xpm']),
         ('share/applications', ['etmTk/etm.desktop']),
