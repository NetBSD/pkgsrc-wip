$NetBSD$

* Import from chromium

--- src/webrtc/src/build/config/linux/pkg-config.py.orig	2026-11-10 15:46:15.346000000 +0000
+++ src/webrtc/src/build/config/linux/pkg-config.py
@@ -125,7 +125,7 @@ def main():
   # If this is run on non-Linux platforms, just return nothing and indicate
   # success. This allows us to "kind of emulate" a Linux build from other
   # platforms.
-  if "linux" not in sys.platform:
+  if  not sys.platform.startswith(tuple(['linux', 'openbsd', 'freebsd', 'netbsd'])):
     if options.dridriverdir or options.libdir:
       sys.stdout.write("")
       return 0
