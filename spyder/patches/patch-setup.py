$NetBSD$

--- setup.py.orig	2015-10-04 10:35:42.000000000 +0000
+++ setup.py
@@ -65,7 +65,7 @@ def get_subpackages(name):
 
 def get_data_files():
     """Return data_files in a platform dependent manner"""
-    if sys.platform.startswith('linux'):
+    if sys.platform.startswith('netbsd'):
         if PY3:
             data_files = [('share/applications', ['scripts/spyder3.desktop']),
                           ('share/pixmaps', ['img_src/spyder3.png'])]
@@ -83,7 +83,7 @@ def get_data_files():
 class MyInstallData(install_data):
     def run(self):
         install_data.run(self)
-        if sys.platform.startswith('linux'):
+        if sys.platform.startswith('netbsd'):
             try:
                 subprocess.call(['update-desktop-database'])
             except:
@@ -207,10 +207,10 @@ def get_packages():
 # NOTE: the '[...]_win_post_install.py' script is installed even on non-Windows
 # platforms due to a bug in pip installation process (see Issue 1158)
 SCRIPTS = ['%s_win_post_install.py' % NAME]
-if PY3 and sys.platform.startswith('linux'):
+if PY3 and sys.platform.startswith('netbsd'):
     SCRIPTS.append('spyder3')
 else:
-    SCRIPTS.append('spyder')
+    SCRIPTS.append('spyder'+sys.version[0:3])
 EXTLIST = ['.mo', '.svg', '.png', '.css', '.html', '.js', '.chm', '.ini',
            '.txt', '.rst', '.qss']
 if os.name == 'nt':
