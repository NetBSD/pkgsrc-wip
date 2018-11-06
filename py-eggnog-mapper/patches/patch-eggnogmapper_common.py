$NetBSD$

# Support python 3

--- eggnogmapper/common.py.orig	2018-11-06 00:14:59 UTC
+++ eggnogmapper/common.py
@@ -105,7 +105,7 @@ def set_data_path(data_path):
 def show_binaries():
     for e in (HMMSEARCH, HMMSCAN, HMMSTAT, HMMPGMD, PHMMER, DIAMOND, DATA_PATH,
               get_fasta_path(), get_hmmdb_path(), get_eggnogdb_file(), get_oglevels_file(), get_eggnog_dmnd_db()):
-        print "% 65s" %e, pexists(e)
+        print("% 65s" %e, pexists(e))
 
 def get_call_info():
     text = []
