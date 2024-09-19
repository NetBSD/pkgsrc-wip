$NetBSD$

--- src/edb.cpp.orig	2017-02-18 21:21:09.000000000 +0000
+++ src/edb.cpp
@@ -966,7 +966,7 @@ IRegion::pointer primary_data_region() {
 //------------------------------------------------------------------------------
 IRegion::pointer primary_code_region() {
 
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(Q_OS_NETBSD)
 	if(debugger_core) {
 		if(IProcess *process = debugger_core->process()) {
 			const address_t address = process->code_address();
