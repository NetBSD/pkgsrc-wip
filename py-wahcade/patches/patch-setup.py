$NetBSD: patch-setup.py,v 1.2 2013/03/09 21:03:09 othyro Exp $

Resolves "Unknown distribution option: 'priority'".
Fix file names and remove non-existent files.

--- setup.py.orig	2009-06-29 17:15:56.000000000 +0000
+++ setup.py
@@ -42,9 +42,9 @@ setup(
     recommends = 'sdlmame',
     section = 'games',
     #suggests = 'python-pygame (>=1.6), python-imaging (>=1.1.5)',
-    priority = 'optional',
+    #priority = 'optional',
     url = 'http://www.anti-particle.com/wahcade',
-    scripts = ['wahcade', 'wahcade-setup', 'wahcade-layout-editor'],
+    scripts = ['wahcade.py', 'wahcade-setup.py', 'wahcade-layout-editor.py'],
     data_files = [
         ("share/games/wahcade", glob.glob("*.py")),
         ("share/games/wahcade/config.dist", glob.glob("config.dist/*.*")),
@@ -78,7 +78,7 @@ setup(
         ("share/games/wahcade/pixmaps", glob.glob("pixmaps/*.ico")),
         ("share/games/wahcade/templates", glob.glob("templates/*.ini")),
         ("share/applications", glob.glob("*.desktop")),
-        ("share/pixmaps", ["pixmaps/wahcade.png", "pixmaps/wahcade-setup.png", "pixmaps/wahcade-layout-editor.png"]),
+        ("share/pixmaps", ["pixmaps/wahcade.png"]),
         ("share/locale/de/LC_MESSAGES", glob.glob("locale/de/LC_MESSAGES/*.mo")),
         ("share/locale/en/LC_MESSAGES", glob.glob("locale/en/LC_MESSAGES/*.mo")),
         ("share/locale/en_GB/LC_MESSAGES", glob.glob("locale/en_GB/LC_MESSAGES/*.mo")),
