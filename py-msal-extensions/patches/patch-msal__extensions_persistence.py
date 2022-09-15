$NetBSD$

Handle everything but Windows and macOS like Linux.

--- msal_extensions/persistence.py.orig	2022-02-14 23:45:30.000000000 +0000
+++ msal_extensions/persistence.py
@@ -94,7 +94,7 @@ def build_encrypted_persistence(location
         return FilePersistenceWithDataProtection(location)
     if sys.platform.startswith('darwin'):
         return KeychainPersistence(location)
-    if sys.platform.startswith('linux'):
+    else:
         return LibsecretPersistence(location)
     raise RuntimeError("Unsupported platform: {}".format(sys.platform))  # pylint: disable=consider-using-f-string
 
