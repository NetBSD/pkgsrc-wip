$NetBSD$

--- docutils/writers/odf_odt/__init__.py.orig	2025-07-29 14:37:37.693677400 +0000
+++ docutils/writers/odf_odt/__init__.py
@@ -386,10 +386,9 @@ class Writer(writers.Writer):
             ('Specify a stylesheet.  '
                 'Default: "%s"' % default_stylesheet_path,
                 ['--stylesheet'],
-                {
-                    'default': default_stylesheet_path,
-                    'dest': 'stylesheet'
-                }),
+                {'default': default_stylesheet_path,
+                    'dest': 'stylesheet',
+                    'metavar': '<filename>'}),
             ('Specify an ODF-specific configuration/mapping file '
                 'relative to the current working directory.',
                 ['--odf-config-file'],
