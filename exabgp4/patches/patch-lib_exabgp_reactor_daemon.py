$NetBSD$

Already fixed upstream, but not released
https://github.com/Exa-Networks/exabgp/commit/b4a7028

--- lib/exabgp/reactor/daemon.py.orig	2021-01-28 18:18:19.554094109 +0000
+++ lib/exabgp/reactor/daemon.py
@@ -156,7 +156,7 @@ class Daemon(object):
     def _is_socket(self, fd):
         try:
             s = socket.fromfd(fd, socket.AF_INET, socket.SOCK_RAW)
-        except ValueError:
+        except (OSError, ValueError):
             # The file descriptor is closed
             return False
         try:
