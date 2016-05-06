$NetBSD$

https://bitbucket.org/durin42/hgsubversion/commits/2ae4fb5bfab90f93ebf074e382798a7d2e67137a

--- hgsubversion/__init__.py.orig	2015-05-07 08:46:09.000000000 +0000
+++ hgsubversion/__init__.py
@@ -191,7 +191,8 @@ hg.schemes.update({ 'file': _lookup, 'ht
                     'svn': svnrepo, 'svn+ssh': svnrepo, 'svn+http': svnrepo,
                     'svn+https': svnrepo})
 
-commands.optionalrepo += ' svn'
+if hgutil.safehasattr(commands, 'optionalrepo'):
+    commands.optionalrepo += ' svn'
 
 cmdtable = {
     "svn":
