$NetBSD$

* Handle attached-detached devices with udev monitor
* Handle auto-repeat per device instead of globally

--- src/wscons.c.orig	2026-01-30 14:33:32.122725330 +0000
+++ src/wscons.c
@@ -45,53 +45,121 @@ static void
 wscons_device_init_pointer_acceleration(struct wscons_device *device,
               struct motion_filter *filter);
 
-static int old_value = -1;
-
-static int
-udev_input_enable(struct libinput *libinput)
+static void
+wscons_udev_handler(void *data)
 {
+	struct udev_input *input = data;
+	struct udev_device *udev_device;
 	struct libinput_seat *seat;
 	struct libinput_device *device;
+	uint64_t time;
+	struct timespec ts;
+	struct libinput_event *event;
+	const char *action, *devnode, *sysname;
 
-	seat = wscons_seat_get(libinput, default_seat, default_seat_name);
-	list_for_each(device, &seat->devices_list, link) {
-		device->fd = open_restricted(libinput, device->devname, O_RDWR);
-		device->source =
-		    libinput_add_fd(libinput, device->fd,
-			wscons_device_dispatch, device);
-		if (!device->source) {
-			return -ENOMEM;
+	udev_device = udev_monitor_receive_device(input->udev_monitor);
+	if (!udev_device)
+		return;
+
+	action = udev_device_get_action(udev_device);
+	devnode = udev_device_get_devnode(udev_device);
+	sysname = udev_device_get_sysname(udev_device);
+	if (!action || !devnode || !sysname)
+		goto out;
+
+	if (!(strneq(sysname, "wskbd", 5) || strneq(sysname, "wsmouse", 7)))
+		goto out;
+
+	if (streq(action, "add")) {
+		device = libinput_path_add_device(&input->base, devnode);
+		if (!device)
+			goto out;
+		clock_gettime(CLOCK_REALTIME, &ts);
+		time = s2us(ts.tv_sec) + ns2us(ts.tv_nsec);
+		event = calloc(1, sizeof(*event));
+		post_device_event(device, time, LIBINPUT_EVENT_DEVICE_ADDED, event);
+	}
+	else if (streq(action, "remove")) {
+		seat = wscons_seat_get(&input->base, default_seat, default_seat_name);
+		list_for_each(device, &seat->devices_list, link) {
+			if (device->devname && strcmp(device->devname, devnode) == 0) {
+				clock_gettime(CLOCK_REALTIME, &ts);
+				time = s2us(ts.tv_sec) + ns2us(ts.tv_nsec);
+				event = calloc(1, sizeof(*event));
+				post_device_event(device, time, LIBINPUT_EVENT_DEVICE_REMOVED, event);
+				libinput_path_remove_device(device);
+				break;
+			}
 		}
 	}
+
+out:
+	udev_device_unref(udev_device);
+}
+
+static int
+udev_input_enable(struct libinput *libinput)
+{
+	struct udev_input *input = (struct udev_input *)libinput;
+	struct udev *udev = input->udev;
+	int fd;
+
+	input->udev_monitor = udev_monitor_new_from_netlink(udev, "udev");
+	if (!input->udev_monitor) {
+		log_info(libinput, "udev: failed to create the udev monitor\n");
+		return -1;
+	}
+
+	if (udev_monitor_filter_add_match_subsystem_devtype(input->udev_monitor, "input", NULL)) {
+		log_info(libinput, "udev: failed to set up filter\n");
+		goto err;
+	}
+
+	if (udev_monitor_enable_receiving(input->udev_monitor)) {
+		log_info(libinput, "udev: failed to bind the udev monitor\n");
+		goto err;
+	}
+
+	fd = udev_monitor_get_fd(input->udev_monitor);
+	input->udev_monitor_source =
+			libinput_add_fd(&input->base, fd, wscons_udev_handler, input);
+	if (!input->udev_monitor_source) {
+		goto err;
+	}
+
 	return 0;
+
+err:
+	if (input->udev_monitor) {
+		udev_monitor_unref(input->udev_monitor);
+		input->udev_monitor = NULL;
+	}
+	return -1;
 }
 
 static void
 udev_input_disable(struct libinput *libinput)
 {
-	struct libinput_seat *seat;
-	struct libinput_device *device;
+	struct udev_input *input = (struct udev_input*)libinput;
 
-	seat = wscons_seat_get(libinput, default_seat, default_seat_name);
-	list_for_each(device, &seat->devices_list, link) {
-		if (device->source) {
-			libinput_remove_source(libinput, device->source);
-			device->source = NULL;
-		}
-		close_restricted(libinput, device->fd);
+	if (input->udev_monitor_source) {
+		libinput_remove_source(&input->base, input->udev_monitor_source);
+		input->udev_monitor_source = NULL;
+	}
+	if (input->udev_monitor) {
+		udev_monitor_unref(input->udev_monitor);
+		input->udev_monitor = NULL;
 	}
 }
 
 static void
 udev_input_destroy(struct libinput *libinput)
 {
-	struct libinput_seat *seat;
-	struct libinput_device *device;
+	struct udev_input *input = (struct udev_input*)libinput;
 
-	fprintf(stderr, "%s", __func__);
-	seat = wscons_seat_get(libinput, default_seat, default_seat_name);
-	list_for_each(device, &seat->devices_list, link) {
-		close_restricted(libinput, device->fd);
+	if (input->udev) {
+		udev_unref(input->udev);
+		input->udev = NULL;
 	}
 }
 
@@ -128,13 +196,13 @@ wscons_process(struct libinput_device *d
 		key = wsevent->value;
 		if (wsevent->type == WSCONS_EVENT_KEY_UP) {
 			kstate = LIBINPUT_KEY_STATE_RELEASED;
-			old_value = -1;
+			dev->old_value = -1;
 		} else {
 			kstate = LIBINPUT_KEY_STATE_PRESSED;
 			/* ignore auto-repeat */
-			if (key == old_value)
+			if (key == dev->old_value)
 				return;
-			old_value = key;
+			dev->old_value = key;
 		}
 		keyboard_notify_key(device, time,
 		    wskey_transcode(wscons_device(device)->scanCodeMap, key), kstate);
@@ -239,7 +307,7 @@ wscons_device_dispatch(void *data)
 	ssize_t len;
 	int count, i;
 
-	len = read(device->fd, wsevents, sizeof(struct wscons_event));
+	len = read(device->fd, wsevents, sizeof(wsevents));
 	if (len <= 0 || (len % sizeof(struct wscons_event)) != 0)
 		return;
 
@@ -282,20 +350,27 @@ wscons_seat_get(struct libinput *libinpu
 
 LIBINPUT_EXPORT struct libinput *
 libinput_udev_create_context(const struct libinput_interface *interface,
-			     void *user_data,
-			     struct udev *udev)
+				 void *user_data,
+				 struct udev *udev)
 {
-	struct libinput *libinput;
+	struct udev_input *input;
 
-	libinput = calloc(1, sizeof(*libinput));
-	if (libinput == NULL)
+	if (!interface || !udev)
 		return NULL;
 
-	if (libinput_init(libinput, interface, &interface_backend, user_data) != 0) {
-		free(libinput);
+	input = calloc(1, sizeof(*input));
+	if (!input)
+		return NULL;
+
+	if (libinput_init(&input->base, interface, &interface_backend, user_data) != 0) {
+		libinput_unref(&input->base);
+		free(input);
 		return NULL;
 	}
-	return libinput;
+
+	input->udev = udev_ref(udev);
+
+	return &input->base;
 }
 
 LIBINPUT_EXPORT int
@@ -307,6 +382,7 @@ libinput_udev_assign_seat(struct libinpu
 	uint64_t time;
 	struct timespec ts;
 	struct libinput_event *event;
+	struct udev_input *input = (struct udev_input*)libinput;
 
 	/* Add standard devices */
 	for (int i = 0; i < 10; i++) {
@@ -332,6 +408,10 @@ libinput_udev_assign_seat(struct libinpu
 		post_device_event(device, time, LIBINPUT_EVENT_DEVICE_ADDED,
 		    event);
 	}
+
+	if (udev_input_enable(&input->base) < 0)
+		return -1;
+
 	return 0;
 }
 
@@ -517,6 +597,8 @@ wscons_device_init(struct wscons_device 
 {
 	struct libinput_device *device = &wscons_device->base;
 
+	wscons_device->old_value = -1;
+
 	if (strncmp(device->devname, "/dev/wsmouse", 12) == 0) {
 		/* XXX handle tablets and touchpanel */
 		wscons_device->capability = LIBINPUT_DEVICE_CAP_POINTER;
@@ -576,8 +658,18 @@ libinput_path_add_device(struct libinput
 	return device;
 
 err:
-	if (device != NULL)
-		close_restricted(libinput, device->fd);
+	if (device != NULL) {
+		if (device->source)
+			libinput_remove_source(libinput, device->source);
+		if (device->devname) {
+			free(device->devname);
+			device->devname = NULL;
+		}
+		if (device->fd >= 0)
+			close_restricted(libinput, device->fd);
+	} else if (fd >= 0) {
+		close_restricted(libinput, fd);
+	}
 	free(wscons_device);
 	return NULL;
 }
@@ -587,6 +679,7 @@ libinput_path_remove_device(struct libin
 {
 	struct libinput *libinput = device->seat->libinput;
 
+	list_remove(&device->link);
 	libinput_remove_source(libinput, device->source);
 	device->source = NULL;
 
