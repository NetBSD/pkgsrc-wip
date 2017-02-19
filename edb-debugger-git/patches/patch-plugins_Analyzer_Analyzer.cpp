$NetBSD$

--- plugins/Analyzer/Analyzer.cpp.orig	2017-02-18 21:21:09.000000000 +0000
+++ plugins/Analyzer/Analyzer.cpp
@@ -868,7 +868,7 @@ bool Analyzer::will_return(edb::address_
 			return false;
 		}
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD)
 		if(func_name == "_Unwind_Resume") {
 			return false;
 		}
