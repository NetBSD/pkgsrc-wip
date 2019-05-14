$NetBSD$

Always redraw the entire view instead of only two lines.

With NetBSD curses(3) where `main' and `diff' views are present only the current
two entries are visible in the `main' view.  To reproduce that, after invoking
`tig':

 - press enter
 - press down arrow

Workaround that by redrawing the entire view.

--- src/view.c.orig	2018-07-27 03:18:19.000000000 +0000
+++ src/view.c
@@ -262,17 +262,23 @@ move_view(struct view *view, enum reques
 		return;
 	}
 
+	redraw_view(view);
+
+#if 0
 	/* Repaint the old "current" line if we be scrolling */
 	if (ABS(steps) < view->height)
 		draw_view_line(view, view->pos.lineno - steps - view->pos.offset);
+#endif
 
 	if (scroll_steps) {
 		do_scroll_view(view, scroll_steps);
 		return;
 	}
 
+#if 0
 	/* Draw the current line */
 	draw_view_line(view, view->pos.lineno - view->pos.offset);
+#endif
 
 	wnoutrefresh(view->win);
 	report_clear();
