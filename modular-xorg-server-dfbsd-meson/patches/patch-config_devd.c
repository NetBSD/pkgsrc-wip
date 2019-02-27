$NetBSD$

devd support to detect devices from FreeBSD ports / DragonFly dports
x11-servers/xorg-server 1.18.4.

Added many debugging statements with DebugF.

Adjust for update to 1.19.6 API.

--- config/devd.c.orig	2018-08-04 04:32:13.580868000 +0000
+++ config/devd.c
@@ -0,0 +1,613 @@
+/*
+ * Copyright (c) 2012 Baptiste Daroussin
+ * Copyright (c) 2013, 2014 Alex Kozlov
+ * Copyright (c) 2014 Robert Millan
+ * Copyright (c) 2014 Jean-Sebastien Pedron
+ *
+ * Permission is hereby granted, free of charge, to any person obtaining a
+ * copy of this software and associated documentation files (the "Software"),
+ * to deal in the Software without restriction, including without limitation
+ * the rights to use, copy, modify, merge, publish, distribute, sublicense,
+ * and/or sell copies of the Software, and to permit persons to whom the
+ * Software is furnished to do so, subject to the following conditions:
+ *
+ * The above copyright notice and this permission notice (including the next
+ * paragraph) shall be included in all copies or substantial portions of the
+ * Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
+ * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
+ * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
+ * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
+ * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
+ * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
+ * DEALINGS IN THE SOFTWARE.
+ *
+ * Author: Baptiste Daroussin <bapt@FreeBSD.org>
+ */
+
+#ifdef HAVE_DIX_CONFIG_H
+#include <dix-config.h>
+#endif
+
+#ifdef CONFIG_DEVD
+
+#include <sys/types.h>
+#include <sys/kbio.h>
+#include <sys/socket.h>
+#include <sys/stat.h>
+#include <sys/sysctl.h>
+#include <sys/un.h>
+
+#include <ctype.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <stdlib.h>
+#include <stdio.h>
+#include <stdbool.h>
+#include <unistd.h>
+
+#include "input.h"
+#include "inputstr.h"
+#include "hotplug.h"
+#include "config-backends.h"
+#include "os.h"
+
+#define DEVD_SOCK_PATH "/var/run/devd.pipe"
+
+#define DEVD_EVENT_ADD		'+'
+#define DEVD_EVENT_REMOVE	'-'
+#define DEVD_EVENT_NOTIFY	'!'
+
+#define RECONNECT_DELAY		(5 * 1000)
+
+static int sock_devd;
+static bool is_console_kbd = false;
+static bool is_kbdmux = false;
+static OsTimerPtr rtimer = NULL;
+
+struct hw_type {
+	const char *driver;
+	int flag;
+	const char *xdriver;
+};
+
+static struct hw_type hw_types[] = {
+	{ "ukbd", ATTR_KEYBOARD, "kbd" },
+	{ "atkbd", ATTR_KEYBOARD, "kbd" },
+	{ "kbdmux", ATTR_KEYBOARD, "kbd" },
+	{ "sysmouse", ATTR_POINTER, "mouse" },
+	{ "ums", ATTR_POINTER, "mouse" },
+	{ "psm", ATTR_POINTER, "mouse" },
+	{ "vboxguest", ATTR_POINTER, "vboxmouse" },
+	{ "joy", ATTR_JOYSTICK, NULL },
+	{ "atp", ATTR_TOUCHPAD, NULL },
+	{ "uep", ATTR_TOUCHSCREEN, NULL },
+	{ NULL, -1, NULL },
+};
+
+static bool
+sysctl_exists(const struct hw_type *device, int unit,
+	char *devname, size_t devname_len)
+{
+	char sysctlname[PATH_MAX];
+	size_t len;
+	int ret;
+
+	if (device == NULL || device->driver == NULL)
+		return false;
+
+	/* Check if a sysctl exists. */
+	snprintf(sysctlname, sizeof(sysctlname), "dev.%s.%i.%%desc",
+	    device->driver, unit);
+	ret = sysctlbyname(sysctlname, NULL, &len, NULL, 0);
+
+	if (ret == 0 && len > 0) {
+		snprintf(devname, devname_len, "%s%i", device->driver, unit);
+		DebugF("[config/devd]: sysctl_exists: true for sysctlname (%s), devname (%s)\n", sysctlname, devname);
+		return true;
+	}
+
+	return false;
+}
+
+static bool
+devpath_exists(const struct hw_type *device,
+	char *devname, size_t devname_len)
+{
+	char *devpath;
+	struct stat st;
+	int ret;
+
+	if (device == NULL || device->driver == NULL)
+		return false;
+
+	/* Check if /dev/$driver exists. */
+	asprintf(&devpath, "/dev/%s", device->driver);
+	if (devpath == NULL)
+		return false;
+
+	ret = stat(devpath, &st);
+	free(devpath);
+
+	if (ret == 0) {
+		DebugF("[config/devd]: devpath_exists true for devpath (%s)\n", devpath);
+		strncpy(devname, device->driver, devname_len);
+		return true;
+	}
+
+	return false;
+}
+
+static char *
+sysctl_get_str(const char *sysctlname)
+{
+	char *dest = NULL;
+	size_t len;
+
+	if (sysctlname == NULL)
+		return NULL;
+
+	if (sysctlbyname(sysctlname, NULL, &len, NULL, 0) == 0) {
+		dest = malloc(len + 1);
+		if (dest) {
+			if (sysctlbyname(sysctlname, dest, &len, NULL, 0) == 0)
+				dest[len] = '\0';
+			else {
+				free(dest);
+				dest = NULL;
+			}
+		}
+	}
+
+	return dest;
+}
+
+static void
+device_added(const char *devname)
+{
+	char path[PATH_MAX];
+	char sysctlname[PATH_MAX];
+	char *vendor;
+	char *product = NULL;
+	char *config_info = NULL;
+	char *walk;
+	InputOption *options = NULL;
+	InputAttributes attrs = { };
+	DeviceIntPtr dev = NULL;
+	int i;
+	int fd;
+
+	DebugF("[config/devd]: begin device_added: devname (%s)\n", devname);
+
+	for (i = 0; hw_types[i].driver != NULL; i++) {
+		size_t len;
+
+		len = strlen(hw_types[i].driver);
+		if (strcmp(devname, hw_types[i].driver) == 0 ||
+			(strncmp(devname, hw_types[i].driver, len) == 0 &&
+				isnumber(*(devname + len)))) {
+			attrs.flags |= hw_types[i].flag;
+			break;
+		}
+	}
+
+	if (hw_types[i].driver == NULL || hw_types[i].xdriver == NULL) {
+		LogMessage(X_INFO, "config/devd: ignoring device %s\n",
+				devname);
+		DebugF("[config/devd]: ignoring device %s\n",
+				devname);
+		return;
+	}
+
+	/* Skip keyboard devices if kbdmux is enabled */
+	if (is_kbdmux && is_console_kbd && hw_types[i].flag & ATTR_KEYBOARD) {
+		LogMessage(X_INFO, "config/devd: kbdmux is enabled, ignoring device %s\n",
+				devname);
+		DebugF("[config/devd]: kbdmux is enabled, ignoring device %s\n",
+				devname);
+		return;
+	}
+
+	snprintf(path, sizeof(path), "/dev/%s", devname);
+	DebugF("[config/devd]: device_added: devname full path (%s)\n", path);
+
+	options = input_option_new(NULL, "_source", "server/devd");
+	if (!options)
+		return;
+
+	snprintf(sysctlname, sizeof(sysctlname), "dev.%s.%s.%%desc",
+	    hw_types[i].driver, devname + strlen(hw_types[i].driver));
+	DebugF("[config/devd]: device_added: try sysctl name (%s)\n", sysctlname);
+	vendor = sysctl_get_str(sysctlname);
+	if (vendor == NULL) {
+		DebugF("[config/devd]: device_added: input_option_new([name], devname (%s))\n", devname);
+		options = input_option_new(options, "name", devname);
+	}
+	else {
+		DebugF("[config/devd]: device_added: read full vendor (%s)\n", vendor);
+		if ((walk = strchr(vendor, ' ')) != NULL) {
+			walk[0] = '\0';
+			walk++;
+			product = walk;
+			if ((walk = strchr(product, ',')) != NULL)
+				walk[0] = '\0';
+		}
+
+		attrs.vendor = strdup(vendor);
+		if (product) {
+			DebugF("[config/devd]: device_added: input_option_new([name], product (%s))\n", product);
+			attrs.product = strdup(product);
+			options = input_option_new(options, "name", product);
+		}
+		else {
+			DebugF("[config/devd]: device_added: input_option_new([name], [(unnamed)])\n");
+			options = input_option_new(options, "name", "(unnamed)");
+		}
+
+		free(vendor);
+	}
+
+	/* XXX implement usb_id */
+	attrs.usb_id = NULL;
+	attrs.device = strdup(path);
+	options = input_option_new(options, "driver", hw_types[i].xdriver);
+	DebugF("[config/devd]: device_added: input_option_new ([driver], (%s))\n", hw_types[i].xdriver);
+
+	fd = open(path, O_RDONLY);
+	if (fd >= 0) {
+		DebugF("[config/devd]: device_added: input_option_new ([device], (%s)), fd (%d)\n", path, fd);
+		close(fd);
+		options = input_option_new(options, "device", path);
+	}
+	else {
+		if (attrs.flags & ~ATTR_KEYBOARD) {
+			LogMessage(X_INFO, "config/devd: device %s already opened\n",
+					 path);
+			DebugF("[config/devd]: device_added: device (%s) already opened: flags (0x%x), fd (%d)\n",
+					 path, attrs.flags, fd);
+
+			/*
+			 * Fail if cannot open device, it breaks AllowMouseOpenFail,
+			 * but it should not matter when config/devd enabled
+			 */
+			goto unwind;
+		}
+
+		if (is_console_kbd) {
+			/*
+			 * There can be only one keyboard attached to console and
+			 * it is already added.
+			 */
+			LogMessage(X_WARNING, "config/devd: console keyboard is "
+					"already added, ignoring %s (%s)\n",
+					attrs.product, path);
+			DebugF("[config/devd]: device_added: console keyboard is "
+					"already added, ignoring %s, path (%s): fd (%d)\n",
+					attrs.product, path, fd);
+			goto unwind;
+		}
+		else {
+			/*
+			 * Don't pass "device" option if the keyboard is already
+			 * attached to the console (ie. open() fails).
+			 * This would activate a special logic in xf86-input-keyboard.
+			 * Prevent any other attached to console keyboards being
+			 * processed. There can be only one such device.
+			 */
+			DebugF("[config/devd]: device_added: keyboard already attached to console "
+					"is_console_kbd = true, ignoring %s, path (%s): fd (%d)\n",
+					attrs.product, path, fd);
+			is_console_kbd = true;
+		}
+	}
+
+	if (asprintf(&config_info, "devd:%s", devname) == -1) {
+		config_info = NULL;
+		goto unwind;
+	}
+
+	if (device_is_duplicate(config_info)) {
+		LogMessage(X_WARNING, "config/devd: device %s (%s) already added. "
+				"ignoring\n", attrs.product, path);
+		DebugF("[config/devd]: device %s (%s) already added. "
+				"ignoring\n", attrs.product, path);
+		goto unwind;
+	}
+
+	DebugF("[config/devd]: device_added: input_option_new ([config_info], (%s))\n", config_info);
+	options = input_option_new(options, "config_info", config_info);
+	LogMessage(X_INFO, "config/devd: adding input device %s (%s)\n",
+			attrs.product, path);
+	DebugF("[config/devd]: device_added: before   NewInputDeviceRequest for device %s (%s)\n",
+			attrs.product, path);
+
+	NewInputDeviceRequest(options, &attrs, &dev);
+
+	DebugF("[config/devd]: device_added: finished NewInputDeviceRequest for device %s (%s)\n",
+			attrs.product, path);
+
+unwind:
+	free(config_info);
+	input_option_free_list(&options);
+	free(attrs.usb_id);
+	free(attrs.product);
+	free(attrs.device);
+	free(attrs.vendor);
+}
+
+static void
+device_removed(char *devname)
+{
+	char *config_info;
+
+	DebugF("[config/devd]: removing device (%s)\n", devname);
+
+	if (asprintf(&config_info, "devd:%s", devname) == -1)
+		return;
+
+	remove_devices("devd", config_info);
+
+	free(config_info);
+}
+
+static bool is_kbdmux_enabled(void)
+{
+	/* Xorg uses /dev/ttyv0 as a console device */
+	/* const char device[]="/dev/console"; */
+	const char device[]="/dev/ttyv0";
+	keyboard_info_t info;
+	int fd;
+
+	fd = open(device, O_RDONLY);
+	DebugF("[config/devd]: is_kbdmux_enabled: device (%s) opened, fd (%d)\n", device, fd);
+
+	if (fd < 0)
+		return false;
+
+	if (ioctl(fd, KDGKBINFO, &info) == -1) {
+		DebugF("[config/devd]: is_kbdmux_enabled: ioctl KDGKBINFO failed (%s)\n", strerror(errno));
+		close(fd);
+		return false;
+	}
+
+	close(fd);
+
+	DebugF("[config/devd]: is_kbdmux_enabled: info.kb_name (%s)\n", info.kb_name);
+	if (!strncmp(info.kb_name, "kbdmux", 6))
+		return true;
+
+	return false;
+}
+
+static void
+disconnect_devd(int sock)
+{
+	LogMessage(X_INFO, "config/devd: disconnect socket (%d)\n", sock);
+	DebugF("[config/devd]: disconnect socket (%d)\n", sock);
+
+	if (sock >= 0) {
+		RemoveNotifyFd(sock);
+		close(sock);
+	}
+}
+
+static void
+wakeup_handler(int sock, int ready, void *data);
+
+static int
+connect_devd(void)
+{
+	struct sockaddr_un devd;
+	int sock;
+
+	DebugF("[config/devd]: connecting ... \n");
+
+	sock = socket(AF_UNIX, SOCK_STREAM, 0);
+	if (sock < 0) {
+		LogMessage(X_ERROR, "[config/devd]: failed opening stream socket: %s\n", strerror(errno));
+		DebugF("[config/devd]: connect_devd: failed opening stream socket: %s\n", strerror(errno));
+		return -1;
+	}
+
+	DebugF("[config/devd]: opened stream socket (%d)\n", sock);
+
+	devd.sun_family = AF_UNIX;
+	strlcpy(devd.sun_path, DEVD_SOCK_PATH, sizeof(devd.sun_path));
+
+	if (connect(sock, (struct sockaddr *) &devd, sizeof(devd)) < 0) {
+		close(sock);
+		LogMessage(X_ERROR, "[config/devd]: failed to connect to devd: %s\n", strerror(errno));
+		DebugF("[config/devd]: connect_devd: failed to connect to devd: %s\n", strerror(errno));
+		return -1;
+	}
+
+	DebugF("[config/devd]: connected to devd, sock (%d), pid file (%s)\n", sock, DEVD_SOCK_PATH);
+
+	SetNotifyFd(sock, wakeup_handler, X_NOTIFY_READ, NULL);
+
+	return	sock;
+}
+
+static CARD32
+reconnect_handler(OsTimerPtr timer, CARD32 time, void *arg)
+{
+	int newsock;
+
+	if ((newsock = connect_devd()) >= 0) {
+		sock_devd = newsock;
+		TimerFree(rtimer);
+		rtimer = NULL;
+		LogMessage(X_INFO, "config/devd: reopening devd socket\n");
+		DebugF("[config/devd]: reconnect_handler: RECONNECTED using socket (%d)\n", sock_devd);
+		return 0;
+	}
+	DebugF("[config/devd]: reconnect_handler FAILED to reconnect returned (%d)\n", newsock);
+
+	/* Try again after RECONNECT_DELAY */
+	return RECONNECT_DELAY;
+}
+
+static ssize_t
+socket_getline(int fd, char **out)
+{
+	char *buf, *newbuf;
+	ssize_t ret, cap, sz = 0;
+	char c;
+
+	cap = 1024;
+	buf = malloc(cap * sizeof(char));
+	if (!buf)
+		return -1;
+
+	for (;;) {
+		ret = read(sock_devd, &c, 1);
+		if (ret < 0) {
+			if (errno == EINTR)
+				continue;
+			free(buf);
+			return -1;
+		/* EOF - devd socket is lost */
+		} else if (ret == 0) {
+			disconnect_devd(sock_devd);
+			rtimer = TimerSet(NULL, 0, 1, reconnect_handler, NULL);
+			LogMessage(X_WARNING, "config/devd: devd socket is lost\n");
+			DebugF("[config/devd]: WARNING socket_getline: EOF devd socket (%d) is LOST\n", sock_devd);
+			free(buf);
+			return -1;
+		}
+		if (c == '\n')
+			break;
+
+		if (sz + 1 >= cap) {
+			cap *= 2;
+			newbuf = realloc(buf, cap * sizeof(char));
+			if (!newbuf) {
+				DebugF("[config/devd]: ERROR socket_getline: realloc failed on buf\n");
+				free(buf);
+				return -1;
+			}
+			buf = newbuf;
+		}
+		buf[sz] = c;
+		sz++;
+	}
+
+	buf[sz] = '\0';
+	if (sz >= 0)
+		*out = buf;
+	else
+		free(buf);
+
+	/* Number of bytes in the line, not counting the line break */
+	return sz;
+}
+
+static void
+wakeup_handler(int sock, int ready, void *data)
+{
+	char *line = NULL;
+	char *walk;
+	ssize_t sz;
+
+	DebugF("[config/devd]: wakeup_handler: sock_devd (%d), sock (%d), ready (%d)\n", sock_devd, sock, ready);
+	
+		sz = socket_getline(sock_devd, &line);
+		if (sz < 0)
+			return;
+		if (sz == 0) {
+			DebugF("[config/devd]: WARNING wakeup_handler: socket_getline returned zero length line\n");
+			free(line);
+			return;
+		}
+		DebugF("[config/devd]: wakeup_handler: socket_getline (%s)\n", line);
+
+		walk = strchr(line + 1, ' ');
+		if (walk != NULL)
+			walk[0] = '\0';
+
+		switch (*line) {
+		case DEVD_EVENT_ADD:
+			DebugF("[config/devd]: wakeup_handler: DEVD_EVENT_ADD line (%s)\n", line);
+			device_added(line + 1);
+			break;
+		case DEVD_EVENT_REMOVE:
+			DebugF("[config/devd]: wakeup_handler: DEVD_EVENT_REMOVE line (%s)\n", line);
+			device_removed(line + 1);
+			break;
+		case DEVD_EVENT_NOTIFY:
+			DebugF("[config/devd]: wakeup_handler: DEVD_EVENT_NOTIFY line (%s)\n", line);
+			break;
+		default:
+			break;
+		}
+		free(line);
+}
+
+#if 0
+static void
+block_handler(void *data, struct timeval **tv)
+{
+}
+#endif
+
+int
+config_devd_init(void)
+{
+	char devicename[1024];
+	int i, j;
+
+	LogMessage(X_INFO, "config/devd: probing input devices...\n");
+	DebugF("[config/devd]: config_devd_init: probing input devices...\n");
+
+	/*
+	 * Add fake keyboard and give up on keyboards management
+	 * if kbdmux is enabled
+	 */
+	if ((is_kbdmux = is_kbdmux_enabled()) == true)
+		device_added("kbdmux");
+
+	for (i = 0; hw_types[i].driver != NULL; i++) {
+		/* First scan the sysctl to determine the hardware */
+		for (j = 0; j < 16; j++) {
+			if (sysctl_exists(&hw_types[i], j,
+					devicename, sizeof(devicename)) != 0)
+				device_added(devicename);
+		}
+
+		if (devpath_exists(&hw_types[i], devicename, sizeof(devicename)) != 0)
+			device_added(devicename);
+	}
+
+	if ((sock_devd = connect_devd()) < 0)
+		return 0;
+
+#if 0
+	RegisterBlockAndWakeupHandlers(block_handler, wakeup_handler, NULL);
+#endif
+	DebugF("[config/devd]: config_devd_init: devices probed, sock_devd (%d)\n", sock_devd);
+
+	return 1;
+}
+
+void
+config_devd_fini(void)
+{
+	LogMessage(X_INFO, "config/devd: terminating backend...\n");
+	DebugF("[config/devd]: terminating backend...\n");
+
+	if (rtimer) {
+		TimerFree(rtimer);
+		rtimer = NULL;
+	}
+
+	disconnect_devd(sock_devd);
+
+#if 0
+	RemoveBlockAndWakeupHandlers(block_handler, wakeup_handler, NULL);
+#endif
+
+	is_console_kbd = false;
+}
+
+#endif /* CONFIG_DEVD */
