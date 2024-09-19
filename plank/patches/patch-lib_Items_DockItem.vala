$NetBSD$

Backport of plank 0.11.89 fix "Constructors of abstract classes
should not be public" (fb624c21c19c7114eef5a1932a43b099ef0555da)
Without this fix, plank is not building anymore with recent pkgsrc.
Porting of plan 0.11.89 currently is blocked by the lack of gnome-menus-3

--- lib/Items/DockItem.vala.orig    2021-05-15 13:23:45.995070431 +0000
+++ lib/Items/DockItem.vala
@@ -133,7 +133,7 @@ namespace Plank
		/**
		 * Creates a new dock item.
		 */
-		public DockItem ()
+		protected DockItem ()
		{
			GLib.Object (Prefs: new DockItemPreferences ());
		}
