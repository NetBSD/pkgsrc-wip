$NetBSD$

Backport of plank 0.11.89 fix "Constructors of abstract classes
should not be public" (fb624c21c19c7114eef5a1932a43b099ef0555da)
Without this fix, plank is not building anymore with recent pkgsrc.
Porting of plan 0.11.89 currently is blocked by the lack of gnome-menus-3

--- lib/Drawing/Theme.vala.orig 2021-05-15 13:22:18.493326252 +0000
+++ lib/Drawing/Theme.vala
@@ -82,12 +82,12 @@ namespace Plank
		File? theme_folder;
		Gtk.StyleContext style_context;
		
-		public Theme ()
+		protected Theme ()
		{
			theme_folder = get_theme_folder (DEFAULT_NAME);
		}
		
-		public Theme.with_name (string name)
+		protected Theme.with_name (string name)
		{
			theme_folder = get_theme_folder (name);
		}
