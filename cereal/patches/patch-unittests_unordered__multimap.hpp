$NetBSD$

Avoid char which is ambiguous, and may be signed or unsigned.
https://github.com/USCiLab/cereal/commit/2c647d87d492bea4400e95cf71c2de7270e2f3ab

--- unittests/unordered_multimap.hpp.orig	2026-08-09 01:43:34.764028570 +0000
+++ unittests/unordered_multimap.hpp
@@ -71,7 +71,7 @@ void test_unordered_multimap()
     std::unordered_multimap<int8_t, StructExternalSplit> o_esplunordered_multimap;
     for(int j=0; j<100; ++j)
     {
-      auto key = random_value<char>(gen);
+      auto key = random_value<int8_t>(gen);
       o_esplunordered_multimap.insert({key,  { random_value<int>(gen), random_value<int>(gen) }});
       o_esplunordered_multimap.insert({key,  { random_value<int>(gen), random_value<int>(gen) }});
     }
