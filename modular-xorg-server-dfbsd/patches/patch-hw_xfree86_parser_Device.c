$NetBSD$

From NetBSD xsrc:

Oct 22 15:00:40 2011 UTC

if the video driver is "vmware" or "vmwlegacy" and no mouse section exists,
use the "vmmouse" input driver instead of "mouse" -- now xorg works properly
in vmware without a config file

--- hw/xfree86/parser/Device.c.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/parser/Device.c
@@ -348,3 +348,16 @@ xf86findDevice(const char *ident, XF86Co
     }
     return NULL;
 }
+
+XF86ConfDevicePtr
+xf86findDeviceByDriver (const char *driver, XF86ConfDevicePtr p)
+{
+	while (p)
+	{
+		if (xf86nameCompare (driver, p->dev_driver) == 0)
+			return p;
+
+		p = p->list.next;
+	}
+	return NULL;
+}
