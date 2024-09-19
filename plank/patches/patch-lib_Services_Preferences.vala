$NetBSD$

Backport of plank 0.11.89 fix "Constructors of abstract classes
should not be public" (fb624c21c19c7114eef5a1932a43b099ef0555da)
Without this fix, plank is not building anymore with recent pkgsrc.
Porting of plan 0.11.89 currently is blocked by the lack of gnome-menus-3

--- lib/Services/Preferences.vala.orig  2021-05-15 13:24:49.046738188 +0000
+++ lib/Services/Preferences.vala
@@ -65,7 +65,7 @@ namespace Plank
		/**
		 * Creates a new preferences object with no backing file.
		 */
-		public Preferences ()
+		protected Preferences ()
		{
		}
		
@@ -151,7 +151,7 @@ namespace Plank
		 *
		 * @param file the {@link GLib.File} of the backing file for this preferences
		 */
-		public Preferences.with_file (GLib.File file)
+		protected Preferences.with_file (GLib.File file)
		{
			init_from_file (file);
		}
@@ -161,7 +161,7 @@ namespace Plank
		 *
		 * @param filename of the backing file for this preferences
		 */
-		public Preferences.with_filename (string filename)
+		protected Preferences.with_filename (string filename)
		{
			init_from_file (Paths.AppConfigFolder.get_child (filename));
		}
