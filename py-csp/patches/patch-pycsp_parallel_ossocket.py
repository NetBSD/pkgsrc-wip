$NetBSD$

--- pycsp/parallel/ossocket.py.orig	2016-04-20 17:39:32.000000000 +0000
+++ pycsp/parallel/ossocket.py
@@ -23,33 +23,13 @@ STDERR_OUTPUT = False
 conf = Configuration()    
 
 # Functions for retrieving LAN ip addresses
-if os.name != "nt":
-    import fcntl
-    import struct
-    
-    def _get_interface_ip(ifname):
-        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
-        ip = socket.inet_ntoa(fcntl.ioctl(
-                s.fileno(),
-                0x8915,  # SIOCGIFADDR
-                struct.pack('256s', ifname[:15])
-                )[20:24])
-        s.close()
-        return ip
-    
 def _get_ip():
-    ip = socket.gethostbyname(socket.gethostname())
-    if ip.startswith("127.") and os.name != "nt":
-        interfaces = ["eth0","eth1","eth2","wlan0","wlan1","wifi0","ath0","ath1","ppp0"]
-        for ifname in interfaces:
-            try:
-                ip = _get_interface_ip(ifname)
-                break;
-            except IOError:
-                pass
+    from netifaces import interfaces, ifaddresses, AF_INET
+    for ifname in interfaces():
+        ip = [i['addr'] for i in ifaddresses(ifname).setdefault(AF_INET, [{'addr':'No IP addr'}] )][0]
+        if not ip.startswith("127."):
+            break
     return ip
-    
-
 
 def _connect(addr, reconnect=True):
     """
@@ -329,5 +309,3 @@ class ConnHandler(object):
             sock.close()
 
         self.cacheSockets = {}
-
-
