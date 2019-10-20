$NetBSD$

Tolerate VARBASE not being /var

--- virtManager/engine.py.orig	2019-07-02 20:13:28.000000000 +0000
+++ virtManager/engine.py
@@ -151,8 +151,8 @@ class vmmEngine(vmmGObject):
         except Exception:
             units = []
             log.exception("Couldn't connect to systemd")
-            libvirtd_installed = os.path.exists("/var/run/libvirt")
-            libvirtd_active = os.path.exists("/var/run/libvirt/libvirt-sock")
+            libvirtd_installed = os.path.exists("@VARBASE@/run/libvirt")
+            libvirtd_active = os.path.exists("@VARBASE@/run/libvirt/libvirt-sock")
 
         # Check if libvirtd is installed and running
         for unitinfo in units:
