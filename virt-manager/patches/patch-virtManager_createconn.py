$NetBSD$

Tolerabe qemu installed from pkgsrc

--- virtManager/createconn.py.orig	2019-07-02 20:13:28.000000000 +0000
+++ virtManager/createconn.py
@@ -69,7 +69,8 @@ class vmmCreateConn(vmmGObjectUI):
             os.path.exists("/usr/bin/qemu-kvm") or
             os.path.exists("/usr/bin/kvm") or
             os.path.exists("/usr/libexec/qemu-kvm") or
-            glob.glob("/usr/bin/qemu-system-*")):
+            glob.glob("/usr/bin/qemu-system-*") or
+            glob.glob("/usr/pkg/bin/qemu-system-*")):
             return "qemu:///system"
 
         if (os.path.exists("/usr/lib/libvirt/libvirt_lxc") or
