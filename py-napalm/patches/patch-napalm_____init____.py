$NetBSD$

Comment out modules where we've not packaged the prerequisites yet.

--- napalm/__init__.py.orig	2016-02-08 08:22:24.000000000 +0000
+++ napalm/__init__.py
@@ -15,9 +15,9 @@
 from eos import EOSDriver
 from iosxr import IOSXRDriver
 from junos import JunOSDriver
-from fortios import FortiOSDriver
-from nxos import NXOSDriver
-from ibm import IBMDriver
+# from fortios import FortiOSDriver
+# from nxos import NXOSDriver
+# from ibm import IBMDriver
 from ios import IOSDriver
 
 def get_network_driver(vendor):
@@ -28,9 +28,9 @@ def get_network_driver(vendor):
         'IOSXR': IOSXRDriver,
         'JUNOS': JunOSDriver,
         'JUNIPER': JunOSDriver,
-        'FORTIOS': FortiOSDriver,
-        'NXOS': NXOSDriver,
-        'IBM': IBMDriver,
+#        'FORTIOS': FortiOSDriver,
+#        'NXOS': NXOSDriver,
+#         'IBM': IBMDriver,
         'IOS' : IOSDriver,
     }
     try:
