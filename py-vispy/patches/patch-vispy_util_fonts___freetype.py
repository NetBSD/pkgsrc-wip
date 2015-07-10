$NetBSD: patch-vispy_util_fonts___freetype.py,v 1.1 2015/07/10 22:28:02 jihbed Exp $

--- vispy/util/fonts/_freetype.py.orig	2015-05-22 18:29:37.000000000 +0000
+++ vispy/util/fonts/_freetype.py
@@ -14,6 +14,8 @@ import numpy as np
 from ._vispy_fonts import _vispy_fonts, _get_vispy_font_filename
 if sys.platform.startswith('linux'):
     from ...ext.fontconfig import find_font
+if sys.platform.startswith('netbsd6'):
+    from ...ext.fontconfig import find_font
 elif sys.platform.startswith('win'):
     from ._win32 import find_font  # noqa, analysis:ignore
 else:
