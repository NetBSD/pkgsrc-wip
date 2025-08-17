$NetBSD$

--- docutils/writers/html4css1/__init__.py.orig	2025-07-29 14:37:37.693212000 +0000
+++ docutils/writers/html4css1/__init__.py
@@ -74,7 +74,7 @@ class Writer(writers._html_base.Writer):
             'Math output format (one of "MathML", "HTML", "MathJax", or '
             '"LaTeX") and option(s). (default: "HTML math.css")',
             ['--math-output'],
-            {'default': 'HTML math.css',
+            {'metavar': '<format [option(s)]>', 'default': 'HTML math.css',
              'validator': frontend.validate_math_output}),
         xml_declaration=(
             'Prepend an XML declaration (default). ',
