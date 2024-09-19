$NetBSD$

--- src/VBox/ValidationKit/testdriver/vbox.py.orig	2016-03-04 19:30:17.000000000 +0000
+++ src/VBox/ValidationKit/testdriver/vbox.py
@@ -1015,7 +1015,7 @@ class TestDriver(base.TestDriver):      
         cMsFudge      = 1;
         sVBoxSVC      = '%s/VBoxSVC' % (self.oBuild.sInstallPath,); ## @todo .exe and stuff.
         if self.fVBoxSvcInDebugger:
-            if self.sHost in ('darwin', 'freebsd', 'linux', 'solaris', ):
+            if self.sHost in ('darwin', 'freebsd', 'linux', 'solaris', 'netbsd'):
                 # Start VBoxSVC in gdb in a new terminal.
                 #sTerm = '/usr/bin/gnome-terminal'; - doesn't work, some fork+exec stuff confusing us.
                 sTerm = '/usr/bin/xterm';
@@ -1057,7 +1057,7 @@ class TestDriver(base.TestDriver):      
             else:
                 reporter.error('Port me!');
         else: # Run without a debugger attached.
-            if self.sHost in ('darwin', 'freebsd', 'linux', 'solaris', ):
+            if self.sHost in ('darwin', 'freebsd', 'linux', 'solaris', 'netbsd'):
                 #
                 # XPCOM - We can use a pipe to let VBoxSVC notify us when it's ready.
                 #
@@ -1689,7 +1689,7 @@ class TestDriver(base.TestDriver):      
                 if os.path.isfile(sVBoxSvcRelLog + sSuff):
                     reporter.addLogFile(sVBoxSvcRelLog + sSuff, 'log/release/svc', 'Release log file for VBoxSVC');
             # Testbox debugging - START - TEMPORARY, REMOVE ASAP.
-            if self.sHost in ('darwin', 'freebsd', 'linux', 'solaris', ):
+            if self.sHost in ('darwin', 'freebsd', 'linux', 'solaris', 'netbsd'):
                 try:
                     print '> ls -la %s' % (os.path.join(self.sScratchPath, 'VBoxUserHome'),);
                     utils.processCall(['ls', '-la', os.path.join(self.sScratchPath, 'VBoxUserHome')]);
@@ -3289,4 +3289,3 @@ class TestDriver(base.TestDriver):      
         return fRc;
 
     # pylint: enable=R0914,R0913
-
