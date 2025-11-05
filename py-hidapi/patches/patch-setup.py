$NetBSD$

Fix setup.py to use the backend according to the comms/libhidapi 
settings.

--- setup.py.orig	2025-11-04 23:48:53.111348221 +0000
+++ setup.py
@@ -179,46 +179,29 @@ def hid_from_embedded_hidapi():
 
 def hid_from_system_hidapi():
     if sys.platform.startswith("linux"):
-        modules = []
-        if "--with-hidraw" in sys.argv:
-            sys.argv.remove("--with-hidraw")
-            HIDAPI_WITH_HIDRAW = True
-        else:
-            HIDAPI_WITH_HIDRAW = to_bool(os.getenv("HIDAPI_WITH_HIDRAW"))
-        if "--with-libusb" in sys.argv:
-            sys.argv.remove("--with-libusb")
-            HIDAPI_WITH_LIBUSB = True
-        else:
-            HIDAPI_WITH_LIBUSB = to_bool(os.getenv("HIDAPI_WITH_LIBUSB"))
-
-        # make libusb backend default if none is specified
-        if not HIDAPI_WITH_HIDRAW and not HIDAPI_WITH_LIBUSB:
-            HIDAPI_WITH_LIBUSB = True
-
-        if HIDAPI_WITH_LIBUSB:
-            hidraw_module = "hidraw"
-            modules.append(
-                pkgconfig_configure_extension(
-                    Extension("hid", sources=["hid.pyx"]), hidapi_libusb_pkgconfig
-                )
+        modules.append(
+            pkgconfig_configure_extension(
+                Extension("hid", sources=["hid.pyx"]), hidapi_libusb_pkgconfig
             )
-        elif HIDAPI_WITH_HIDRAW:
-            hidraw_module = "hid"
-        else:
-            raise ValueError("Unknown HIDAPI backend")
-
+        )
         modules.append(
             pkgconfig_configure_extension(
-                Extension(hidraw_module, sources=["hidraw.pyx"]),
+                Extension("hidraw", sources=["hidraw.pyx"]),
                 hidapi_hidraw_pkgconfig,
             )
         )
-    else:
+    elif sys.platform.startswith("darwin"):
         modules = [
             pkgconfig_configure_extension(
                 Extension("hid", sources=["hid.pyx"]), hidapi_pkgconfig
             )
         ]
+    else:
+        modules = [
+            pkgconfig_configure_extension(
+                Extension("hid", sources=["hid.pyx"]), hidapi_libusb_pkgconfig
+            )
+        ]
 
     return modules
 
