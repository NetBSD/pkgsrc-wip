$NetBSD$

Backport of plank 0.11.89 fix "Constructors of abstract classes
should not be public" (fb624c21c19c7114eef5a1932a43b099ef0555da)
Without this fix, plank is not building anymore with recent pkgsrc.
Porting of plan 0.11.89 currently is blocked by the lack of gnome-menus-3

--- lib/Drawing/Renderer.vala.orig  2021-05-15 13:21:33.222562026 +0000
+++ lib/Drawing/Renderer.vala
@@ -38,7 +38,7 @@ namespace Plank
		/**
		 * Creates a new animation renderer.
		 */
-		public Renderer (Gtk.Widget widget)
+		protected Renderer (Gtk.Widget widget)
		{
			Object (widget : widget);
		}
