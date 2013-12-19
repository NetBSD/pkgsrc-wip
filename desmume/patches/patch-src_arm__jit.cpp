$NetBSD: patch-src_arm__jit.cpp,v 1.1 2013/12/19 03:25:57 othyro Exp $

Set correct type for popcount().

--- src/arm_jit.cpp.orig	2013-11-28 00:37:17.000000000 +0000
+++ src/arm_jit.cpp
@@ -2067,7 +2067,8 @@ static int OP_SWPB(const u32 i) { return
 //-----------------------------------------------------------------------------
 //   LDMIA / LDMIB / LDMDA / LDMDB / STMIA / STMIB / STMDA / STMDB
 //-----------------------------------------------------------------------------
-static u32 popcount(u32 x)
+
+extern u32 popcount(u32 x)
 {
 	uint32_t pop = 0;
 	for(; x; x>>=1)
