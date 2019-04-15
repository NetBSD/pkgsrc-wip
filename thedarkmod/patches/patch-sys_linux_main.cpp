$NetBSD$

--- sys/linux/main.cpp.orig	2019-02-02 17:51:37.000000000 +0000
+++ sys/linux/main.cpp
@@ -246,7 +246,7 @@ void Sys_Shutdown( void ) {
 Sys_GetProcessorId
 ===============
 */
-cpuid_t Sys_GetProcessorId( void ) {
+id_cpuid_t Sys_GetProcessorId( void ) {
 	return CPUID_GENERIC;
 }
 
