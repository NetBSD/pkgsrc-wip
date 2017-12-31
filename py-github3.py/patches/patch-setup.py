$NetBSD$

uritemplate.py was merged to uritemplate on 2016-08-29 and on pkgsrc only the
latter is available. Adjust the requirements accordingly.

--- setup.py.orig	2016-02-17 22:36:54.000000000 +0000
+++ setup.py
@@ -34,7 +34,7 @@ if sys.argv[-1] in ("submit", "publish")
     os.system("python setup.py bdist_wheel sdist upload")
     sys.exit()
 
-requires.extend(["requests >= 2.0", "uritemplate.py >= 0.2.0"])
+requires.extend(["requests >= 2.0", "uritemplate >= 0.2.0"])
 
 __version__ = ''
 with open('github3/__about__.py', 'r') as fd:
