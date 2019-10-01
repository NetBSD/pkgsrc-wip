$NetBSD$

--- iniparse/config.py.orig	2010-05-08 19:55:43.000000000 +0000
+++ iniparse/config.py
@@ -143,7 +143,7 @@ class BasicConfig(ConfigNamespace):
 
     >>> n.aaa = 42
     >>> del n.x
-    >>> print n
+    >>> print(n)
     aaa = 42
     name.first = paramjit
     name.last = oberoi
@@ -152,7 +152,7 @@ class BasicConfig(ConfigNamespace):
 
     >>> isinstance(n.name, ConfigNamespace)
     True
-    >>> print n.name
+    >>> print(n.name)
     first = paramjit
     last = oberoi
     >>> sorted(list(n.name))
@@ -160,7 +160,7 @@ class BasicConfig(ConfigNamespace):
 
     Finally, values can be read from a file as follows:
 
-    >>> from StringIO import StringIO
+    >>> from six import StringIO
     >>> sio = StringIO('''
     ... # comment
     ... ui.height = 100
@@ -171,7 +171,7 @@ class BasicConfig(ConfigNamespace):
     ... ''')
     >>> n = BasicConfig()
     >>> n._readfp(sio)
-    >>> print n
+    >>> print(n)
     complexity = medium
     data.secret.password = goodness=gracious me
     have_python
@@ -199,7 +199,7 @@ class BasicConfig(ConfigNamespace):
 
     def __str__(self, prefix=''):
         lines = []
-        keys = self._data.keys()
+        keys = list(self._data.keys())
         keys.sort()
         for name in keys:
             value = self._data[name]
@@ -258,7 +258,7 @@ def update_config(target, source):
     >>> n.ui.display_clock = True
     >>> n.ui.display_qlength = True
     >>> n.ui.width = 150
-    >>> print n
+    >>> print(n)
     playlist.expand_playlist = True
     ui.display_clock = True
     ui.display_qlength = True
@@ -267,7 +267,7 @@ def update_config(target, source):
     >>> from iniparse import ini
     >>> i = ini.INIConfig()
     >>> update_config(i, n)
-    >>> print i
+    >>> print(i)
     [playlist]
     expand_playlist = True
     <BLANKLINE>
@@ -277,7 +277,7 @@ def update_config(target, source):
     width = 150
 
     """
-    for name in source:
+    for name in sorted(source):
         value = source[name]
         if isinstance(value, ConfigNamespace):
             if name in target:
