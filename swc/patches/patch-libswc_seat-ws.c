$NetBSD$

--- libswc/seat-ws.c.orig	2019-08-11 16:54:52.381600368 +0000
+++ libswc/seat-ws.c
@@ -0,0 +1,332 @@
+/* swc: libswc/seat-ws.c
+ *
+ * Copyright (c) 2013, 2014 Michael Forney
+ * Copyright (c) 2019 Nia Alarie
+ *
+ * Permission is hereby granted, free of charge, to any person obtaining a copy
+ * of this software and associated documentation files (the "Software"), to deal
+ * in the Software without restriction, including without limitation the rights
+ * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
+ * copies of the Software, and to permit persons to whom the Software is
+ * furnished to do so, subject to the following conditions:
+ *
+ * The above copyright notice and this permission notice shall be included in
+ * all copies or substantial portions of the Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
+ * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
+ * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
+ * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
+ * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
+ * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
+ * SOFTWARE.
+ */
+
+#include "seat.h"
+#include "compositor.h"
+#include "data_device.h"
+#include "event.h"
+#include "internal.h"
+#include "keyboard.h"
+#include "launch.h"
+#include "pointer.h"
+#include "screen.h"
+#include "surface.h"
+#include "util.h"
+
+#include <dev/wscons/wsconsio.h>
+
+#include <stdbool.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <fcntl.h>
+#include <unistd.h>
+
+static struct {
+	char *name;
+	uint32_t capabilities;
+
+	int mouse_fd;
+	int kbd_fd;
+	bool ignore;
+
+	struct wl_event_source *mouse_source;
+	struct wl_event_source *kbd_source;
+
+	struct wl_listener swc_listener;
+
+	struct keyboard keyboard;
+	struct pointer pointer;
+	struct data_device data_device;
+
+	struct wl_global *global;
+	struct wl_list resources;
+} seat;
+
+const struct swc_seat swc_seat = {
+	.pointer = &seat.pointer,
+	.keyboard = &seat.keyboard,
+	.data_device = &seat.data_device,
+};
+
+static void
+handle_keyboard_focus_event(struct wl_listener *listener, void *data)
+{
+	struct event *ev = data;
+	struct input_focus_event_data *event_data = ev->data;
+
+	if (ev->type != INPUT_FOCUS_EVENT_CHANGED)
+		return;
+
+	if (event_data->new) {
+		struct wl_client *client = wl_resource_get_client(event_data->new->surface->resource);
+
+		/* Offer the selection to the new focus. */
+		data_device_offer_selection(&seat.data_device, client);
+	}
+}
+
+static struct wl_listener keyboard_focus_listener = {
+	.notify = handle_keyboard_focus_event,
+};
+
+static void
+handle_data_device_event(struct wl_listener *listener, void *data)
+{
+	struct event *ev = data;
+
+	if (ev->type != DATA_DEVICE_EVENT_SELECTION_CHANGED)
+		return;
+
+	if (seat.keyboard.focus.client)
+		data_device_offer_selection(&seat.data_device, seat.keyboard.focus.client);
+}
+
+static struct wl_listener data_device_listener = {
+	.notify = handle_data_device_event,
+};
+
+static void
+handle_swc_event(struct wl_listener *listener, void *data)
+{
+	struct event *ev = data;
+
+	switch (ev->type) {
+	case SWC_EVENT_DEACTIVATED:
+		seat.ignore = true;
+		keyboard_reset(&seat.keyboard);
+		break;
+	case SWC_EVENT_ACTIVATED:
+		seat.ignore = false;
+		break;
+	}
+}
+
+/* Wayland Seat Interface */
+static void
+get_pointer(struct wl_client *client, struct wl_resource *resource, uint32_t id)
+{
+	pointer_bind(&seat.pointer, client, wl_resource_get_version(resource), id);
+}
+
+static void
+get_keyboard(struct wl_client *client, struct wl_resource *resource, uint32_t id)
+{
+	keyboard_bind(&seat.keyboard, client, wl_resource_get_version(resource), id);
+}
+
+static void
+get_touch(struct wl_client *client, struct wl_resource *resource, uint32_t id)
+{
+	/* XXX: Implement */
+}
+
+static struct wl_seat_interface seat_implementation = {
+	.get_pointer = get_pointer,
+	.get_keyboard = get_keyboard,
+	.get_touch = get_touch,
+};
+
+static void
+bind_seat(struct wl_client *client, void *data, uint32_t version, uint32_t id)
+{
+	struct wl_resource *resource;
+
+	if (version > 4)
+		version = 4;
+
+	resource = wl_resource_create(client, &wl_seat_interface, version, id);
+	wl_resource_set_implementation(resource, &seat_implementation, NULL, &remove_resource);
+	wl_list_insert(&seat.resources, wl_resource_get_link(resource));
+
+	if (version >= 2)
+		wl_seat_send_name(resource, seat.name);
+
+	wl_seat_send_capabilities(resource, seat.capabilities);
+}
+
+static int
+handle_ws_data(int fd, uint32_t mask, void *data)
+{
+	struct wscons_event ev;
+
+	while (!seat.ignore && (read(fd, &ev, sizeof(ev))) != -1) {
+		uint32_t state, time;
+		int key;
+		wl_fixed_t pos;
+
+		time = ev.time.tv_sec + (ev.time.tv_nsec / 1000000L);
+		switch (ev.type) {
+		case WSCONS_EVENT_KEY_UP:
+			state = WL_KEYBOARD_KEY_STATE_RELEASED;
+			key = ev.value;
+			keyboard_handle_key(&seat.keyboard, time, key, state);
+			break;
+		case WSCONS_EVENT_KEY_DOWN:
+			state = WL_KEYBOARD_KEY_STATE_PRESSED;
+			key = ev.value;
+			keyboard_handle_key(&seat.keyboard, time, key, state);
+			break;
+		case WSCONS_EVENT_ALL_KEYS_UP:
+			break;
+		case WSCONS_EVENT_MOUSE_UP:
+			state = WL_POINTER_BUTTON_STATE_RELEASED;
+			key = ev.value;
+			pointer_handle_button(&seat.pointer, time, key, state);
+			break;
+		case WSCONS_EVENT_MOUSE_DOWN:
+			state = WL_POINTER_BUTTON_STATE_PRESSED;
+			key = ev.value;
+			pointer_handle_button(&seat.pointer, time, key, state);
+			break;
+		case WSCONS_EVENT_MOUSE_DELTA_X:
+			pos = wl_fixed_from_int(ev.value);
+			pointer_handle_relative_motion(&seat.pointer, time, pos, 0);
+			break;
+		case WSCONS_EVENT_MOUSE_DELTA_Y:
+			pos = wl_fixed_from_int(ev.value);
+			pointer_handle_relative_motion(&seat.pointer, time, 0, pos);
+			break;
+		case WSCONS_EVENT_MOUSE_DELTA_Z:
+			pos = wl_fixed_from_int(ev.value);
+			break;
+		case WSCONS_EVENT_MOUSE_DELTA_W:
+			pos = wl_fixed_from_int(ev.value);
+			break;
+		case WSCONS_EVENT_MOUSE_ABSOLUTE_X:
+			pos = wl_fixed_from_int(ev.value);
+			pointer_handle_absolute_motion(&seat.pointer, time, pos, 0);
+			break;
+		case WSCONS_EVENT_MOUSE_ABSOLUTE_Y:
+			pos = wl_fixed_from_int(ev.value);
+			pointer_handle_absolute_motion(&seat.pointer, time, 0, pos);
+			break;	
+		case WSCONS_EVENT_MOUSE_ABSOLUTE_Z:
+			pos = wl_fixed_from_int(ev.value);
+			break;	
+		case WSCONS_EVENT_MOUSE_ABSOLUTE_W:
+			pos = wl_fixed_from_int(ev.value);
+			break;	
+		
+		}
+	}
+	return 0;
+}
+
+static bool
+initialize_wscons(void)
+{
+	if ((seat.mouse_fd = launch_open_device("/dev/wsmouse", O_RDONLY | O_NONBLOCK)) == -1) {
+		goto error0;
+	}
+	if ((seat.kbd_fd = launch_open_device("/dev/wskbd", O_RDONLY | O_NONBLOCK)) == -1) {
+		goto error1;
+	}
+
+	seat.kbd_source = wl_event_loop_add_fd
+		(swc.event_loop, seat.kbd_fd, WL_EVENT_READABLE,
+		 &handle_ws_data, NULL);
+	seat.mouse_source = wl_event_loop_add_fd
+		(swc.event_loop, seat.mouse_fd, WL_EVENT_READABLE,
+		 &handle_ws_data, NULL);
+	return true;
+error1:
+	close(seat.mouse_fd);
+error0:
+	return false;
+}
+
+bool
+seat_initialize(const char *seat_name)
+{
+	if (!(seat.name = strdup(seat_name))) {
+		ERROR("Could not allocate seat name string\n");
+		goto error0;
+	}
+
+	seat.capabilities = WL_SEAT_CAPABILITY_KEYBOARD | WL_SEAT_CAPABILITY_POINTER;
+	seat.global = wl_global_create(swc.display, &wl_seat_interface, 4, NULL, &bind_seat);
+
+	if (!seat.global)
+		goto error1;
+
+	wl_list_init(&seat.resources);
+	seat.swc_listener.notify = &handle_swc_event;
+	wl_signal_add(&swc.event_signal, &seat.swc_listener);
+
+	if (!data_device_initialize(&seat.data_device)) {
+		ERROR("Could not initialize data device\n");
+		goto error2;
+	}
+
+	wl_signal_add(&seat.data_device.event_signal, &data_device_listener);
+
+	if (!keyboard_initialize(&seat.keyboard)) {
+		ERROR("Could not initialize keyboard\n");
+		goto error3;
+	}
+
+	wl_signal_add(&seat.keyboard.focus.event_signal, &keyboard_focus_listener);
+
+	if (!pointer_initialize(&seat.pointer)) {
+		ERROR("Could not initialize pointer\n");
+		goto error4;
+	}
+
+	if (!initialize_wscons())
+		goto error5;
+
+	return true;
+
+error5:
+	pointer_finalize(&seat.pointer);
+error4:
+	keyboard_finalize(&seat.keyboard);
+error3:
+	data_device_finalize(&seat.data_device);
+error2:
+	wl_global_destroy(seat.global);
+error1:
+	free(seat.name);
+error0:
+	return false;
+}
+
+void
+seat_finalize(void)
+{
+	wl_event_source_remove(seat.mouse_source);
+	wl_event_source_remove(seat.kbd_source);
+	close(seat.mouse_fd);
+	seat.mouse_fd = -1;
+	close(seat.kbd_fd);
+	seat.kbd_fd = -1;
+
+	pointer_finalize(&seat.pointer);
+	keyboard_finalize(&seat.keyboard);
+	data_device_finalize(&seat.data_device);
+
+	wl_global_destroy(seat.global);
+	free(seat.name);
+}
