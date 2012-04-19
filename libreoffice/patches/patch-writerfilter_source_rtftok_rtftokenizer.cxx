$NetBSD: patch-writerfilter_source_rtftok_rtftokenizer.cxx,v 1.1 2012/04/19 19:15:06 ftigeot Exp $

--- writerfilter/source/rtftok/rtftokenizer.cxx.orig	2012-03-27 16:22:01.000000000 +0000
+++ writerfilter/source/rtftok/rtftokenizer.cxx
@@ -213,6 +213,11 @@ int RTFTokenizer::resolveKeyword()
     {
         aBuf.append(ch);
         Strm() >> ch;
+        if (Strm().IsEof())
+        {
+            ch = ' ';
+            break;
+        }
     }
     if (aBuf.getLength() > 32)
         // See RTF spec v1.9.1, page 7
@@ -237,6 +242,11 @@ int RTFTokenizer::resolveKeyword()
         {
             aParameter.append(ch);
             Strm() >> ch;
+            if (Strm().IsEof())
+            {
+                ch = ' ';
+                break;
+            }
         }
         nParam = aParameter.makeStringAndClear().toInt32();
         if (bNeg)
