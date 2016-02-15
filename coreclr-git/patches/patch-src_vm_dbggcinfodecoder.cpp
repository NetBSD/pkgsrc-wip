$NetBSD$

--- src/vm/dbggcinfodecoder.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/vm/dbggcinfodecoder.cpp
@@ -309,7 +309,7 @@ bool GcInfoDecoder::EnumerateLiveSlots(
             {
                 m_IsInterruptible = true;
 
-                BYTE* callSiteLiveSet = (BYTE*) _alloca( ( numSlotMappings + 7 ) / 8 );
+                BYTE* callSiteLiveSet = (BYTE*) Alloca( ( numSlotMappings + 7 ) / 8 );
 
                 UINT32 i;
                 for( i=0; i<numSlotMappings/8; i++ )
@@ -323,7 +323,7 @@ bool GcInfoDecoder::EnumerateLiveSlots(
                 // Read slot mappings
                 //---------------------------------------------------------------------------
 
-                GcSlotDesc* slotMappings = (GcSlotDesc*) _alloca( numSlotMappings * sizeof( GcSlotDesc ) );
+                GcSlotDesc* slotMappings = (GcSlotDesc*) Alloca( numSlotMappings * sizeof( GcSlotDesc ) );
                 // Assert that we can read a GcSlotDesc with a single call to m_Reader.Read()
                 _ASSERTE( sizeof( GcSlotDesc ) <= sizeof ( size_t ) );
                 for( UINT32 i=0; i<numSlotMappings; i++ )
