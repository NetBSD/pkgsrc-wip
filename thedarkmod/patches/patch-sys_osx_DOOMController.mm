$NetBSD$

--- sys/osx/DOOMController.mm.orig	2019-02-02 17:51:38.000000000 +0000
+++ sys/osx/DOOMController.mm
@@ -459,8 +459,8 @@ void Sys_Shutdown( void ) {
 Sys_GetProcessorId
 ===============
 */
-cpuid_t Sys_GetProcessorId( void ) {
-	cpuid_t cpuid = CPUID_GENERIC;
+id_cpuid_t Sys_GetProcessorId( void ) {
+	id_cpuid_t cpuid = CPUID_GENERIC;
 #if defined(__ppc__)
 	cpuid |= CPUID_ALTIVEC;
 #elif defined(__i386__)
