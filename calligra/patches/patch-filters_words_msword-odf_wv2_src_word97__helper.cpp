$NetBSD: patch-filters_words_msword-odf_wv2_src_word97__helper.cpp,v 1.1 2014/03/29 14:10:18 nsloss Exp $

Fixes build with clang as abs is not in std.

--- filters/words/msword-odf/wv2/src/word97_helper.cpp.orig	2014-03-29 12:07:59.000000000 +0000
+++ filters/words/msword-odf/wv2/src/word97_helper.cpp
@@ -730,7 +730,7 @@ namespace
         {
             m_center = readS16( ptr + index * sizeof( S16 ) );
             // A negative value doesn't make sense here, right? Hmmm
-            m_plusMinus = std::abs( readS16( ptr + itbdDelMax * sizeof( S16 ) + index * sizeof( S16 ) ) );
+            m_plusMinus = abs( readS16( ptr + itbdDelMax * sizeof( S16 ) + index * sizeof( S16 ) ) );
         }
 
         bool contains( S16 position ) const { return m_center - m_plusMinus <= position && m_center + m_plusMinus >= position; }
