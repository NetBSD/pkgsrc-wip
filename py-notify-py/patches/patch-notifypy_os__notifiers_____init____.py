$NetBSD$

--- notifypy/os_notifiers/__init__.py.orig	2020-07-06 01:31:26.000000000 +0000
+++ notifypy/os_notifiers/__init__.py
@@ -1,3 +1,4 @@
 from .linux import LinuxNotifier
 from .macos import MacOSNotifier
+from .netbsd import NetBSDNotifier
 from .windows import WindowsNotifier
