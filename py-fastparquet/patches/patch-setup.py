$NetBSD$
No need to call git status
--- setup.py.orig	2022-12-05 18:49:37.000000000 +0000
+++ setup.py
@@ -44,7 +44,6 @@ else:
     extra = {'ext_modules': cythonize(modules, language_level=3)}

 install_requires = open('requirements.txt').read().strip().split('\n')
-subprocess.call(["git", "status"], stdout=sys.stdout, stderr=sys.stderr)

 setup(
     name='fastparquet',
