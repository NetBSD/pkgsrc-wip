$NetBSD$

--- lib/xray/xray_flags.h.orig	2018-08-21 21:25:41.000000000 +0000
+++ lib/xray/xray_flags.h
@@ -31,7 +31,8 @@ struct Flags {
 extern Flags xray_flags_dont_use_directly;
 extern void registerXRayFlags(FlagParser *P, Flags *F);
 const char *useCompilerDefinedFlags();
-inline Flags *flags() { return &xray_flags_dont_use_directly; }
+inline Flags *flags() {
+ return &xray_flags_dont_use_directly; }
 
 void initializeFlags();
 
