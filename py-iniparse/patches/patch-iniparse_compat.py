$NetBSD$

--- iniparse/compat.py.orig	2010-05-08 00:51:42.000000000 +0000
+++ iniparse/compat.py
@@ -12,19 +12,21 @@ The underlying INIConfig object can be a
 """
 
 import re
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
 
 # These are imported only for compatiability.
 # The code below does not reference them directly.
-from ConfigParser import Error, InterpolationError, \
-                  MissingSectionHeaderError, ParsingError
+from .configparser import Error, InterpolationError, \
+                   MissingSectionHeaderError, ParsingError
 
-import ini
+import six
+
+from . import ini
 
 class RawConfigParser(object):
     def __init__(self, defaults=None, dict_type=dict):
@@ -56,7 +58,7 @@ class RawConfigParser(object):
         # The default section is the only one that gets the case-insensitive
         # treatment - so it is special-cased here.
         if section.lower() == "default":
-            raise ValueError, 'Invalid section name: %s' % section
+            raise ValueError('Invalid section name: %s' % section)
 
         if self.has_section(section):
             raise DuplicateSectionError(section)
@@ -88,7 +90,7 @@ class RawConfigParser(object):
         filename may also be given.
         """
         files_read = []
-        if isinstance(filenames, basestring):
+        if isinstance(filenames, six.string_types):
             filenames = [filenames]
         for filename in filenames:
             try:
@@ -143,7 +145,7 @@ class RawConfigParser(object):
     def getboolean(self, section, option):
         v = self.get(section, option)
         if v.lower() not in self._boolean_states:
-            raise ValueError, 'Not a boolean: %s' % v
+            raise ValueError('Not a boolean: %s' % v)
         return self._boolean_states[v.lower()]
 
     def has_option(self, section, option):
@@ -234,7 +236,7 @@ class ConfigParser(RawConfigParser):
             if "%(" in value:
                 try:
                     value = value % vars
-                except KeyError, e:
+                except KeyError as e:
                     raise InterpolationMissingOptionError(
                         option, section, rawval, e.args[0])
             else:
@@ -283,7 +285,7 @@ class SafeConfigParser(ConfigParser):
     _badpercent_re = re.compile(r"%[^%]|%$")
 
     def set(self, section, option, value):
-        if not isinstance(value, basestring):
+        if not isinstance(value, six.string_types):
             raise TypeError("option values must be strings")
         # check for bad percent signs:
         # first, replace all "good" interpolations
