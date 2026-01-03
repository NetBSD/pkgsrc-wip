$NetBSD$

Allow of NetBSD/OpenBSD wscons differences

--- src/wscons.c.orig	2025-08-02 09:40:32.000000000 +0000
+++ src/wscons.c
@@ -209,13 +209,19 @@ wscons_process(struct libinput_device *d
 		axis_notify_event(device, time, &accel, &raw);
 		break;
 
+#ifdef WSCONS_EVENT_SYNC
 	case WSCONS_EVENT_SYNC:
 		break;
+#endif
 
 	case WSCONS_EVENT_MOUSE_ABSOLUTE_Z:
 	case WSCONS_EVENT_MOUSE_ABSOLUTE_W:
+#ifdef WSCONS_EVENT_TOUCH_WIDTH
 	case WSCONS_EVENT_TOUCH_WIDTH:
+#endif
+#ifdef WSCONS_EVENT_TOUCH_RESET
 	case WSCONS_EVENT_TOUCH_RESET:
+#endif
 		/* ignore those */
 		break;
 	default:
