$NetBSD$

Mozilla/firefox project specific scripts.

--- setup.py.orig	2016-11-02 19:01:16.000000000 +0000
+++ setup.py
@@ -145,9 +145,6 @@ translatescripts = [
 translatebashscripts = [
     join(*('tools', ) + script) for script in [
         ('junitmsgfmt', ),
-        ('mozilla', 'build_firefox.sh'),
-        ('mozilla', 'buildxpi.py'),
-        ('mozilla', 'get_moz_enUS.py'),
         ('pocommentclean', ),
         ('pocompendium', ),
         ('pomigrate2', ),
@@ -430,7 +427,7 @@ def getdatafiles():
              for f in os.listdir(srcdir) if isfile(join(srcdir, f))])
 
     docfiles = []
-    for subdir in ['docs', 'share']:
+    for subdir in ['share']:
         docwalk = os.walk(subdir)
         for docs in docwalk:
             files = listfiles(docs[0])
