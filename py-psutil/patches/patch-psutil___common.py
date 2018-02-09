$NetBSD$

--- psutil/_common.py.orig	2017-12-07 10:02:52.000000000 +0000
+++ psutil/_common.py
@@ -43,7 +43,7 @@ PY3 = sys.version_info[0] == 3
 __all__ = [
     # constants
     'FREEBSD', 'BSD', 'LINUX', 'NETBSD', 'OPENBSD', 'OSX', 'POSIX', 'SUNOS',
-    'WINDOWS',
+    'WINDOWS', 'DRAGONFLY',
     'ENCODING', 'ENCODING_ERRS', 'AF_INET6',
     # connection constants
     'CONN_CLOSE', 'CONN_CLOSE_WAIT', 'CONN_CLOSING', 'CONN_ESTABLISHED',
@@ -79,7 +79,8 @@ OSX = sys.platform.startswith("darwin")
 FREEBSD = sys.platform.startswith("freebsd")
 OPENBSD = sys.platform.startswith("openbsd")
 NETBSD = sys.platform.startswith("netbsd")
-BSD = FREEBSD or OPENBSD or NETBSD
+DRAGONFLY = sys.platform.startswith("dragonfly")
+BSD = FREEBSD or OPENBSD or NETBSD or DRAGONFLY
 SUNOS = sys.platform.startswith("sunos") or sys.platform.startswith("solaris")
 AIX = sys.platform.startswith("aix")
 
