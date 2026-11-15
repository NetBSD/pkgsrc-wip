$NetBSD$

* Import from chromium

--- src/webrtc/src/build/detect_host_arch.py.orig	2026-11-10 15:46:15.373000000 +0000
+++ src/webrtc/src/build/detect_host_arch.py
@@ -24,6 +24,8 @@ def HostArch():
     host_arch = 'arm'
   elif host_arch.startswith('aarch64'):
     host_arch = 'arm64'
+  elif host_arch.startswith('arm64'):
+    host_arch = 'arm64'
   elif host_arch.startswith('mips64'):
     host_arch = 'mips64'
   elif host_arch.startswith('mips'):
