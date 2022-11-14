--- src/serial_posix.c.orig	2022-11-13 22:34:30.225666053 -0800
+++ src/serial_posix.c	2022-11-13 22:35:04.795132804 -0800
@@ -30,6 +30,7 @@
 #include <fcntl.h>	// fcntl
 #include <termios.h>	// tcgetattr, tcsetattr, cfsetispeed, cfsetospeed, tcflush, tcsendbreak
 #include <sys/ioctl.h>	// ioctl
+#include <sys/select.h>	// select
 #ifdef HAVE_LINUX_SERIAL_H
 #include <linux/serial.h>
 #endif
