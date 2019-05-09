$NetBSD$

- Avoid too strict version requirements.
- Depends on uritemplate, not uritemplate.py

--- setup.py.orig	2019-04-07 18:12:11.000000000 +0000
+++ setup.py
@@ -109,17 +109,17 @@ def main():
     if HAVE_SETUPTOOLS:
         skw['setup_requires'] = ['ply']
         skw['install_requires'] = [
-            'numpydoc>=0.5,<1.0',
-            'ply>=3.4,<4.0',
-            'prompt_toolkit>=2.0.0,<2.1.0',
-            'requests>=2.8.1,<3.0.0',
-            'colorama>=0.3.3,<1.0.0',
-            'click>=5.1,<7.0',
-            'pygments>=2.0.2,<3.0.0',
-            'feedparser>=5.2.1,<6.0.0',
-            'pytz>=2016.3,<2017.0',
-            'docopt>=0.6.2,<1.0.0',
-            'uritemplate.py>=1.0.0,<4.0.0',
+            'numpydoc>=0.5',
+            'ply>=3.4',
+            'prompt_toolkit>=2.0.0',
+            'requests>=2.8.1',
+            'colorama>=0.3.3',
+            'click>=5.1',
+            'pygments>=2.0.2',
+            'feedparser>=5.2.1',
+            'pytz>=2016.3',
+            'docopt>=0.6.2',
+            'uritemplate>=1.0.0',
         ],
         skw['entry_points'] = {
             'pygments.lexers': ['gitsome = xonsh.pyghooks:XonshLexer',
