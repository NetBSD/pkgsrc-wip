$NetBSD$

Add compatibility for tag API introiduced in udev 247.
See https://sysdfree.wordpress.com/2023/07/08/372/.

--- udev-device.c.orig	2025-08-06 15:53:14.000000000 +0000
+++ udev-device.c
@@ -168,6 +168,13 @@ udev_device_get_tags_list_entry(struct u
 	return (udev_list_entry_get_first(udev_device_get_tags_list(ud)));
 }
 
+LIBUDEV_EXPORT struct udev_list_entry *
+udev_device_get_current_tags_list_entry(struct udev_device *udev_device)
+{
+	// TODO: udev-bsd database does not support current tags
+	return udev_device_get_tags_list_entry(udev_device);
+}
+
 LIBUDEV_EXPORT int
 udev_device_has_tag(struct udev_device *ud, const char *tag)
 {
@@ -185,6 +192,12 @@ udev_device_get_devlinks_list(struct ude
 	return (&ud->devlink_list);
 }
 
+LIBUDEV_EXPORT int
+udev_device_has_current_tag(struct udev_device *udev_device, const char *tag) {
+	// TODO: udev-bsd database does not support current tags
+	return udev_device_has_tag(udev_device, tag);
+}
+
 LIBUDEV_EXPORT struct udev_list_entry *
 udev_device_get_devlinks_list_entry(struct udev_device *ud)
 {
