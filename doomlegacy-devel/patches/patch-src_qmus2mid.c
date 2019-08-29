$NetBSD$

Typecast signed result from LE_SWAP16 macro to unsigned where required.
Only relevant for big endian machines.
Proposed by upstream for test.

--- src/qmus2mid.c.orig	2019-08-21 09:16:55.000000000 +0000
+++ src/qmus2mid.c
@@ -113,17 +113,17 @@ void* S_CacheMusicLump(int lump)
     if (lump_read && memcmp(data, MUSHEADER, 4) == 0) {
         /* Header should be at beginning of opaque data pointer */
         MUSheader *mh = (MUSheader*)data;
-        mh->scoreLength = LE_SWAP16(mh->scoreLength);
-        mh->scoreStart = LE_SWAP16(mh->scoreStart);
-        mh->channels = LE_SWAP16(mh->channels);
-        mh->sec_channels = LE_SWAP16(mh->sec_channels);
-        mh->instrCnt = LE_SWAP16(mh->instrCnt);
+        mh->scoreLength = (uint16_t)( LE_SWAP16(mh->scoreLength) );
+        mh->scoreStart = (uint16_t)( LE_SWAP16(mh->scoreStart) );
+        mh->channels = (uint16_t)( LE_SWAP16(mh->channels) );
+        mh->sec_channels = (uint16_t)( LE_SWAP16(mh->sec_channels) );
+        mh->instrCnt = (uint16_t)( LE_SWAP16(mh->instrCnt) );
         /* Probably unnecessary if this is just padding */
-        mh->dummy = LE_SWAP16(mh->dummy);
+        mh->dummy = (uint16_t)( LE_SWAP16(mh->dummy) );
 
         uint16_t i;
         for (i = 0; i < mh->instrCnt; ++i) {
-            mh->instruments[i] = LE_SWAP16(mh->instruments[i]);
+            mh->instruments[i] = (uint16_t)( LE_SWAP16(mh->instruments[i]) );
         }
     }
 
