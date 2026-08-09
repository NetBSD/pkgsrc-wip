$NetBSD$

Avoid char which is ambiguous, and may be signed or unsigned.
https://github.com/USCiLab/cereal/commit/2c647d87d492bea4400e95cf71c2de7270e2f3ab

--- unittests/multimap.hpp.orig	2026-08-09 01:40:56.618204637 +0000
+++ unittests/multimap.hpp
@@ -71,7 +71,7 @@ void test_multimap()
     std::multimap<int8_t, StructExternalSplit> o_esplmultimap;
     for(int j=0; j<100; ++j)
     {
-      auto key = random_value<char>(gen);
+      auto key = random_value<int8_t>(gen);
       o_esplmultimap.insert({key,  { random_value<int>(gen), random_value<int>(gen) }});
       o_esplmultimap.insert({key,  { random_value<int>(gen), random_value<int>(gen) }});
     }
