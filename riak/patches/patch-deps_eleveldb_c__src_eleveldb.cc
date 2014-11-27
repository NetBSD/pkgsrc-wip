$NetBSD: patch-deps_eleveldb_c__src_eleveldb.cc,v 1.2 2014/11/27 13:14:48 fhajny Exp $

At least on SunOS, 32bit size_t will be unsigned int, breaking expectations here.
--- deps/eleveldb/c_src/eleveldb.cc.orig	2014-11-05 19:41:07.000000000 +0000
+++ deps/eleveldb/c_src/eleveldb.cc
@@ -240,7 +240,7 @@ ERL_NIF_TERM parse_init_option(ErlNifEnv
     {
         if (option[0] == eleveldb::ATOM_TOTAL_LEVELDB_MEM)
         {
-            size_t memory_sz;
+            unsigned long memory_sz;
             if (enif_get_ulong(env, option[1], &memory_sz))
             {
                 if (memory_sz != 0)
@@ -328,7 +328,7 @@ ERL_NIF_TERM parse_open_option(ErlNifEnv
         }
         else if (option[0] == eleveldb::ATOM_BLOCK_CACHE_THRESHOLD)
         {
-            size_t memory_sz;
+            unsigned long memory_sz;
             if (enif_get_ulong(env, option[1], &memory_sz))
             {
                 if (memory_sz != 0)
