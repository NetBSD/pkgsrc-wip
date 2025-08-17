$NetBSD$

--- docutils/writers/xetex/__init__.py.orig	2025-07-29 14:37:37.839053600 +0000
+++ docutils/writers/xetex/__init__.py
@@ -57,7 +57,8 @@ class Writer(latex2e.Writer):
         latex_preamble=('Customization by LaTeX code in the preamble. '
                         'Default: select "Linux Libertine" fonts.',
                         ['--latex-preamble'],
-                        {'default': default_preamble}),
+                        {'metavar': '<preamble>',
+                         'default': default_preamble}),
         )
 
     def __init__(self) -> None:
