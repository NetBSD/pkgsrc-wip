$NetBSD$

--- src/od-fs/mman.cpp.orig	2015-10-09 10:30:03.000000000 +0000
+++ src/od-fs/mman.cpp
@@ -50,12 +50,6 @@ static void GetSystemInfo(SYSTEM_INFO *s
 
 #define USE_MMAP
 
-#ifdef USE_MMAP
-#ifdef MACOSX
-#define MAP_ANONYMOUS MAP_ANON
-#endif
-#endif
-
 static void *VirtualAlloc(void *lpAddress, size_t dwSize, int flAllocationType,
 		int flProtect)
 {
@@ -97,7 +91,7 @@ static void *VirtualAlloc(void *lpAddres
 
 	if (flAllocationType & MEM_RESERVE) {
 #ifdef USE_MMAP
-		memory = mmap(lpAddress, dwSize, 0, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
+		memory = mmap(lpAddress, dwSize, 0, MAP_PRIVATE | MAP_ANON, -1, 0);
 		if (memory == (void *) -1) {
 			write_log("mmap failed errno %d\n", errno);
 			return NULL;
