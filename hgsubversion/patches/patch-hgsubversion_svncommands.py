$NetBSD$

https://bitbucket.org/durin42/hgsubversion/commits/2ae4fb5bfab90f93ebf074e382798a7d2e67137a

--- hgsubversion/svncommands.py.orig	2015-05-07 08:46:09.000000000 +0000
+++ hgsubversion/svncommands.py
@@ -490,6 +490,9 @@ def svn(ui, repo, subcommand, *args, **o
         else:
             raise
 
+svn.optionalrepo = True
+svn.norepo = False
+
 table = {
     'genignore': genignore,
     'info': info,
