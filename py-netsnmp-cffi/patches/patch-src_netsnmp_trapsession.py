$NetBSD$

Add patch to handle sockaddr layout on BSD*s.

--- src/netsnmpy/trapsession.py.orig	2025-04-25 09:15:29.422003201 +0000
+++ src/netsnmpy/trapsession.py
@@ -1,6 +1,7 @@
 """SNMP Trap session handling"""
 
 import logging
+import platform
 from ipaddress import ip_address
 from socket import AF_INET, AF_INET6, inet_ntop
 from typing import Optional, Protocol
@@ -36,10 +37,18 @@ _lib = _netsnmp.lib
 _log = logging.getLogger(__name__)
 
 # Local constants
+SOCKADDR_OFFSET = 1 if "BSD" in platform.system() else 0
 IPADDR_SIZE = 4
 IP6ADDR_SIZE = 16
-IPADDR_OFFSET = 4
-IP6ADDR_OFFSET = 8
+IPADDR_OFFSET = 0
+IP6ADDR_OFFSET = _ffi.sizeof("uint32_t") # sin6_flowinfo
+if "BSD" in platform.platform():
+    SOCKADDR_TYPE = "bsd_sockaddr_in"
+    SA_FAILY_TYPE = "uint8_t"
+else:
+    SOCKADDR_TYPE = "linux_sockaddr_in"
+    SA_FAMILY_TYPE = "unsigned short"
+SOCKADDR_DATA_OFFSET = _ffi.offsetof(SOCKADDR_TYPE, "sa_data")
 
 OBJID_SNMP_TRAPS = OID(".1.3.6.1.6.3.1.1.5")
 OBJID_SNMP_TRAP_OID = OID(".1.3.6.1.6.3.1.1.4.1.0")
@@ -248,18 +257,19 @@ class SNMPTrap:
         if pdu.transport_data_length <= 1:
             return
 
-        # peek the first two bytes of the pdu's opaque transport data to determine
-        # socket address family (we are assuming the transport_data is a sockaddr_in
-        # or sockaddr_in6 structure and accessing it naughtily here)
-        family_p = _ffi.cast("unsigned short*", pdu.transport_data)
-        family = family_p[0]
+        # peek the first part of the pdu's opaque transport data to determine socket
+        # address family (we are assuming the transport_data is a sockaddr_in or
+        # sockaddr_in6 structure and accessing it naughtily here. sockaddr
+        # definitions vary between platforms, further complicating this).
+        sockaddr = _ffi.cast(f"{SOCKADDR_TYPE}*", pdu.transport_data)
+        family = sockaddr[0].sa_family
         if family not in (AF_INET, AF_INET6):
             return
 
         addr_size, offset = (
-            (IPADDR_SIZE, IPADDR_OFFSET)
+            (IPADDR_SIZE, SOCKADDR_DATA_OFFSET + IPADDR_OFFSET)
             if family == AF_INET
-            else (IP6ADDR_SIZE, IP6ADDR_OFFSET)
+            else (IP6ADDR_SIZE, SOCKADDR_DATA_OFFSET + IP6ADDR_OFFSET)
         )
 
         buffer = _ffi.cast("char*", pdu.transport_data)
