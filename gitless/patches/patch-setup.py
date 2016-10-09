$NetBSD$

Do not insist on particular version numbers of dependencies.
pkgsrc has newer ones that work.

--- setup.py.orig	2016-06-15 17:51:04.000000000 +0000
+++ setup.py
@@ -36,7 +36,7 @@ if sys.argv[-1] == 'gl-build':
   sys.exit()
 
 
-reqs = ['pygit2==0.23.0', 'sh==1.11', 'clint==0.3.6']
+reqs = [] # ['pygit2==0.23.0', 'sh==1.11', 'clint==0.3.6']
 if sys.version_info < (2, 7) or (
     sys.version_info < (3, 3) and sys.version_info > (3, 0)):
   reqs.append('argparse')
