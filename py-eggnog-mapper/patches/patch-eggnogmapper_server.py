$NetBSD$

# Support python 3

--- eggnogmapper/server.py.orig	2018-11-06 00:18:53 UTC
+++ eggnogmapper/server.py
@@ -30,7 +30,7 @@ def server_functional(host, port, dbtype
     if server_up(host, port):
         try:
             search.get_hits("test", "TESTSEQ", host, port, dbtype)
-        except Exception, e:
+        except(Exception, e):
             #print 'Server not ready', e
             return False
         else:
@@ -94,7 +94,7 @@ def generate_idmap(dbpath):
     if dbpath.endswith(".h3f"):
         dbpath = dbpath.replace(".h3f", "")
     cmd = """%s %s |grep -v '#'|awk '{print $1" "$2}' > %s""" %(HMMSTAT, dbpath, dbpath+'.idmap')
-    print colorify(cmd, "cyan")
+    print(colorify(cmd, "cyan"))
     print('Generating idmap in '+dbpath+'.idmap')
     return os.system(cmd) == 0
     
