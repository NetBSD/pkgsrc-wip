$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/7zArcIn.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/7zArcIn.c
@@ -1,5 +1,5 @@
 /* 7zArcIn.c -- 7z Input functions
-2021-02-09 : Igor Pavlov : Public domain */
+2023-09-07 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
@@ -10,10 +10,11 @@
 #include "7zCrc.h"
 #include "CpuArch.h"
 
-#define MY_ALLOC(T, p, size, alloc) { \
-  if ((p = (T *)ISzAlloc_Alloc(alloc, (size) * sizeof(T))) == NULL) return SZ_ERROR_MEM; }
+#define MY_ALLOC(T, p, size, alloc) \
+  { if ((p = (T *)ISzAlloc_Alloc(alloc, (size) * sizeof(T))) == NULL) return SZ_ERROR_MEM; }
 
-#define MY_ALLOC_ZE(T, p, size, alloc) { if ((size) == 0) p = NULL; else MY_ALLOC(T, p, size, alloc) }
+#define MY_ALLOC_ZE(T, p, size, alloc) \
+  { if ((size) == 0) p = NULL; else MY_ALLOC(T, p, size, alloc) }
 
 #define MY_ALLOC_AND_CPY(to, size, from, alloc) \
   { MY_ALLOC(Byte, to, size, alloc); memcpy(to, from, size); }
@@ -58,7 +59,7 @@ enum EIdEnum
 
 const Byte k7zSignature[k7zSignatureSize] = {'7', 'z', 0xBC, 0xAF, 0x27, 0x1C};
 
-#define SzBitUi32s_Init(p) { (p)->Defs = NULL; (p)->Vals = NULL; }
+#define SzBitUi32s_INIT(p) { (p)->Defs = NULL; (p)->Vals = NULL; }
 
 static SRes SzBitUi32s_Alloc(CSzBitUi32s *p, size_t num, ISzAllocPtr alloc)
 {
@@ -69,8 +70,8 @@ static SRes SzBitUi32s_Alloc(CSzBitUi32s
   }
   else
   {
-    MY_ALLOC(Byte, p->Defs, (num + 7) >> 3, alloc);
-    MY_ALLOC(UInt32, p->Vals, num, alloc);
+    MY_ALLOC(Byte, p->Defs, (num + 7) >> 3, alloc)
+    MY_ALLOC(UInt32, p->Vals, num, alloc)
   }
   return SZ_OK;
 }
@@ -81,7 +82,7 @@ static void SzBitUi32s_Free(CSzBitUi32s 
   ISzAlloc_Free(alloc, p->Vals); p->Vals = NULL;
 }
 
-#define SzBitUi64s_Init(p) { (p)->Defs = NULL; (p)->Vals = NULL; }
+#define SzBitUi64s_INIT(p) { (p)->Defs = NULL; (p)->Vals = NULL; }
 
 static void SzBitUi64s_Free(CSzBitUi64s *p, ISzAllocPtr alloc)
 {
@@ -96,7 +97,7 @@ static void SzAr_Init(CSzAr *p)
   p->NumFolders = 0;
   
   p->PackPositions = NULL;
-  SzBitUi32s_Init(&p->FolderCRCs);
+  SzBitUi32s_INIT(&p->FolderCRCs)
 
   p->FoCodersOffsets = NULL;
   p->FoStartPackStreamIndex = NULL;
@@ -142,11 +143,11 @@ void SzArEx_Init(CSzArEx *p)
   p->FileNameOffsets = NULL;
   p->FileNames = NULL;
   
-  SzBitUi32s_Init(&p->CRCs);
-  SzBitUi32s_Init(&p->Attribs);
-  // SzBitUi32s_Init(&p->Parents);
-  SzBitUi64s_Init(&p->MTime);
-  SzBitUi64s_Init(&p->CTime);
+  SzBitUi32s_INIT(&p->CRCs)
+  SzBitUi32s_INIT(&p->Attribs)
+  // SzBitUi32s_INIT(&p->Parents)
+  SzBitUi64s_INIT(&p->MTime)
+  SzBitUi64s_INIT(&p->CTime)
 }
 
 void SzArEx_Free(CSzArEx *p, ISzAllocPtr alloc)
@@ -180,11 +181,20 @@ static int TestSignatureCandidate(const 
   return 1;
 }
 
-#define SzData_Clear(p) { (p)->Data = NULL; (p)->Size = 0; }
+#define SzData_CLEAR(p) { (p)->Data = NULL; (p)->Size = 0; }
+
+#define SZ_READ_BYTE_SD_NOCHECK(_sd_, dest) \
+    (_sd_)->Size--; dest = *(_sd_)->Data++;
+
+#define SZ_READ_BYTE_SD(_sd_, dest) \
+    if ((_sd_)->Size == 0) return SZ_ERROR_ARCHIVE; \
+    SZ_READ_BYTE_SD_NOCHECK(_sd_, dest)
 
-#define SZ_READ_BYTE_SD(_sd_, dest) if ((_sd_)->Size == 0) return SZ_ERROR_ARCHIVE; (_sd_)->Size--; dest = *(_sd_)->Data++;
 #define SZ_READ_BYTE(dest) SZ_READ_BYTE_SD(sd, dest)
-#define SZ_READ_BYTE_2(dest) if (sd.Size == 0) return SZ_ERROR_ARCHIVE; sd.Size--; dest = *sd.Data++;
+
+#define SZ_READ_BYTE_2(dest) \
+    if (sd.Size == 0) return SZ_ERROR_ARCHIVE; \
+    sd.Size--; dest = *sd.Data++;
 
 #define SKIP_DATA(sd, size) { sd->Size -= (size_t)(size); sd->Data += (size_t)(size); }
 #define SKIP_DATA2(sd, size) { sd.Size -= (size_t)(size); sd.Data += (size_t)(size); }
