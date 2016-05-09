$NetBSD$

--- tests/test-compositor.c.orig	2015-11-25 09:48:11.000000000 +0000
+++ tests/test-compositor.c
@@ -104,7 +104,10 @@ client_destroyed(struct wl_listener *lis
 	ci = wl_container_of(listener, ci, destroy_listener);
 	d = ci->display;
 
+#ifndef __NetBSD__
 	assert(waitid(P_PID, ci->pid, &status, WEXITED) != -1);
+#else
+#endif
 
 	switch (status.si_code) {
 	case CLD_KILLED:
