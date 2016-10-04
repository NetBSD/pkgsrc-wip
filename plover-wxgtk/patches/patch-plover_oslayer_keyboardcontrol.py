$NetBSD$

Add NetBSD to supported platforms.

--- plover/oslayer/keyboardcontrol.py.orig	2016-04-02 21:25:51.000000000 +0000
+++ plover/oslayer/keyboardcontrol.py
@@ -21,7 +21,7 @@ import sys
 KEYBOARDCONTROL_NOT_FOUND_FOR_OS = \
         "No keyboard control module was found for os %s" % sys.platform
 
-if sys.platform.startswith('linux'):
+if sys.platform.startswith('linux') or sys.platform.startswith('netbsd'):
     from plover.oslayer import xkeyboardcontrol as keyboardcontrol
 elif sys.platform.startswith('win32'):
     from plover.oslayer import winkeyboardcontrol as keyboardcontrol
