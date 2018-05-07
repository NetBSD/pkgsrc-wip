$NetBSD$

--- lib/asan/asan_mapping.h.orig	2018-02-01 23:46:05.000000000 +0000
+++ lib/asan/asan_mapping.h
@@ -122,6 +122,13 @@
 // || `[0x400000000000, 0x47ffffffffff]` || LowShadow  ||
 // || `[0x000000000000, 0x3fffffffffff]` || LowMem     ||
 //
+// Shadow mapping on NerBSD/i386 with SHADOW_OFFSET == 0x40000000:
+// || `[0x60000000, 0xfffff000]` || HighMem    ||
+// || `[0x4c000000, 0x5fffffff]` || HighShadow ||
+// || `[0x48000000, 0x4bffffff]` || ShadowGap  ||
+// || `[0x40000000, 0x47ffffff]` || LowShadow  ||
+// || `[0x00000000, 0x3fffffff]` || LowMem     ||
+//
 // Default Windows/i386 mapping:
 // (the exact location of HighShadow/HighMem may vary depending
 //  on WoW64, /LARGEADDRESSAWARE, etc).
@@ -152,6 +159,7 @@ static const u64 kPPC64_ShadowOffset64 =
 static const u64 kSystemZ_ShadowOffset64 = 1ULL << 52;
 static const u64 kFreeBSD_ShadowOffset32 = 1ULL << 30;  // 0x40000000
 static const u64 kFreeBSD_ShadowOffset64 = 1ULL << 46;  // 0x400000000000
+static const u64 kNetBSD_ShadowOffset32 = 1ULL << 30;  // 0x40000000
 static const u64 kNetBSD_ShadowOffset64 = 1ULL << 46;  // 0x400000000000
 static const u64 kWindowsShadowOffset32 = 3ULL << 28;  // 0x30000000
 
@@ -166,6 +174,8 @@ static const u64 kWindowsShadowOffset32 
 #    define SHADOW_OFFSET kMIPS32_ShadowOffset32
 #  elif SANITIZER_FREEBSD
 #    define SHADOW_OFFSET kFreeBSD_ShadowOffset32
+#  elif SANITIZER_NETBSD
+#    define SHADOW_OFFSET kNetBSD_ShadowOffset32
 #  elif SANITIZER_WINDOWS
 #    define SHADOW_OFFSET kWindowsShadowOffset32
 #  elif SANITIZER_IOS
