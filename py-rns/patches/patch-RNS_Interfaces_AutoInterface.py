$NetBSD$

https://github.com/gdt/Reticulum/commits/fix-transmit-hash

--- RNS/Interfaces/AutoInterface.py.orig	2023-02-03 16:36:43.000000000 +0000
+++ RNS/Interfaces/AutoInterface.py
@@ -23,6 +23,7 @@
 from .Interface import Interface
 import socketserver
 import threading
+import re
 import socket
 import struct
 import time
@@ -53,6 +54,13 @@ class AutoInterface(Interface):
             return AutoInterfaceHandler(callback, *args, **keys)
         return create_handler
 
+    def descope_linklocal(self, link_local_addr):
+        # Drop scope specifier expressd as %ifname (macOS)
+        link_local_addr = link_local_addr.split("%")[0]
+        # Drop embedded scope specifier (NetBSD, OpenBSD)
+        link_local_addr = re.sub(r"fe80:[0-9a-f]*::","fe80::", link_local_addr)
+        return link_local_addr
+
     def __init__(self, owner, name, group_id=None, discovery_scope=None, discovery_port=None, data_port=None, allowed_interfaces=None, ignored_interfaces=None, configured_bitrate=None):
         import importlib
         if importlib.util.find_spec('netifaces') != None:
@@ -158,9 +166,9 @@ class AutoInterface(Interface):
                         for address in addresses[self.netifaces.AF_INET6]:
                             if "addr" in address:
                                 if address["addr"].startswith("fe80:"):
-                                    link_local_addr = address["addr"]
-                                    self.link_local_addresses.append(link_local_addr.split("%")[0])
-                                    self.adopted_interfaces[ifname] = link_local_addr.split("%")[0]
+                                    link_local_addr = self.descope_linklocal(address["addr"])
+                                    self.link_local_addresses.append(link_local_addr)
+                                    self.adopted_interfaces[ifname] = link_local_addr
                                     self.multicast_echoes[ifname] = time.time()
                                     RNS.log(str(self)+" Selecting link-local address "+str(link_local_addr)+" for interface "+str(ifname), RNS.LOG_EXTREME)
 
@@ -278,7 +286,7 @@ class AutoInterface(Interface):
                         for address in addresses[self.netifaces.AF_INET6]:
                             if "addr" in address:
                                 if address["addr"].startswith("fe80:"):
-                                    link_local_addr = address["addr"].split("%")[0]
+                                    link_local_addr = self.descope_linklocal(address["addr"])
                                     if link_local_addr != self.adopted_interfaces[ifname]:
                                         old_link_local_address = self.adopted_interfaces[ifname]
                                         RNS.log("Replacing link-local address "+str(old_link_local_address)+" for "+str(ifname)+" with "+str(link_local_addr), RNS.LOG_DEBUG)
