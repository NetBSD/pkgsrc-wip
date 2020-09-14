$NetBSD$

--- notifypy/notify.py.orig	2020-07-06 01:33:23.000000000 +0000
+++ notifypy/notify.py
@@ -14,7 +14,7 @@ from .exceptions import (
     InvalidAudioFormat,
 )
 
-from .os_notifiers import LinuxNotifier, MacOSNotifier, WindowsNotifier
+from .os_notifiers import LinuxNotifier, MacOSNotifier, NetBSDNotifier, WindowsNotifier
 
 from .os_notifiers._base import BaseNotifier
 
@@ -86,6 +86,8 @@ class Notify:
         if selected_platform == "Linux":
 
             return LinuxNotifier
+        elif selected_platform == "NetBSD":
+            return  NetBSDNotifier
         elif selected_platform == "Darwin":
 
             return MacOSNotifier
