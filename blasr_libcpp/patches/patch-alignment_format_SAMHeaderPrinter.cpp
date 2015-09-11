$NetBSD: patch-alignment_format_SAMHeaderPrinter.cpp,v 1.1 2015/09/11 16:48:33 outpaddling Exp $

--- alignment/format/SAMHeaderPrinter.cpp.orig	2015-08-12 17:41:23.000000000 +0000
+++ alignment/format/SAMHeaderPrinter.cpp
@@ -183,8 +183,10 @@ SAMHeaderPG::SAMHeaderPG(const std::stri
 }
 
 // SAMHeaderSQ
-SAMHeaderSQ::SAMHeaderSQ(const std::string & sn, const DNALength & ln, const std::string & md5)
-: SAMHeaderSQ(sn, std::to_string(ln), md5) {}
+SAMHeaderSQ::SAMHeaderSQ(const std::string & sn, const DNALength & ln, const std::string & md5) {}
+
+// Doesn't compile in GCC 4.4.7.  C++11ism?
+// : SAMHeaderSQ(sn, std::to_string(static_cast<unsigned long long>(ln)), md5) {}
 
 SAMHeaderSQ::SAMHeaderSQ(const std::string & sn, const string & ln, const std::string & md5)
 : SAMHeaderGroup() {
@@ -400,7 +402,7 @@ SAMHeaderPGs SAMHeaderPrinter::MakePGs(c
 #endif
     }
 
-    pgs.Add(SAMHeaderPG(std::to_string(prog_id), progName, progVersion, commandLine));
+    pgs.Add(SAMHeaderPG(std::to_string(static_cast<unsigned long long>(prog_id)), progName, progVersion, commandLine));
     return pgs;
 }
 
