$NetBSD$

Fix negative values in scrollh()/scrollv().

Shared upstream via:

 <https://lists.suckless.org/hackers/1906/16887.html>

--- libsurf-webext.c.orig	2020-06-01 15:14:21.000000000 +0000
+++ libsurf-webext.c
@@ -91,14 +91,14 @@ readpipe(GIOChannel *s, GIOCondition c, 
 			return TRUE;
 		ww = webkit_dom_dom_window_get_inner_width(view);
 		webkit_dom_dom_window_scroll_by(view,
-		                                (ww / 100) * msg[3], 0);
+		                                (ww / 100) * (signed char)msg[3], 0);
 		break;
 	case 'v':
 		if (msgsz != 4)
 			return TRUE;
 		wh = webkit_dom_dom_window_get_inner_height(view);
 		webkit_dom_dom_window_scroll_by(view,
-		                                0, (wh / 100) * msg[3]);
+		                                0, (wh / 100) * (signed char)msg[3]);
 		break;
 	}
 
