$NetBSD$

# Support python 3

--- eggnogmapper/annota.py.orig	2018-11-06 00:14:05 UTC
+++ eggnogmapper/annota.py
@@ -269,9 +269,9 @@ def get_annotated_orthologs(target_membe
     cmd3 = 'SELECT name, pname, go, kegg FROM member WHERE name in (%s);' % in_clause
     t1 = time.time()
     db.execute(cmd3)
-    print time.time() - t1
+    print(time.time() - t1)
     functions = {e[0]: e[1:] for e in db.fetchall()}
-    print time.time() - t1
+    print(time.time() - t1)
 
     #print len(all_orthologs), list(all_orthologs)[:10], in_clause[:10]
     #print len([b for a,b in functions.iteritems() if b[0] ])
