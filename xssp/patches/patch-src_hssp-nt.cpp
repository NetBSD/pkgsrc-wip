$NetBSD$

# Fix unsigned compare

--- src/hssp-nt.cpp.orig	2018-04-06 08:17:20 UTC
+++ src/hssp-nt.cpp
@@ -23,7 +23,7 @@
 #include <boost/lexical_cast.hpp>
 #include <boost/range/adaptor/sliced.hpp>
 #include <boost/regex.hpp>
-#include <boost/tr1/cmath.hpp>
+#include <boost/units/cmath.hpp>
 
 #include <algorithm>
 #include <cmath>
@@ -474,7 +474,7 @@ void MProfile::AdjustXGapCosts(std::vect
     {
       if (ix + d >= m_residues.size() or
         m_residues[ix + d].m_dist[22] > 0 or
-        ix - d < 0 or
+        (long)(ix - d) < 0 or
         m_residues[ix - d].m_dist[22] > 0)
       {
         gop[ix] *= (2 + ((8 - d) * 2)) / 8.f;
