$NetBSD$

http://neosource.1emulation.com/forums/index.php?topic=1731.msg24254#msg24254

--- src/cpu/arm7_intf.cpp.orig	2017-07-13 03:39:54.000000000 +0000
+++ src/cpu/arm7_intf.cpp
@@ -391,6 +391,7 @@ void Arm7Init( INT32 nCPU ) // only one
 	
 	for (INT32 i = 0; i < 3; i++) {
 		membase[i] = (UINT8**)malloc(PAGE_COUNT * sizeof(UINT8*));
+		memset(membase[i], 0, PAGE_COUNT * sizeof(UINT8*));
 	}
 
 	CpuCheatRegister(nCPU, &Arm7CheatCpuConfig);