@@ -192,25 +202,25 @@ static int TestSignatureCandidate(const 
 #define SZ_READ_32(dest) if (sd.Size < 4) return SZ_ERROR_ARCHIVE; \
    dest = GetUi32(sd.Data); SKIP_DATA2(sd, 4);
 
-static MY_NO_INLINE SRes ReadNumber(CSzData *sd, UInt64 *value)
+static Z7_NO_INLINE SRes ReadNumber(CSzData *sd, UInt64 *value)
 {
   Byte firstByte, mask;
   unsigned i;
   UInt32 v;
 
-  SZ_READ_BYTE(firstByte);
+  SZ_READ_BYTE(firstByte)
   if ((firstByte & 0x80) == 0)
   {
     *value = firstByte;
     return SZ_OK;
   }
-  SZ_READ_BYTE(v);
+  SZ_READ_BYTE(v)
   if ((firstByte & 0x40) == 0)
   {
     *value = (((UInt32)firstByte & 0x3F) << 8) | v;
     return SZ_OK;
   }
-  SZ_READ_BYTE(mask);
+  SZ_READ_BYTE(mask)
   *value = v | ((UInt32)mask << 8);
   mask = 0x20;
   for (i = 2; i < 8; i++)
@@ -218,11 +228,11 @@ static MY_NO_INLINE SRes ReadNumber(CSzD
     Byte b;
     if ((firstByte & mask) == 0)
     {
-      UInt64 highPart = (unsigned)firstByte & (unsigned)(mask - 1);
+      const UInt64 highPart = (unsigned)firstByte & (unsigned)(mask - 1);
       *value |= (highPart << (8 * i));
       return SZ_OK;
     }
-    SZ_READ_BYTE(b);
+    SZ_READ_BYTE(b)
     *value |= ((UInt64)b << (8 * i));
     mask >>= 1;
   }
@@ -230,7 +240,7 @@ static MY_NO_INLINE SRes ReadNumber(CSzD
 }
 
 
-static MY_NO_INLINE SRes SzReadNumber32(CSzData *sd, UInt32 *value)
+static Z7_NO_INLINE SRes SzReadNumber32(CSzData *sd, UInt32 *value)
 {
   Byte firstByte;
   UInt64 value64;
@@ -244,7 +254,7 @@ static MY_NO_INLINE SRes SzReadNumber32(
     sd->Size--;
     return SZ_OK;
   }
-  RINOK(ReadNumber(sd, &value64));
+  RINOK(ReadNumber(sd, &value64))
   if (value64 >= (UInt32)0x80000000 - 1)
     return SZ_ERROR_UNSUPPORTED;
   if (value64 >= ((UInt64)(1) << ((sizeof(size_t) - 1) * 8 + 4)))
@@ -258,10 +268,10 @@ static MY_NO_INLINE SRes SzReadNumber32(
 static SRes SkipData(CSzData *sd)
 {
   UInt64 size;
-  RINOK(ReadNumber(sd, &size));
+  RINOK(ReadNumber(sd, &size))
   if (size > sd->Size)
     return SZ_ERROR_ARCHIVE;
-  SKIP_DATA(sd, size);
+  SKIP_DATA(sd, size)
   return SZ_OK;
 }
 
@@ -270,28 +280,28 @@ static SRes WaitId(CSzData *sd, UInt32 i
   for (;;)
   {
     UInt64 type;
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
     if (type == id)
       return SZ_OK;
     if (type == k7zIdEnd)
       return SZ_ERROR_ARCHIVE;
-    RINOK(SkipData(sd));
+    RINOK(SkipData(sd))
   }
 }
 
 static SRes RememberBitVector(CSzData *sd, UInt32 numItems, const Byte **v)
 {
-  UInt32 numBytes = (numItems + 7) >> 3;
+  const UInt32 numBytes = (numItems + 7) >> 3;
   if (numBytes > sd->Size)
     return SZ_ERROR_ARCHIVE;
   *v = sd->Data;
-  SKIP_DATA(sd, numBytes);
+  SKIP_DATA(sd, numBytes)
   return SZ_OK;
 }
 
 static UInt32 CountDefinedBits(const Byte *bits, UInt32 numItems)
 {
-  Byte b = 0;
+  unsigned b = 0;
   unsigned m = 0;
   UInt32 sum = 0;
   for (; numItems != 0; numItems--)
@@ -302,53 +312,53 @@ static UInt32 CountDefinedBits(const Byt
       m = 8;
     }
     m--;
-    sum += ((b >> m) & 1);
+    sum += (UInt32)((b >> m) & 1);
   }
   return sum;
 }
 
-static MY_NO_INLINE SRes ReadBitVector(CSzData *sd, UInt32 numItems, Byte **v, ISzAllocPtr alloc)
+static Z7_NO_INLINE SRes ReadBitVector(CSzData *sd, UInt32 numItems, Byte **v, ISzAllocPtr alloc)
 {
   Byte allAreDefined;
   Byte *v2;
-  UInt32 numBytes = (numItems + 7) >> 3;
+  const UInt32 numBytes = (numItems + 7) >> 3;
   *v = NULL;
-  SZ_READ_BYTE(allAreDefined);
+  SZ_READ_BYTE(allAreDefined)
   if (numBytes == 0)
     return SZ_OK;
   if (allAreDefined == 0)
   {
     if (numBytes > sd->Size)
       return SZ_ERROR_ARCHIVE;
-    MY_ALLOC_AND_CPY(*v, numBytes, sd->Data, alloc);
-    SKIP_DATA(sd, numBytes);
+    MY_ALLOC_AND_CPY(*v, numBytes, sd->Data, alloc)
+    SKIP_DATA(sd, numBytes)
     return SZ_OK;
   }
-  MY_ALLOC(Byte, *v, numBytes, alloc);
+  MY_ALLOC(Byte, *v, numBytes, alloc)
   v2 = *v;
   memset(v2, 0xFF, (size_t)numBytes);
   {
-    unsigned numBits = (unsigned)numItems & 7;
+    const unsigned numBits = (unsigned)numItems & 7;
     if (numBits != 0)
       v2[(size_t)numBytes - 1] = (Byte)((((UInt32)1 << numBits) - 1) << (8 - numBits));
   }
   return SZ_OK;
 }
 
-static MY_NO_INLINE SRes ReadUi32s(CSzData *sd2, UInt32 numItems, CSzBitUi32s *crcs, ISzAllocPtr alloc)
+static Z7_NO_INLINE SRes ReadUi32s(CSzData *sd2, UInt32 numItems, CSzBitUi32s *crcs, ISzAllocPtr alloc)
 {
   UInt32 i;
   CSzData sd;
   UInt32 *vals;
   const Byte *defs;
-  MY_ALLOC_ZE(UInt32, crcs->Vals, numItems, alloc);
+  MY_ALLOC_ZE(UInt32, crcs->Vals, numItems, alloc)
   sd = *sd2;
   defs = crcs->Defs;
   vals = crcs->Vals;
   for (i = 0; i < numItems; i++)
     if (SzBitArray_Check(defs, i))
     {
-      SZ_READ_32(vals[i]);
+      SZ_READ_32(vals[i])
     }
     else
       vals[i] = 0;
@@ -359,7 +369,7 @@ static MY_NO_INLINE SRes ReadUi32s(CSzDa
 static SRes ReadBitUi32s(CSzData *sd, UInt32 numItems, CSzBitUi32s *crcs, ISzAllocPtr alloc)
 {
   SzBitUi32s_Free(crcs, alloc);
-  RINOK(ReadBitVector(sd, numItems, &crcs->Defs, alloc));
+  RINOK(ReadBitVector(sd, numItems, &crcs->Defs, alloc))
   return ReadUi32s(sd, numItems, crcs, alloc);
 }
 
@@ -367,36 +377,36 @@ static SRes SkipBitUi32s(CSzData *sd, UI
 {
   Byte allAreDefined;
   UInt32 numDefined = numItems;
-  SZ_READ_BYTE(allAreDefined);
+  SZ_READ_BYTE(allAreDefined)
   if (!allAreDefined)
   {
-    size_t numBytes = (numItems + 7) >> 3;
+    const size_t numBytes = (numItems + 7) >> 3;
     if (numBytes > sd->Size)
       return SZ_ERROR_ARCHIVE;
     numDefined = CountDefinedBits(sd->Data, numItems);
-    SKIP_DATA(sd, numBytes);
+    SKIP_DATA(sd, numBytes)
   }
   if (numDefined > (sd->Size >> 2))
     return SZ_ERROR_ARCHIVE;
-  SKIP_DATA(sd, (size_t)numDefined * 4);
+  SKIP_DATA(sd, (size_t)numDefined * 4)
   return SZ_OK;
 }
 
 static SRes ReadPackInfo(CSzAr *p, CSzData *sd, ISzAllocPtr alloc)
 {
-  RINOK(SzReadNumber32(sd, &p->NumPackStreams));
+  RINOK(SzReadNumber32(sd, &p->NumPackStreams))
 
-  RINOK(WaitId(sd, k7zIdSize));
-  MY_ALLOC(UInt64, p->PackPositions, (size_t)p->NumPackStreams + 1, alloc);
+  RINOK(WaitId(sd, k7zIdSize))
+  MY_ALLOC(UInt64, p->PackPositions, (size_t)p->NumPackStreams + 1, alloc)
   {
     UInt64 sum = 0;
     UInt32 i;
-    UInt32 numPackStreams = p->NumPackStreams;
+    const UInt32 numPackStreams = p->NumPackStreams;
     for (i = 0; i < numPackStreams; i++)
     {
       UInt64 packSize;
       p->PackPositions[i] = sum;
-      RINOK(ReadNumber(sd, &packSize));
+      RINOK(ReadNumber(sd, &packSize))
       sum += packSize;
       if (sum < packSize)
         return SZ_ERROR_ARCHIVE;
@@ -407,16 +417,16 @@ static SRes ReadPackInfo(CSzAr *p, CSzDa
   for (;;)
   {
     UInt64 type;
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
     if (type == k7zIdEnd)
       return SZ_OK;
     if (type == k7zIdCRC)
     {
       /* CRC of packed streams is unused now */
-      RINOK(SkipBitUi32s(sd, p->NumPackStreams));
+      RINOK(SkipBitUi32s(sd, p->NumPackStreams))
       continue;
     }
-    RINOK(SkipData(sd));
+    RINOK(SkipData(sd))
   }
 }
 
@@ -442,7 +452,7 @@ SRes SzGetNextFolderItem(CSzFolder *f, C
   f->NumPackStreams = 0;
   f->UnpackStream = 0;
   
-  RINOK(SzReadNumber32(sd, &numCoders));
+  RINOK(SzReadNumber32(sd, &numCoders))
   if (numCoders == 0 || numCoders > SZ_NUM_CODERS_IN_FOLDER_MAX)
     return SZ_ERROR_UNSUPPORTED;
   
@@ -453,7 +463,7 @@ SRes SzGetNextFolderItem(CSzFolder *f, C
     unsigned idSize, j;
     UInt64 id;
     
-    SZ_READ_BYTE(mainByte);
+    SZ_READ_BYTE(mainByte)
     if ((mainByte & 0xC0) != 0)
       return SZ_ERROR_UNSUPPORTED;
     
@@ -481,12 +491,12 @@ SRes SzGetNextFolderItem(CSzFolder *f, C
     {
       UInt32 numStreams;
       
-      RINOK(SzReadNumber32(sd, &numStreams));
+      RINOK(SzReadNumber32(sd, &numStreams))
       if (numStreams > k_NumCodersStreams_in_Folder_MAX)
         return SZ_ERROR_UNSUPPORTED;
       coder->NumStreams = (Byte)numStreams;
 
-      RINOK(SzReadNumber32(sd, &numStreams));
+      RINOK(SzReadNumber32(sd, &numStreams))
       if (numStreams != 1)
         return SZ_ERROR_UNSUPPORTED;
     }
@@ -499,7 +509,7 @@ SRes SzGetNextFolderItem(CSzFolder *f, C
     if ((mainByte & 0x20) != 0)
     {
       UInt32 propsSize = 0;
-      RINOK(SzReadNumber32(sd, &propsSize));
+      RINOK(SzReadNumber32(sd, &propsSize))
       if (propsSize > sd->Size)
         return SZ_ERROR_ARCHIVE;
       if (propsSize >= 0x80)
@@ -549,12 +559,12 @@ SRes SzGetNextFolderItem(CSzFolder *f, C
       {
         CSzBond *bp = f->Bonds + i;
         
-        RINOK(SzReadNumber32(sd, &bp->InIndex));
+        RINOK(SzReadNumber32(sd, &bp->InIndex))
         if (bp->InIndex >= numInStreams || streamUsed[bp->InIndex])
           return SZ_ERROR_ARCHIVE;
         streamUsed[bp->InIndex] = True;
         
-        RINOK(SzReadNumber32(sd, &bp->OutIndex));
+        RINOK(SzReadNumber32(sd, &bp->OutIndex))
         if (bp->OutIndex >= numCoders || coderUsed[bp->OutIndex])
           return SZ_ERROR_ARCHIVE;
         coderUsed[bp->OutIndex] = True;
@@ -584,7 +594,7 @@ SRes SzGetNextFolderItem(CSzFolder *f, C
       for (i = 0; i < numPackStreams; i++)
       {
         UInt32 index;
-        RINOK(SzReadNumber32(sd, &index));
+        RINOK(SzReadNumber32(sd, &index))
         if (index >= numInStreams || streamUsed[index])
           return SZ_ERROR_ARCHIVE;
         streamUsed[index] = True;
@@ -598,7 +608,7 @@ SRes SzGetNextFolderItem(CSzFolder *f, C
 }
 
 
-static MY_NO_INLINE SRes SkipNumbers(CSzData *sd2, UInt32 num)
+static Z7_NO_INLINE SRes SkipNumbers(CSzData *sd2, UInt32 num)
 {
   CSzData sd;
   sd = *sd2;
@@ -606,7 +616,7 @@ static MY_NO_INLINE SRes SkipNumbers(CSz
   {
     Byte firstByte, mask;
     unsigned i;
-    SZ_READ_BYTE_2(firstByte);
+    SZ_READ_BYTE_2(firstByte)
     if ((firstByte & 0x80) == 0)
       continue;
     if ((firstByte & 0x40) == 0)
@@ -622,7 +632,7 @@ static MY_NO_INLINE SRes SkipNumbers(CSz
       mask >>= 1;
     if (i > sd.Size)
       return SZ_ERROR_ARCHIVE;
-    SKIP_DATA2(sd, i);
+    SKIP_DATA2(sd, i)
   }
   *sd2 = sd;
   return SZ_OK;
@@ -645,30 +655,30 @@ static SRes ReadUnpackInfo(CSzAr *p,
   const Byte *startBufPtr;
   Byte external;
   
-  RINOK(WaitId(sd2, k7zIdFolder));
+  RINOK(WaitId(sd2, k7zIdFolder))
   
-  RINOK(SzReadNumber32(sd2, &numFolders));
+  RINOK(SzReadNumber32(sd2, &numFolders))
   if (numFolders > numFoldersMax)
     return SZ_ERROR_UNSUPPORTED;
   p->NumFolders = numFolders;
 
-  SZ_READ_BYTE_SD(sd2, external);
+  SZ_READ_BYTE_SD(sd2, external)
   if (external == 0)
     sd = *sd2;
   else
   {
     UInt32 index;
-    RINOK(SzReadNumber32(sd2, &index));
+    RINOK(SzReadNumber32(sd2, &index))
     if (index >= numTempBufs)
       return SZ_ERROR_ARCHIVE;
     sd.Data = tempBufs[index].data;
     sd.Size = tempBufs[index].size;
   }
   
-  MY_ALLOC(size_t, p->FoCodersOffsets, (size_t)numFolders + 1, alloc);
-  MY_ALLOC(UInt32, p->FoStartPackStreamIndex, (size_t)numFolders + 1, alloc);
-  MY_ALLOC(UInt32, p->FoToCoderUnpackSizes, (size_t)numFolders + 1, alloc);
-  MY_ALLOC_ZE(Byte, p->FoToMainUnpackSizeIndex, (size_t)numFolders, alloc);
+  MY_ALLOC(size_t, p->FoCodersOffsets, (size_t)numFolders + 1, alloc)
+  MY_ALLOC(UInt32, p->FoStartPackStreamIndex, (size_t)numFolders + 1, alloc)
+  MY_ALLOC(UInt32, p->FoToCoderUnpackSizes, (size_t)numFolders + 1, alloc)
+  MY_ALLOC_ZE(Byte, p->FoToMainUnpackSizeIndex, (size_t)numFolders, alloc)
   
   startBufPtr = sd.Data;
   
@@ -681,7 +691,7 @@ static SRes ReadUnpackInfo(CSzAr *p,
     
     p->FoCodersOffsets[fo] = (size_t)(sd.Data - startBufPtr);
     
-    RINOK(SzReadNumber32(&sd, &numCoders));
+    RINOK(SzReadNumber32(&sd, &numCoders))
     if (numCoders == 0 || numCoders > k_Scan_NumCoders_MAX)
       return SZ_ERROR_UNSUPPORTED;
     
@@ -691,7 +701,7 @@ static SRes ReadUnpackInfo(CSzAr *p,
       unsigned idSize;
       UInt32 coderInStreams;
       
-      SZ_READ_BYTE_2(mainByte);
+      SZ_READ_BYTE_2(mainByte)
       if ((mainByte & 0xC0) != 0)
         return SZ_ERROR_UNSUPPORTED;
       idSize = (mainByte & 0xF);
@@ -699,15 +709,15 @@ static SRes ReadUnpackInfo(CSzAr *p,
         return SZ_ERROR_UNSUPPORTED;
       if (idSize > sd.Size)
         return SZ_ERROR_ARCHIVE;
-      SKIP_DATA2(sd, idSize);
+      SKIP_DATA2(sd, idSize)
       
       coderInStreams = 1;
       
       if ((mainByte & 0x10) != 0)
       {
         UInt32 coderOutStreams;
-        RINOK(SzReadNumber32(&sd, &coderInStreams));
-        RINOK(SzReadNumber32(&sd, &coderOutStreams));
+        RINOK(SzReadNumber32(&sd, &coderInStreams))
+        RINOK(SzReadNumber32(&sd, &coderOutStreams))
         if (coderInStreams > k_Scan_NumCodersStreams_in_Folder_MAX || coderOutStreams != 1)
           return SZ_ERROR_UNSUPPORTED;
       }
@@ -717,10 +727,10 @@ static SRes ReadUnpackInfo(CSzAr *p,
       if ((mainByte & 0x20) != 0)
       {
         UInt32 propsSize;
-        RINOK(SzReadNumber32(&sd, &propsSize));
+        RINOK(SzReadNumber32(&sd, &propsSize))
         if (propsSize > sd.Size)
           return SZ_ERROR_ARCHIVE;
-        SKIP_DATA2(sd, propsSize);
+        SKIP_DATA2(sd, propsSize)
       }
     }
     
@@ -734,7 +744,7 @@ static SRes ReadUnpackInfo(CSzAr *p,
         Byte coderUsed[k_Scan_NumCoders_MAX];
     
         UInt32 i;
-        UInt32 numBonds = numCoders - 1;
+        const UInt32 numBonds = numCoders - 1;
         if (numInStreams < numBonds)
           return SZ_ERROR_ARCHIVE;
         
@@ -750,12 +760,12 @@ static SRes ReadUnpackInfo(CSzAr *p,
         {
           UInt32 index;
           
-          RINOK(SzReadNumber32(&sd, &index));
+          RINOK(SzReadNumber32(&sd, &index))
           if (index >= numInStreams || streamUsed[index])
             return SZ_ERROR_ARCHIVE;
           streamUsed[index] = True;
           
-          RINOK(SzReadNumber32(&sd, &index));
+          RINOK(SzReadNumber32(&sd, &index))
           if (index >= numCoders || coderUsed[index])
             return SZ_ERROR_ARCHIVE;
           coderUsed[index] = True;
@@ -767,7 +777,7 @@ static SRes ReadUnpackInfo(CSzAr *p,
           for (i = 0; i < numPackStreams; i++)
           {
             UInt32 index;
-            RINOK(SzReadNumber32(&sd, &index));
+            RINOK(SzReadNumber32(&sd, &index))
             if (index >= numInStreams || streamUsed[index])
               return SZ_ERROR_ARCHIVE;
             streamUsed[index] = True;
@@ -802,7 +812,7 @@ static SRes ReadUnpackInfo(CSzAr *p,
     const size_t dataSize = (size_t)(sd.Data - startBufPtr);
     p->FoStartPackStreamIndex[fo] = packStreamIndex;
     p->FoCodersOffsets[fo] = dataSize;
-    MY_ALLOC_ZE_AND_CPY(p->CodersData, dataSize, startBufPtr, alloc);
+    MY_ALLOC_ZE_AND_CPY(p->CodersData, dataSize, startBufPtr, alloc)
   }
   
   if (external != 0)
@@ -812,21 +822,21 @@ static SRes ReadUnpackInfo(CSzAr *p,
     sd = *sd2;
   }
   
-  RINOK(WaitId(&sd, k7zIdCodersUnpackSize));
+  RINOK(WaitId(&sd, k7zIdCodersUnpackSize))
   
-  MY_ALLOC_ZE(UInt64, p->CoderUnpackSizes, (size_t)numCodersOutStreams, alloc);
+  MY_ALLOC_ZE(UInt64, p->CoderUnpackSizes, (size_t)numCodersOutStreams, alloc)
   {
     UInt32 i;
     for (i = 0; i < numCodersOutStreams; i++)
     {
-      RINOK(ReadNumber(&sd, p->CoderUnpackSizes + i));
+      RINOK(ReadNumber(&sd, p->CoderUnpackSizes + i))
     }
   }
 
   for (;;)
   {
     UInt64 type;
-    RINOK(ReadID(&sd, &type));
+    RINOK(ReadID(&sd, &type))
     if (type == k7zIdEnd)
     {
       *sd2 = sd;
@@ -834,10 +844,10 @@ static SRes ReadUnpackInfo(CSzAr *p,
     }
     if (type == k7zIdCRC)
     {
-      RINOK(ReadBitUi32s(&sd, numFolders, &p->FolderCRCs, alloc));
+      RINOK(ReadBitUi32s(&sd, numFolders, &p->FolderCRCs, alloc))
       continue;
     }
-    RINOK(SkipData(&sd));
+    RINOK(SkipData(&sd))
   }
 }
 
@@ -862,13 +872,13 @@ static SRes ReadSubStreamsInfo(CSzAr *p,
 {
   UInt64 type = 0;
   UInt32 numSubDigests = 0;
-  UInt32 numFolders = p->NumFolders;
+  const UInt32 numFolders = p->NumFolders;
   UInt32 numUnpackStreams = numFolders;
   UInt32 numUnpackSizesInData = 0;
 
   for (;;)
   {
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
     if (type == k7zIdNumUnpackStream)
     {
       UInt32 i;
@@ -878,7 +888,7 @@ static SRes ReadSubStreamsInfo(CSzAr *p,
       for (i = 0; i < numFolders; i++)
       {
         UInt32 numStreams;
-        RINOK(SzReadNumber32(sd, &numStreams));
+        RINOK(SzReadNumber32(sd, &numStreams))
         if (numUnpackStreams > numUnpackStreams + numStreams)
           return SZ_ERROR_UNSUPPORTED;
         numUnpackStreams += numStreams;
@@ -892,7 +902,7 @@ static SRes ReadSubStreamsInfo(CSzAr *p,
     }
     if (type == k7zIdCRC || type == k7zIdSize || type == k7zIdEnd)
       break;
-    RINOK(SkipData(sd));
+    RINOK(SkipData(sd))
   }
 
   if (!ssi->sdNumSubStreams.Data)
@@ -908,9 +918,9 @@ static SRes ReadSubStreamsInfo(CSzAr *p,
   if (type == k7zIdSize)
   {
     ssi->sdSizes.Data = sd->Data;
-    RINOK(SkipNumbers(sd, numUnpackSizesInData));
+    RINOK(SkipNumbers(sd, numUnpackSizesInData))
     ssi->sdSizes.Size = (size_t)(sd->Data - ssi->sdSizes.Data);
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
   }
 
   for (;;)
@@ -920,14 +930,14 @@ static SRes ReadSubStreamsInfo(CSzAr *p,
     if (type == k7zIdCRC)
     {
       ssi->sdCRCs.Data = sd->Data;
-      RINOK(SkipBitUi32s(sd, numSubDigests));
+      RINOK(SkipBitUi32s(sd, numSubDigests))
       ssi->sdCRCs.Size = (size_t)(sd->Data - ssi->sdCRCs.Data);
     }
     else
     {
-      RINOK(SkipData(sd));
+      RINOK(SkipData(sd))
     }
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
   }
 }
 
@@ -940,31 +950,31 @@ static SRes SzReadStreamsInfo(CSzAr *p,
 {
   UInt64 type;
 
-  SzData_Clear(&ssi->sdSizes);
-  SzData_Clear(&ssi->sdCRCs);
-  SzData_Clear(&ssi->sdNumSubStreams);
+  SzData_CLEAR(&ssi->sdSizes)
+  SzData_CLEAR(&ssi->sdCRCs)
+  SzData_CLEAR(&ssi->sdNumSubStreams)
 
   *dataOffset = 0;
-  RINOK(ReadID(sd, &type));
+  RINOK(ReadID(sd, &type))
   if (type == k7zIdPackInfo)
   {
-    RINOK(ReadNumber(sd, dataOffset));
+    RINOK(ReadNumber(sd, dataOffset))
     if (*dataOffset > p->RangeLimit)
       return SZ_ERROR_ARCHIVE;
-    RINOK(ReadPackInfo(p, sd, alloc));
+    RINOK(ReadPackInfo(p, sd, alloc))
     if (p->PackPositions[p->NumPackStreams] > p->RangeLimit - *dataOffset)
       return SZ_ERROR_ARCHIVE;
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
   }
   if (type == k7zIdUnpackInfo)
   {
-    RINOK(ReadUnpackInfo(p, sd, numFoldersMax, tempBufs, numTempBufs, alloc));
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadUnpackInfo(p, sd, numFoldersMax, tempBufs, numTempBufs, alloc))
+    RINOK(ReadID(sd, &type))
   }
   if (type == k7zIdSubStreamsInfo)
   {
-    RINOK(ReadSubStreamsInfo(p, sd, ssi));
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadSubStreamsInfo(p, sd, ssi))
+    RINOK(ReadID(sd, &type))
   }
   else
   {
@@ -976,7 +986,7 @@ static SRes SzReadStreamsInfo(CSzAr *p,
 }
 
 static SRes SzReadAndDecodePackedStreams(
-    ILookInStream *inStream,
+    ILookInStreamPtr inStream,
     CSzData *sd,
     CBuf *tempBufs,
     UInt32 numFoldersMax,
@@ -988,7 +998,7 @@ static SRes SzReadAndDecodePackedStreams
   UInt32 fo;
   CSubStreamInfo ssi;
 
-  RINOK(SzReadStreamsInfo(p, sd, numFoldersMax, NULL, 0, &dataStartPos, &ssi, allocTemp));
+  RINOK(SzReadStreamsInfo(p, sd, numFoldersMax, NULL, 0, &dataStartPos, &ssi, allocTemp))
   
   dataStartPos += baseOffset;
   if (p->NumFolders == 0)
@@ -1000,7 +1010,7 @@ static SRes SzReadAndDecodePackedStreams
   for (fo = 0; fo < p->NumFolders; fo++)
   {
     CBuf *tempBuf = tempBufs + fo;
-    UInt64 unpackSize = SzAr_GetFolderUnpackSize(p, fo);
+    const UInt64 unpackSize = SzAr_GetFolderUnpackSize(p, fo);
     if ((size_t)unpackSize != unpackSize)
       return SZ_ERROR_MEM;
     if (!Buf_Create(tempBuf, (size_t)unpackSize, allocTemp))
@@ -1010,8 +1020,8 @@ static SRes SzReadAndDecodePackedStreams
   for (fo = 0; fo < p->NumFolders; fo++)
   {
     const CBuf *tempBuf = tempBufs + fo;
-    RINOK(LookInStream_SeekTo(inStream, dataStartPos));
-    RINOK(SzAr_DecodeFolder(p, fo, inStream, dataStartPos, tempBuf->data, tempBuf->size, allocTemp));
+    RINOK(LookInStream_SeekTo(inStream, dataStartPos))
+    RINOK(SzAr_DecodeFolder(p, fo, inStream, dataStartPos, tempBuf->data, tempBuf->size, allocTemp))
   }
   
   return SZ_OK;
@@ -1046,7 +1056,7 @@ static SRes SzReadFileNames(const Byte *
   return (pos == size) ? SZ_OK : SZ_ERROR_ARCHIVE;
 }
 
-static MY_NO_INLINE SRes ReadTime(CSzBitUi64s *p, UInt32 num,
+static Z7_NO_INLINE SRes ReadTime(CSzBitUi64s *p, UInt32 num,
     CSzData *sd2,
     const CBuf *tempBufs, UInt32 numTempBufs,
     ISzAllocPtr alloc)
@@ -1057,22 +1067,22 @@ static MY_NO_INLINE SRes ReadTime(CSzBit
   Byte *defs;
   Byte external;
   
-  RINOK(ReadBitVector(sd2, num, &p->Defs, alloc));
+  RINOK(ReadBitVector(sd2, num, &p->Defs, alloc))
   
-  SZ_READ_BYTE_SD(sd2, external);
+  SZ_READ_BYTE_SD(sd2, external)
   if (external == 0)
     sd = *sd2;
   else
   {
     UInt32 index;
-    RINOK(SzReadNumber32(sd2, &index));
+    RINOK(SzReadNumber32(sd2, &index))
     if (index >= numTempBufs)
       return SZ_ERROR_ARCHIVE;
     sd.Data = tempBufs[index].data;
     sd.Size = tempBufs[index].size;
   }
   
-  MY_ALLOC_ZE(CNtfsFileTime, p->Vals, num, alloc);
+  MY_ALLOC_ZE(CNtfsFileTime, p->Vals, num, alloc)
   vals = p->Vals;
   defs = p->Defs;
   for (i = 0; i < num; i++)
@@ -1082,7 +1092,7 @@ static MY_NO_INLINE SRes ReadTime(CSzBit
         return SZ_ERROR_ARCHIVE;
       vals[i].Low = GetUi32(sd.Data);
       vals[i].High = GetUi32(sd.Data + 4);
-      SKIP_DATA2(sd, 8);
+      SKIP_DATA2(sd, 8)
     }
     else
       vals[i].High = vals[i].Low = 0;
@@ -1100,7 +1110,7 @@ static MY_NO_INLINE SRes ReadTime(CSzBit
 static SRes SzReadHeader2(
     CSzArEx *p,   /* allocMain */
     CSzData *sd,
-    ILookInStream *inStream,
+    ILookInStreamPtr inStream,
     CBuf *tempBufs, UInt32 *numTempBufs,
     ISzAllocPtr allocMain,
     ISzAllocPtr allocTemp
@@ -1111,26 +1121,26 @@ static SRes SzReadHeader2(
 {
   UInt64 type;
   
-  SzData_Clear(&ssi.sdSizes);
-  SzData_Clear(&ssi.sdCRCs);
-  SzData_Clear(&ssi.sdNumSubStreams);
+  SzData_CLEAR(&ssi.sdSizes)
+  SzData_CLEAR(&ssi.sdCRCs)
+  SzData_CLEAR(&ssi.sdNumSubStreams)
 
   ssi.NumSubDigests = 0;
   ssi.NumTotalSubStreams = 0;
 
-  RINOK(ReadID(sd, &type));
+  RINOK(ReadID(sd, &type))
 
   if (type == k7zIdArchiveProperties)
   {
     for (;;)
     {
       UInt64 type2;
-      RINOK(ReadID(sd, &type2));
+      RINOK(ReadID(sd, &type2))
       if (type2 == k7zIdEnd)
         break;
-      RINOK(SkipData(sd));
+      RINOK(SkipData(sd))
     }
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
   }
 
   if (type == k7zIdAdditionalStreamsInfo)
@@ -1148,15 +1158,15 @@ static SRes SzReadHeader2(
     
     if (res != SZ_OK)
       return res;
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
   }
 
   if (type == k7zIdMainStreamsInfo)
   {
     RINOK(SzReadStreamsInfo(&p->db, sd, (UInt32)1 << 30, tempBufs, *numTempBufs,
-        &p->dataPos, &ssi, allocMain));
+        &p->dataPos, &ssi, allocMain))
     p->dataPos += p->startPosAfterHeader;
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
   }
 
   if (type == k7zIdEnd)
@@ -1174,23 +1184,23 @@ static SRes SzReadHeader2(
   const Byte *emptyStreams = NULL;
   const Byte *emptyFiles = NULL;
   
-  RINOK(SzReadNumber32(sd, &numFiles));
+  RINOK(SzReadNumber32(sd, &numFiles))
   p->NumFiles = numFiles;
 
   for (;;)
   {
     UInt64 type;
     UInt64 size;
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
     if (type == k7zIdEnd)
       break;
-    RINOK(ReadNumber(sd, &size));
+    RINOK(ReadNumber(sd, &size))
     if (size > sd->Size)
       return SZ_ERROR_ARCHIVE;
     
     if (type >= ((UInt32)1 << 8))
     {
-      SKIP_DATA(sd, size);
+      SKIP_DATA(sd, size)
     }
     else switch ((unsigned)type)
     {
@@ -1200,7 +1210,7 @@ static SRes SzReadHeader2(
         const Byte *namesData;
         Byte external;
 
-        SZ_READ_BYTE(external);
+        SZ_READ_BYTE(external)
         if (external == 0)
         {
           namesSize = (size_t)size - 1;
@@ -1209,7 +1219,7 @@ static SRes SzReadHeader2(
         else
         {
           UInt32 index;
-          RINOK(SzReadNumber32(sd, &index));
+          RINOK(SzReadNumber32(sd, &index))
           if (index >= *numTempBufs)
             return SZ_ERROR_ARCHIVE;
           namesData = (tempBufs)[index].data;
@@ -1218,25 +1228,25 @@ static SRes SzReadHeader2(
 
         if ((namesSize & 1) != 0)
           return SZ_ERROR_ARCHIVE;
-        MY_ALLOC(size_t, p->FileNameOffsets, numFiles + 1, allocMain);
-        MY_ALLOC_ZE_AND_CPY(p->FileNames, namesSize, namesData, allocMain);
+        MY_ALLOC(size_t, p->FileNameOffsets, numFiles + 1, allocMain)
+        MY_ALLOC_ZE_AND_CPY(p->FileNames, namesSize, namesData, allocMain)
         RINOK(SzReadFileNames(p->FileNames, namesSize, numFiles, p->FileNameOffsets))
         if (external == 0)
         {
-          SKIP_DATA(sd, namesSize);
+          SKIP_DATA(sd, namesSize)
         }
         break;
       }
       case k7zIdEmptyStream:
       {
-        RINOK(RememberBitVector(sd, numFiles, &emptyStreams));
+        RINOK(RememberBitVector(sd, numFiles, &emptyStreams))
         numEmptyStreams = CountDefinedBits(emptyStreams, numFiles);
         emptyFiles = NULL;
         break;
       }
       case k7zIdEmptyFile:
       {
-        RINOK(RememberBitVector(sd, numEmptyStreams, &emptyFiles));
+        RINOK(RememberBitVector(sd, numEmptyStreams, &emptyFiles))
         break;
       }
       case k7zIdWinAttrib:
@@ -1245,22 +1255,22 @@ static SRes SzReadHeader2(
         CSzData sdSwitch;
         CSzData *sdPtr;
         SzBitUi32s_Free(&p->Attribs, allocMain);
-        RINOK(ReadBitVector(sd, numFiles, &p->Attribs.Defs, allocMain));
+        RINOK(ReadBitVector(sd, numFiles, &p->Attribs.Defs, allocMain))
 
-        SZ_READ_BYTE(external);
+        SZ_READ_BYTE(external)
         if (external == 0)
           sdPtr = sd;
         else
         {
           UInt32 index;
-          RINOK(SzReadNumber32(sd, &index));
+          RINOK(SzReadNumber32(sd, &index))
           if (index >= *numTempBufs)
             return SZ_ERROR_ARCHIVE;
           sdSwitch.Data = (tempBufs)[index].data;
           sdSwitch.Size = (tempBufs)[index].size;
           sdPtr = &sdSwitch;
         }
-        RINOK(ReadUi32s(sdPtr, numFiles, &p->Attribs, allocMain));
+        RINOK(ReadUi32s(sdPtr, numFiles, &p->Attribs, allocMain))
         break;
       }
       /*
@@ -1273,11 +1283,11 @@ static SRes SzReadHeader2(
         break;
       }
       */
-      case k7zIdMTime: RINOK(ReadTime(&p->MTime, numFiles, sd, tempBufs, *numTempBufs, allocMain)); break;
-      case k7zIdCTime: RINOK(ReadTime(&p->CTime, numFiles, sd, tempBufs, *numTempBufs, allocMain)); break;
+      case k7zIdMTime: RINOK(ReadTime(&p->MTime, numFiles, sd, tempBufs, *numTempBufs, allocMain)) break;
+      case k7zIdCTime: RINOK(ReadTime(&p->CTime, numFiles, sd, tempBufs, *numTempBufs, allocMain)) break;
       default:
       {
-        SKIP_DATA(sd, size);
+        SKIP_DATA(sd, size)
       }
     }
   }
@@ -1288,10 +1298,10 @@ static SRes SzReadHeader2(
   for (;;)
   {
     UInt64 type;
-    RINOK(ReadID(sd, &type));
+    RINOK(ReadID(sd, &type))
     if (type == k7zIdEnd)
       break;
-    RINOK(SkipData(sd));
+    RINOK(SkipData(sd))
   }
 
   {
@@ -1303,40 +1313,37 @@ static SRes SzReadHeader2(
     UInt64 unpackPos = 0;
     const Byte *digestsDefs = NULL;
     const Byte *digestsVals = NULL;
-    UInt32 digestsValsIndex = 0;
-    UInt32 digestIndex;
-    Byte allDigestsDefined = 0;
+    UInt32 digestIndex = 0;
     Byte isDirMask = 0;
     Byte crcMask = 0;
     Byte mask = 0x80;
     
-    MY_ALLOC(UInt32, p->FolderToFile, p->db.NumFolders + 1, allocMain);
-    MY_ALLOC_ZE(UInt32, p->FileToFolder, p->NumFiles, allocMain);
-    MY_ALLOC(UInt64, p->UnpackPositions, p->NumFiles + 1, allocMain);
-    MY_ALLOC_ZE(Byte, p->IsDirs, (p->NumFiles + 7) >> 3, allocMain);
+    MY_ALLOC(UInt32, p->FolderToFile, p->db.NumFolders + 1, allocMain)
+    MY_ALLOC_ZE(UInt32, p->FileToFolder, p->NumFiles, allocMain)
+    MY_ALLOC(UInt64, p->UnpackPositions, p->NumFiles + 1, allocMain)
+    MY_ALLOC_ZE(Byte, p->IsDirs, (p->NumFiles + 7) >> 3, allocMain)
 
-    RINOK(SzBitUi32s_Alloc(&p->CRCs, p->NumFiles, allocMain));
+    RINOK(SzBitUi32s_Alloc(&p->CRCs, p->NumFiles, allocMain))
 
     if (ssi.sdCRCs.Size != 0)
     {
-      SZ_READ_BYTE_SD(&ssi.sdCRCs, allDigestsDefined);
+      Byte allDigestsDefined = 0;
+      SZ_READ_BYTE_SD_NOCHECK(&ssi.sdCRCs, allDigestsDefined)
       if (allDigestsDefined)
         digestsVals = ssi.sdCRCs.Data;
       else
       {
-        size_t numBytes = (ssi.NumSubDigests + 7) >> 3;
+        const size_t numBytes = (ssi.NumSubDigests + 7) >> 3;
         digestsDefs = ssi.sdCRCs.Data;
         digestsVals = digestsDefs + numBytes;
       }
     }
 
-    digestIndex = 0;
-    
     for (i = 0; i < numFiles; i++, mask >>= 1)
     {
       if (mask == 0)
       {
-        UInt32 byteIndex = (i - 1) >> 3;
+        const UInt32 byteIndex = (i - 1) >> 3;
         p->IsDirs[byteIndex] = isDirMask;
         p->CRCs.Defs[byteIndex] = crcMask;
         isDirMask = 0;
@@ -1374,18 +1381,17 @@ static SRes SzReadHeader2(
           numSubStreams = 1;
           if (ssi.sdNumSubStreams.Data)
           {
-            RINOK(SzReadNumber32(&ssi.sdNumSubStreams, &numSubStreams));
+            RINOK(SzReadNumber32(&ssi.sdNumSubStreams, &numSubStreams))
           }
           remSubStreams = numSubStreams;
           if (numSubStreams != 0)
             break;
           {
-            UInt64 folderUnpackSize = SzAr_GetFolderUnpackSize(&p->db, folderIndex);
+            const UInt64 folderUnpackSize = SzAr_GetFolderUnpackSize(&p->db, folderIndex);
             unpackPos += folderUnpackSize;
             if (unpackPos < folderUnpackSize)
               return SZ_ERROR_ARCHIVE;
           }
-
           folderIndex++;
         }
       }
@@ -1397,47 +1403,44 @@ static SRes SzReadHeader2(
       
       if (--remSubStreams == 0)
       {
-        UInt64 folderUnpackSize = SzAr_GetFolderUnpackSize(&p->db, folderIndex);
-        UInt64 startFolderUnpackPos = p->UnpackPositions[p->FolderToFile[folderIndex]];
+        const UInt64 folderUnpackSize = SzAr_GetFolderUnpackSize(&p->db, folderIndex);
+        const UInt64 startFolderUnpackPos = p->UnpackPositions[p->FolderToFile[folderIndex]];
         if (folderUnpackSize < unpackPos - startFolderUnpackPos)
           return SZ_ERROR_ARCHIVE;
         unpackPos = startFolderUnpackPos + folderUnpackSize;
         if (unpackPos < folderUnpackSize)
           return SZ_ERROR_ARCHIVE;
 
-        if (numSubStreams == 1 && SzBitWithVals_Check(&p->db.FolderCRCs, i))
+        if (numSubStreams == 1 && SzBitWithVals_Check(&p->db.FolderCRCs, folderIndex))
         {
           p->CRCs.Vals[i] = p->db.FolderCRCs.Vals[folderIndex];
           crcMask |= mask;
         }
-        else if (allDigestsDefined || (digestsDefs && SzBitArray_Check(digestsDefs, digestIndex)))
-        {
-          p->CRCs.Vals[i] = GetUi32(digestsVals + (size_t)digestsValsIndex * 4);
-          digestsValsIndex++;
-          crcMask |= mask;
-        }
-        
         folderIndex++;
       }
       else
       {
         UInt64 v;
-        RINOK(ReadNumber(&ssi.sdSizes, &v));
+        RINOK(ReadNumber(&ssi.sdSizes, &v))
         unpackPos += v;
         if (unpackPos < v)
           return SZ_ERROR_ARCHIVE;
-        if (allDigestsDefined || (digestsDefs && SzBitArray_Check(digestsDefs, digestIndex)))
+      }
+      if ((crcMask & mask) == 0 && digestsVals)
+      {
+        if (!digestsDefs || SzBitArray_Check(digestsDefs, digestIndex))
         {
-          p->CRCs.Vals[i] = GetUi32(digestsVals + (size_t)digestsValsIndex * 4);
-          digestsValsIndex++;
+          p->CRCs.Vals[i] = GetUi32(digestsVals);
+          digestsVals += 4;
           crcMask |= mask;
         }
+        digestIndex++;
       }
     }
 
     if (mask != 0x80)
     {
-      UInt32 byteIndex = (i - 1) >> 3;
+      const UInt32 byteIndex = (i - 1) >> 3;
       p->IsDirs[byteIndex] = isDirMask;
       p->CRCs.Defs[byteIndex] = crcMask;
     }
@@ -1454,7 +1457,7 @@ static SRes SzReadHeader2(
         break;
       if (!ssi.sdNumSubStreams.Data)
         return SZ_ERROR_ARCHIVE;
-      RINOK(SzReadNumber32(&ssi.sdNumSubStreams, &numSubStreams));
+      RINOK(SzReadNumber32(&ssi.sdNumSubStreams, &numSubStreams))
       if (numSubStreams != 0)
         return SZ_ERROR_ARCHIVE;
       /*
@@ -1479,7 +1482,7 @@ static SRes SzReadHeader2(
 static SRes SzReadHeader(
     CSzArEx *p,
     CSzData *sd,
-    ILookInStream *inStream,
+    ILookInStreamPtr inStream,
     ISzAllocPtr allocMain,
     ISzAllocPtr allocTemp)
 {
@@ -1498,7 +1501,7 @@ static SRes SzReadHeader(
   for (i = 0; i < NUM_ADDITIONAL_STREAMS_MAX; i++)
     Buf_Free(tempBufs + i, allocTemp);
 
-  RINOK(res);
+  RINOK(res)
 
   if (sd->Size != 0)
     return SZ_ERROR_FAIL;
@@ -1508,7 +1511,7 @@ static SRes SzReadHeader(
 
 static SRes SzArEx_Open2(
     CSzArEx *p,
-    ILookInStream *inStream,
+    ILookInStreamPtr inStream,
     ISzAllocPtr allocMain,
     ISzAllocPtr allocTemp)
 {
@@ -1521,9 +1524,9 @@ static SRes SzArEx_Open2(
   SRes res;
 
   startArcPos = 0;
-  RINOK(ILookInStream_Seek(inStream, &startArcPos, SZ_SEEK_CUR));
+  RINOK(ILookInStream_Seek(inStream, &startArcPos, SZ_SEEK_CUR))
 
-  RINOK(LookInStream_Read2(inStream, header, k7zStartHeaderSize, SZ_ERROR_NO_ARCHIVE));
+  RINOK(LookInStream_Read2(inStream, header, k7zStartHeaderSize, SZ_ERROR_NO_ARCHIVE))
 
   if (!TestSignatureCandidate(header))
     return SZ_ERROR_NO_ARCHIVE;
@@ -1552,14 +1555,14 @@ static SRes SzArEx_Open2(
 
   {
     Int64 pos = 0;
-    RINOK(ILookInStream_Seek(inStream, &pos, SZ_SEEK_END));
+    RINOK(ILookInStream_Seek(inStream, &pos, SZ_SEEK_END))
     if ((UInt64)pos < (UInt64)startArcPos + nextHeaderOffset ||
         (UInt64)pos < (UInt64)startArcPos + k7zStartHeaderSize + nextHeaderOffset ||
         (UInt64)pos < (UInt64)startArcPos + k7zStartHeaderSize + nextHeaderOffset + nextHeaderSize)
       return SZ_ERROR_INPUT_EOF;
   }
 
-  RINOK(LookInStream_SeekTo(inStream, (UInt64)startArcPos + k7zStartHeaderSize + nextHeaderOffset));
+  RINOK(LookInStream_SeekTo(inStream, (UInt64)startArcPos + k7zStartHeaderSize + nextHeaderOffset))
 
   if (!Buf_Create(&buf, nextHeaderSizeT, allocTemp))
     return SZ_ERROR_MEM;
@@ -1634,10 +1637,10 @@ static SRes SzArEx_Open2(
 }
 
 
-SRes SzArEx_Open(CSzArEx *p, ILookInStream *inStream,
+SRes SzArEx_Open(CSzArEx *p, ILookInStreamPtr inStream,
     ISzAllocPtr allocMain, ISzAllocPtr allocTemp)
 {
-  SRes res = SzArEx_Open2(p, inStream, allocMain, allocTemp);
+  const SRes res = SzArEx_Open2(p, inStream, allocMain, allocTemp);
   if (res != SZ_OK)
     SzArEx_Free(p, allocMain);
   return res;
@@ -1646,7 +1649,7 @@ SRes SzArEx_Open(CSzArEx *p, ILookInStre
 
 SRes SzArEx_Extract(
     const CSzArEx *p,
-    ILookInStream *inStream,
+    ILookInStreamPtr inStream,
     UInt32 fileIndex,
     UInt32 *blockIndex,
     Byte **tempBuf,
@@ -1656,7 +1659,7 @@ SRes SzArEx_Extract(
     ISzAllocPtr allocMain,
     ISzAllocPtr allocTemp)
 {
-  UInt32 folderIndex = p->FileToFolder[fileIndex];
+  const UInt32 folderIndex = p->FileToFolder[fileIndex];
   SRes res = SZ_OK;
   
   *offset = 0;
@@ -1673,13 +1676,13 @@ SRes SzArEx_Extract(
 
   if (*tempBuf == NULL || *blockIndex != folderIndex)
   {
-    UInt64 unpackSizeSpec = SzAr_GetFolderUnpackSize(&p->db, folderIndex);
+    const UInt64 unpackSizeSpec = SzAr_GetFolderUnpackSize(&p->db, folderIndex);
     /*
     UInt64 unpackSizeSpec =
         p->UnpackPositions[p->FolderToFile[(size_t)folderIndex + 1]] -
         p->UnpackPositions[p->FolderToFile[folderIndex]];
     */
-    size_t unpackSize = (size_t)unpackSizeSpec;
+    const size_t unpackSize = (size_t)unpackSizeSpec;
 
     if (unpackSize != unpackSizeSpec)
       return SZ_ERROR_MEM;
@@ -1707,7 +1710,7 @@ SRes SzArEx_Extract(
 
   if (res == SZ_OK)
   {
-    UInt64 unpackPos = p->UnpackPositions[fileIndex];
+    const UInt64 unpackPos = p->UnpackPositions[fileIndex];
     *offset = (size_t)(unpackPos - p->UnpackPositions[p->FolderToFile[folderIndex]]);
     *outSizeProcessed = (size_t)(p->UnpackPositions[(size_t)fileIndex + 1] - unpackPos);
     if (*offset + *outSizeProcessed > *outBufferSize)
@@ -1723,8 +1726,8 @@ SRes SzArEx_Extract(
 
 size_t SzArEx_GetFileNameUtf16(const CSzArEx *p, size_t fileIndex, UInt16 *dest)
 {
-  size_t offs = p->FileNameOffsets[fileIndex];
-  size_t len = p->FileNameOffsets[fileIndex + 1] - offs;
+  const size_t offs = p->FileNameOffsets[fileIndex];
+  const size_t len = p->FileNameOffsets[fileIndex + 1] - offs;
   if (dest != 0)
   {
     size_t i;
