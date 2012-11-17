$NetBSD: patch-tools_gyp_pylib_gyp_____init____.py,v 1.2 2012/11/17 02:57:12 gduzan Exp $

--- tools/gyp/pylib/gyp/__init__.py.orig	2011-04-13 08:13:20.000000000 +0000
+++ tools/gyp/pylib/gyp/__init__.py
@@ -313,9 +313,12 @@ def main(args):
       options.formats = [ {'darwin':   'xcode',
                            'win32':    'msvs',
                            'cygwin':   'msvs',
+                           'dragonfly2': 'make',
                            'freebsd7': 'make',
                            'freebsd8': 'make',
                            'linux2':   'make',
+                           'netbsd5':  'make',
+                           'netbsd6':  'make',
                            'openbsd4': 'make',
                            'sunos5':   'make',}[sys.platform] ]
 
