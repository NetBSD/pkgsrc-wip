$NetBSD$

Support TCP keepalive settings on bNetBSD.

--- src/zinolib/utils.py.orig	2025-04-23 13:18:46.349068884 +0000
+++ src/zinolib/utils.py
@@ -74,6 +74,19 @@ def _enable_keepalive_linux(sock, after_
     sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, max_fails)
 
 
+def _enable_keepalive_netbsd(sock, after_idle_sec, interval_sec, max_fails):
+    """Set TCP keepalive on an open socket.
+
+    It activates after (after_idle_sec) of idleness, then
+    sends a keepalive ping once every (interval_sec) seconds,
+    and closes the connection after (max_fails) failed pings.
+    """
+    sock.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
+    sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, after_idle_sec)
+    sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, interval_sec)
+    sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, max_fails)
+
+
 def _enable_keepalive_osx(sock, after_idle_sec, interval_sec, max_fails):
     """Set TCP keepalive on an open socket.
 
@@ -94,6 +107,7 @@ def enable_socket_keepalive(sock, after_
         "Linux": _enable_keepalive_linux,
         "Darwin": _enable_keepalive_osx,
         "Windows": _enable_keepalive_win,
+        "NetBSD": _enable_keepalive_netbsd,
     }
     plat = platform.system()
     if plat in platforms:
