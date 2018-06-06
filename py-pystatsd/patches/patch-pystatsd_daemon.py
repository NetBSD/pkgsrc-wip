$NetBSD$

Python 3 compatability.

--- pystatsd/daemon.py.orig	2013-06-14 19:27:00.000000000 +0000
+++ pystatsd/daemon.py
@@ -27,7 +27,7 @@ class Daemon(object):
             if pid > 0:
                 # First parent; exit.
                 sys.exit(0)
-        except OSError, e:
+        except OSError as e:
             sys.stderr.write('Could not fork! %d (%s)\n' %
                              (e.errno, e.strerror))
             sys.exit(1)
@@ -35,7 +35,7 @@ class Daemon(object):
         # Disconnect from parent environment.
         os.chdir('/')
         os.setsid()
-        os.umask(0022)
+        os.umask(0o022)
 
         # Fork again.
         try:
@@ -43,7 +43,7 @@ class Daemon(object):
             if pid > 0:
                 # Second parent; exit.
                 sys.exit(0)
-        except OSError, e:
+        except OSError as e:
             sys.stderr.write('Could not fork (2nd)! %d (%s)\n' %
                              (e.errno, e.strerror))
             sys.exit(1)
@@ -98,13 +98,13 @@ class Daemon(object):
             while 1:
                 os.kill(pid, SIGTERM)
                 time.sleep(0.1)
-        except OSError, e:
+        except OSError as e:
             e = str(e)
             if e.find('No such process') > 0:
                 if os.path.exists(self.pidfile):
                     os.remove(self.pidfile)
                 else:
-                    print e
+                    print(e)
                     sys.exit(1)
 
     def restart(self, *args, **kw):
