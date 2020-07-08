$NetBSD$

`encoding' argument is only available in Python 3.

--- setup.py.orig	2020-05-05 07:56:05.000000000 +0000
+++ setup.py
@@ -11,7 +11,7 @@ else:
     pygments_deps = 'pygments<2.6.0'
 
 here = path.abspath(path.dirname(__file__))
-with open(path.join(here, 'README.rst'), encoding='utf-8') as f:
+with open(path.join(here, 'README.rst'), **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as f:
     long_description = f.read()
 setup(name='coccigrep',
       version=COCCIGREP_VERSION,
