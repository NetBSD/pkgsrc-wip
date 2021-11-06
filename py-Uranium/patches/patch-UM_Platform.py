$NetBSD$

Include *BSD in Platform.isLinux()

--- UM/Platform.py.orig	2021-06-25 12:54:09.000000000 +0000
+++ UM/Platform.py
@@ -42,5 +42,7 @@ class Platform:
         __platform_type = PlatformType.Windows
     elif sys.platform == "linux":
         __platform_type = PlatformType.Linux
+    elif "bsd" in sys.platform:
+        __platform_type = PlatformType.Linux
     elif sys.platform == "darwin":
         __platform_type = PlatformType.OSX
