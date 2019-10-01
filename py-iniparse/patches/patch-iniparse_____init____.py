$NetBSD$

--- iniparse/__init__.py.orig	2010-05-08 19:36:42.000000000 +0000
+++ iniparse/__init__.py
@@ -3,17 +3,17 @@
 # Copyright (c) 2007 Tim Lauridsen <tla@rasmil.dk>
 # All Rights Reserved.  See LICENSE-PSF & LICENSE for details.
 
-from ini import INIConfig, change_comment_syntax
-from config import BasicConfig, ConfigNamespace
-from compat import RawConfigParser, ConfigParser, SafeConfigParser
-from utils import tidy
+from .ini import INIConfig, change_comment_syntax
+from .config import BasicConfig, ConfigNamespace
+from .compat import RawConfigParser, ConfigParser, SafeConfigParser
+from .utils import tidy
 
-from ConfigParser import DuplicateSectionError,    \
-                  NoSectionError, NoOptionError,   \
-                  InterpolationMissingOptionError, \
-                  InterpolationDepthError,         \
-                  InterpolationSyntaxError,        \
-                  DEFAULTSECT, MAX_INTERPOLATION_DEPTH
+from .configparser import DuplicateSectionError,    \
+                   NoSectionError, NoOptionError,   \
+                   InterpolationMissingOptionError, \
+                   InterpolationDepthError,         \
+                   InterpolationSyntaxError,        \
+                   DEFAULTSECT, MAX_INTERPOLATION_DEPTH
 
 __all__ = [
     'BasicConfig', 'ConfigNamespace',
