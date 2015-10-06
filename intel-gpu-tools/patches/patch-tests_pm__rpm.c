$NetBSD$

--- tests/pm_rpm.c.orig	2015-09-11 14:42:51.000000000 +0000
+++ tests/pm_rpm.c
@@ -38,8 +38,12 @@
 #include <sys/mman.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef __NetBSD__
+#include <dev/i2c/i2c_io.h>
+#else
 #include <linux/i2c.h>
 #include <linux/i2c-dev.h>
+#endif
 
 #include <drm.h>
 
@@ -560,6 +564,7 @@ static bool i2c_edid_is_valid(int fd)
 {
 	int rc;
 	unsigned char edid[128] = {};
+#ifdef __linux__
 	struct i2c_msg msgs[] = {
 		{ /* Start at 0. */
 			.addr = 0x50,
@@ -580,6 +585,9 @@ static bool i2c_edid_is_valid(int fd)
 
 	rc = ioctl(fd, I2C_RDWR, &msgset);
 	return (rc >= 0) ? edid_is_valid(edid) : false;
+#else
+	return false;
+#endif
 }
 
 static int count_i2c_valid_edids(void)
