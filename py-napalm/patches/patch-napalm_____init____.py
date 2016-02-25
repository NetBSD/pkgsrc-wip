$NetBSD$

Comment out modules where we've not packaged the prerequisites yet.

--- napalm/__init__.py.orig	2016-02-08 08:22:24.000000000 +0000
+++ napalm/__init__.py
@@ -15,8 +15,8 @@
 from eos import EOSDriver
 from iosxr import IOSXRDriver
 from junos import JunOSDriver
-from fortios import FortiOSDriver
-from nxos import NXOSDriver
+# from fortios import FortiOSDriver
+# from nxos import NXOSDriver
 from ibm import IBMDriver
 from ios import IOSDriver
 
@@ -28,8 +28,8 @@ def get_network_driver(vendor):
         'IOSXR': IOSXRDriver,
         'JUNOS': JunOSDriver,
         'JUNIPER': JunOSDriver,
-        'FORTIOS': FortiOSDriver,
-        'NXOS': NXOSDriver,
+#        'FORTIOS': FortiOSDriver,
+#        'NXOS': NXOSDriver,
         'IBM': IBMDriver,
         'IOS' : IOSDriver,
     }
