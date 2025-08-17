$NetBSD$

--- docutils/writers/_html_base.py.orig	2025-07-29 14:37:37.539381000 +0000
+++ docutils/writers/_html_base.py
@@ -115,16 +115,16 @@ class Writer(writers.Writer):
          ('Disable compact simple field lists.',
           ['--no-compact-field-lists'],
           {'dest': 'compact_field_lists', 'action': 'store_false'}),
-         ('Added to standard table classes. '
+         ('Class value(s) assigned to all tables. '
           'Defined styles: borderless, booktabs, '
           'align-left, align-center, align-right, '
           'colwidths-auto, colwidths-grid.',
           ['--table-style'],
-          {'default': ''}),
+          {'metavar': '<style>', 'default': ''}),
          ('Math output format (one of "MathML", "HTML", "MathJax", '
           'or "LaTeX") and option(s). (default: "MathML")',
           ['--math-output'],
-          {'default': 'MathML',
+          {'metavar': '<format [option(s)]>', 'default': 'MathML',
            'validator': frontend.validate_math_output}),
          ('Prepend an XML declaration. ',
           ['--xml-declaration'],
