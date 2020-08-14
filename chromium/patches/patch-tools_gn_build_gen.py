$NetBSD$

https://gn-review.googlesource.com/c/gn/+/9700

--- tools/gn/build/gen.py.orig	2020-06-25 09:40:29.000000000 +0000
+++ tools/gn/build/gen.py
@@ -45,6 +45,8 @@ class Platform(object):
       self._platform = 'fuchsia'
     elif self._platform.startswith('freebsd'):
       self._platform = 'freebsd'
+    elif self._platform.startswith('netbsd'):
+      self._platform = 'netbsd'
     elif self._platform.startswith('openbsd'):
       self._platform = 'openbsd'
     elif self._platform.startswith('haiku'):
@@ -52,7 +54,7 @@ class Platform(object):
 
   @staticmethod
   def known_platforms():
-    return ['linux', 'darwin', 'mingw', 'msvc', 'aix', 'fuchsia', 'freebsd', 'openbsd', 'haiku']
+    return ['linux', 'darwin', 'mingw', 'msvc', 'aix', 'fuchsia', 'freebsd', 'netbsd', 'openbsd', 'haiku']
 
   def platform(self):
     return self._platform
@@ -78,8 +80,20 @@ class Platform(object):
   def is_haiku(self):
     return self._platform == 'haiku'
 
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
+  def is_netbsd(self):
+    return self._platform == 'netbsd'
+
+  def is_openbsd(self):
+    return self._platform == 'openbsd'
+
+  def is_bsd(self):
+    return self._platform in ['freebsd', 'openbsd', 'netbsd']
+
   def is_posix(self):
-    return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd', 'haiku']
+    return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd', 'haiku', 'netbsd']
 
 
 def main(argv):
@@ -203,6 +217,7 @@ def WriteGenericNinja(path, static_libra
       'aix': 'build_aix.ninja.template',
       'openbsd': 'build_openbsd.ninja.template',
       'haiku': 'build_haiku.ninja.template',
+      'netbsd': 'build_linux.ninja.template',
   }[platform.platform()])
 
   with open(template_filename) as f:
