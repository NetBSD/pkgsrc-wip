$NetBSD$

* Hide unsupported events on NetBSD

--- src/wscons.c.orig	2025-09-09 13:28:44.467395163 +0000
+++ src/wscons.c
@@ -209,13 +209,17 @@ wscons_process(struct libinput_device *d
 		axis_notify_event(device, time, &accel, &raw);
 		break;
 
+#ifndef __NetBSD__
 	case WSCONS_EVENT_SYNC:
 		break;
+#endif
 
 	case WSCONS_EVENT_MOUSE_ABSOLUTE_Z:
 	case WSCONS_EVENT_MOUSE_ABSOLUTE_W:
+#ifndef __NetBSD__
 	case WSCONS_EVENT_TOUCH_WIDTH:
 	case WSCONS_EVENT_TOUCH_RESET:
+#endif
 		/* ignore those */
 		break;
 	default:
