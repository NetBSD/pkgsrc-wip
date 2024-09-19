$NetBSD: patch-src_CLP.cpp,v 1.1 2014/02/05 09:36:21 nsloss Exp $

Fix clang complaint about constructor being default constructor.

--- src/CLP.cpp.orig	2012-06-26 15:46:34.000000000 +0000
+++ src/CLP.cpp
@@ -176,13 +176,13 @@ void CLP::_processMysqlArguments(std::st
 //
 // CONSTRUCTOR
 //
-CLP::CLP(std::string name="",std::string version="",std::string copyright="",std::string url="",std::string usage=""){
+CLP::CLP(std::string name,std::string version,std::string copyright,std::string url,std::string usagestring){
 	
 	_name      = name;
 	_version   = version;
 	_copyright = copyright;
 	_url       = url;
-	_usage     = usage;
+	_usage     = usagestring;
 	
 }
 
