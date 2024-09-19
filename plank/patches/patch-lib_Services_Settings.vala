$NetBSD$

Backport of plank 0.11.89 fix "Constructors of abstract classes
should not be public" (fb624c21c19c7114eef5a1932a43b099ef0555da)
Without this fix, plank is not building anymore with recent pkgsrc.
Porting of plank 0.11.89 currently is blocked by the lack of gnome-menus-3

--- lib/Services/Settings.vala.orig 2021-05-15 13:25:39.528936265 +0000
+++ lib/Services/Settings.vala
@@ -33,7 +33,7 @@ namespace Plank
		/**
		 * {@inheritDoc}
		 */
-		public Settings (string schema)
+		protected Settings (string schema)
		{
			Object (settings: new GLib.Settings (schema));
		}
@@ -41,7 +41,7 @@ namespace Plank
		/**
		 * {@inheritDoc}
		 */
-		public Settings.with_path (string schema, string path)
+		protected Settings.with_path (string schema, string path)
		{
			Object (settings: new GLib.Settings.with_path (schema, path));
		}
