$NetBSD$

--- sys/sys_local.cpp.orig	2019-02-02 17:51:38.000000000 +0000
+++ sys/sys_local.cpp
@@ -44,7 +44,7 @@ double idSysLocal::ClockTicksPerSecond( 
 	return Sys_ClockTicksPerSecond();
 }
 
-cpuid_t idSysLocal::GetProcessorId( void ) {
+id_cpuid_t idSysLocal::GetProcessorId( void ) {
 	return Sys_GetProcessorId();
 }
 
@@ -84,13 +84,11 @@ void idSysLocal::DLL_GetFileName( const 
 #ifdef _WIN32
     // e.g. gamex64.dll
     idStr::snPrintf(dllName, maxLength, "%s%s.dll", baseName, CPUSTRING);
-#elif defined( __linux__ )
-    // e.g. gamex64.so
-    idStr::snPrintf(dllName, maxLength, "%s%s.so", baseName, CPUSTRING);
 #elif defined( MACOS_X )
 	idStr::snPrintf( dllName, maxLength, "%s" ".dylib", baseName );
 #else
-#error OS define is required
+    // e.g. gamex64.so
+    idStr::snPrintf(dllName, maxLength, "%s%s.so", baseName, CPUSTRING);
 #endif
 }
 
