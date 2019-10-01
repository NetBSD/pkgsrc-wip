$NetBSD$

--- iniparse/ini.py.orig	2010-05-08 19:36:42.000000000 +0000
+++ iniparse/ini.py
@@ -7,7 +7,7 @@
 
 Example:
 
-    >>> from StringIO import StringIO
+    >>> from six import StringIO
     >>> sio = StringIO('''# configure foo-application
     ... [foo]
     ... bar1 = qualia
@@ -16,14 +16,14 @@ Example:
     ... special = 1''')
 
     >>> cfg = INIConfig(sio)
-    >>> print cfg.foo.bar1
+    >>> print(cfg.foo.bar1)
     qualia
-    >>> print cfg['foo-ext'].special
+    >>> print(cfg['foo-ext'].special)
     1
     >>> cfg.foo.newopt = 'hi!'
     >>> cfg.baz.enabled = 0
 
-    >>> print cfg
+    >>> print(cfg)
     # configure foo-application
     [foo]
     bar1 = qualia
@@ -42,9 +42,11 @@ Example:
 # Backward-compatiable with ConfigParser
 
 import re
-from ConfigParser import DEFAULTSECT, ParsingError, MissingSectionHeaderError
+from .configparser import DEFAULTSECT, ParsingError, MissingSectionHeaderError
 
-import config
+import six
+
+from . import config
 
 class LineType(object):
     line = None
@@ -278,6 +280,8 @@ class LineContainer(object):
     value = property(get_value, set_value)
 
     def __str__(self):
+        for c in self.contents:
+            pass#print(c.__str__())
         s = [x.__str__() for x in self.contents]
         return '\n'.join(s)
 
@@ -465,7 +469,7 @@ class INIConfig(config.ConfigNamespace):
         self._sections = {}
         if defaults is None: defaults = {}
         self._defaults = INISection(LineContainer(), optionxformsource=self)
-        for name, value in defaults.iteritems():
+        for name, value in defaults.items():
             self._defaults[name] = value
         if fp is not None:
             self._readfp(fp)
@@ -551,7 +555,7 @@ class INIConfig(config.ConfigNamespace):
 
         for line in readline_iterator(fp):
             # Check for BOM on first line
-            if linecount == 0 and isinstance(line, unicode):
+            if linecount == 0 and isinstance(line, six.text_type):
                 if line[0] == u'\ufeff':
                     line = line[1:]
                     self._bom = True
