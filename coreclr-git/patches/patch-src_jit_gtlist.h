$NetBSD$

--- src/jit/gtlist.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/jit/gtlist.h
@@ -64,7 +64,7 @@ GTNODE(MEMORYBARRIER    , "memoryBarrier
 
 GTNODE(CAST             , "cast"          ,0,GTK_UNOP|GTK_EXOP) // conversion to another type
 GTNODE(CKFINITE         , "ckfinite"      ,0,GTK_UNOP)          // Check for NaN
-GTNODE(LCLHEAP          , "lclHeap"       ,0,GTK_UNOP)          // alloca()
+GTNODE(LCLHEAP          , "lclHeap"       ,0,GTK_UNOP)          // Alloca()
 GTNODE(JMP              , "jump"          ,0,GTK_LEAF)          // Jump to another function
 
 
