$NetBSD: patch-net_disk__cache_disk__format.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/disk_cache/disk_format.h.orig	2011-04-13 08:01:17.000000000 +0000
+++ net/disk_cache/disk_format.h
@@ -156,7 +156,7 @@ struct RankingsNode {
 };
 #pragma pack(pop)
 
-COMPILE_ASSERT(sizeof(RankingsNode) == 36, bad_RankingsNode);
+//COMPILE_ASSERT(sizeof(RankingsNode) == 36, bad_RankingsNode);
 
 const uint32 kBlockMagic = 0xC104CAC3;
 const int kBlockHeaderSize = 8192;  // Two pages: almost 64k entries
