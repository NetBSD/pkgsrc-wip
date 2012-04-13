$NetBSD: patch-gyptest.py,v 1.1 2012/04/13 22:38:16 ryo-on Exp $

--- gyptest.py.orig	2012-04-13 19:32:07.000000000 +0000
+++ gyptest.py
@@ -208,6 +208,9 @@ def main(argv=None):
     format_list = {
       'freebsd7': ['make'],
       'freebsd8': ['make'],
+      'freebsd9': ['make'],
+      'netbsd5': ['make'],
+      'netbsd6': ['make'],
       'cygwin':   ['msvs'],
       'win32':    ['msvs', 'ninja'],
       'linux2':   ['make', 'ninja'],
