$NetBSD$

Fix Coldcard plugin to support ckcc-protocol versions > 1.0

--- electrum/plugins/coldcard/coldcard.py.orig	2000-11-11 11:11:11.000000000 +0000
+++ electrum/plugins/coldcard/coldcard.py
@@ -34,7 +34,7 @@ try:
     from ckcc.constants import (MAX_MSG_LEN, MAX_BLK_LEN, MSG_SIGNING_MAX_LENGTH, MAX_TXN_LEN,
         AF_CLASSIC, AF_P2SH, AF_P2WPKH, AF_P2WSH, AF_P2WPKH_P2SH, AF_P2WSH_P2SH)
 
-    from ckcc.client import ColdcardDevice, COINKITE_VID, CKCC_PID, CKCC_SIMULATOR_PATH
+    from ckcc.client import ColdcardDevice, COINKITE_VID, CKCC_PID, DEFAULT_SIM_SOCKET
 
     requirements_ok = True
 
@@ -511,7 +511,7 @@ class ColdcardPlugin(HW_PluginBase):
     def detect_simulator(self):
         # if there is a simulator running on this machine,
         # return details about it so it's offered as a pairing choice
-        fn = CKCC_SIMULATOR_PATH
+        fn = DEFAULT_SIM_SOCKET
 
         if os.path.exists(fn):
             return [Device(path=fn,
