$NetBSD$

# Support python 3

--- eggnogmapper/search.py.orig	2017-11-15 10:45:47 UTC
+++ eggnogmapper/search.py
@@ -28,7 +28,7 @@ B62_IDENTITIES = {'A': 4, 'B': 4, 'C': 9
 def safe_cast(v):
     try:
         return float(v)
-    except ValueError:
+    except(ValueError):
         return v.strip()
 
 
@@ -57,7 +57,7 @@ def scan_hits(data, address="127.0.0.1",
     s = socket.socket()
     try:
         s.connect((address, port))
-    except Exception, e:
+    except(Exception, e):
         print(address, port, e)
         raise
     s.sendall(data)
@@ -191,7 +191,7 @@ def iter_hits(source, translate, query_t
 
     try:
         max_hits = int(max_hits)
-    except Exception:
+    except(Exception):
         max_hits = None
 
     if scantype == 'mem' and query_type == "seq":
@@ -225,11 +225,11 @@ def hmmscan(query_file, translate, datab
     OUT = NamedTemporaryFile(dir=tempdir)
     if translate or maxseqlen:
         if translate:
-            print 'translating query input file'
+            print('translating query input file')
         Q = NamedTemporaryFile()
         for name, seq in seqio.iter_fasta_seqs(query_file, translate=translate):
             if maxseqlen is None or len(seq) <= maxseqlen:
-                print >>Q, ">%s\n%s" % (name, seq)
+                print(">%s\n%s" % (name, seq)) >> Q
         Q.flush()
         query_file = Q.name
 
