$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Bcj2.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Bcj2.c
@@ -1,29 +1,24 @@
 /* Bcj2.c -- BCJ2 Decoder (Converter for x86 code)
-2021-02-09 : Igor Pavlov : Public domain */
+2023-03-01 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
 #include "Bcj2.h"
 #include "CpuArch.h"
 
-#define CProb UInt16
-
 #define kTopValue ((UInt32)1 << 24)
-#define kNumModelBits 11
-#define kBitModelTotal (1 << kNumModelBits)
+#define kNumBitModelTotalBits 11
+#define kBitModelTotal (1 << kNumBitModelTotalBits)
 #define kNumMoveBits 5
 
-#define _IF_BIT_0 ttt = *prob; bound = (p->range >> kNumModelBits) * ttt; if (p->code < bound)
-#define _UPDATE_0 p->range = bound; *prob = (CProb)(ttt + ((kBitModelTotal - ttt) >> kNumMoveBits));
-#define _UPDATE_1 p->range -= bound; p->code -= bound; *prob = (CProb)(ttt - (ttt >> kNumMoveBits));
+// UInt32 bcj2_stats[256 + 2][2];
 
 void Bcj2Dec_Init(CBcj2Dec *p)
 {
   unsigned i;
-
-  p->state = BCJ2_DEC_STATE_OK;
+  p->state = BCJ2_STREAM_RC; // BCJ2_DEC_STATE_OK;
   p->ip = 0;
-  p->temp[3] = 0;
+  p->temp = 0;
   p->range = 0;
   p->code = 0;
   for (i = 0; i < sizeof(p->probs) / sizeof(p->probs[0]); i++)
@@ -32,217 +27,248 @@ void Bcj2Dec_Init(CBcj2Dec *p)
 
 SRes Bcj2Dec_Decode(CBcj2Dec *p)
 {
+  UInt32 v = p->temp;
+  // const Byte *src;
   if (p->range <= 5)
   {
-    p->state = BCJ2_DEC_STATE_OK;
+    UInt32 code = p->code;
+    p->state = BCJ2_DEC_STATE_ERROR; /* for case if we return SZ_ERROR_DATA; */
     for (; p->range != 5; p->range++)
     {
-      if (p->range == 1 && p->code != 0)
+      if (p->range == 1 && code != 0)
         return SZ_ERROR_DATA;
-      
       if (p->bufs[BCJ2_STREAM_RC] == p->lims[BCJ2_STREAM_RC])
       {
         p->state = BCJ2_STREAM_RC;
         return SZ_OK;
       }
-
-      p->code = (p->code << 8) | *(p->bufs[BCJ2_STREAM_RC])++;
+      code = (code << 8) | *(p->bufs[BCJ2_STREAM_RC])++;
+      p->code = code;
     }
-    
-    if (p->code == 0xFFFFFFFF)
+    if (code == 0xffffffff)
       return SZ_ERROR_DATA;
-    
-    p->range = 0xFFFFFFFF;
+    p->range = 0xffffffff;
   }
-  else if (p->state >= BCJ2_DEC_STATE_ORIG_0)
+  // else
   {
-    while (p->state <= BCJ2_DEC_STATE_ORIG_3)
+    unsigned state = p->state;
+    // we check BCJ2_IS_32BIT_STREAM() here instead of check in the main loop
+    if (BCJ2_IS_32BIT_STREAM(state))
     {
-      Byte *dest = p->dest;
-      if (dest == p->destLim)
+      const Byte *cur = p->bufs[state];
+      if (cur == p->lims[state])
         return SZ_OK;
-      *dest = p->temp[(size_t)p->state - BCJ2_DEC_STATE_ORIG_0];
-      p->state++;
-      p->dest = dest + 1;
+      p->bufs[state] = cur + 4;
+      {
+        const UInt32 ip = p->ip + 4;
+        v = GetBe32a(cur) - ip;
+        p->ip = ip;
+      }
+      state = BCJ2_DEC_STATE_ORIG_0;
     }
-  }
-
-  /*
-  if (BCJ2_IS_32BIT_STREAM(p->state))
-  {
-    const Byte *cur = p->bufs[p->state];
-    if (cur == p->lims[p->state])
-      return SZ_OK;
-    p->bufs[p->state] = cur + 4;
-    
+    if ((unsigned)(state - BCJ2_DEC_STATE_ORIG_0) < 4)
     {
-      UInt32 val;
-      Byte *dest;
-      SizeT rem;
-      
-      p->ip += 4;
-      val = GetBe32(cur) - p->ip;
-      dest = p->dest;
-      rem = p->destLim - dest;
-      if (rem < 4)
+      Byte *dest = p->dest;
+      for (;;)
       {
-        SizeT i;
-        SetUi32(p->temp, val);
-        for (i = 0; i < rem; i++)
-          dest[i] = p->temp[i];
-        p->dest = dest + rem;
-        p->state = BCJ2_DEC_STATE_ORIG_0 + (unsigned)rem;
-        return SZ_OK;
+        if (dest == p->destLim)
+        {
+          p->state = state;
+          p->temp = v;
+          return SZ_OK;
+        }
+        *dest++ = (Byte)v;
+        p->dest = dest;
+        if (++state == BCJ2_DEC_STATE_ORIG_3 + 1)
+          break;
+        v >>= 8;
       }
-      SetUi32(dest, val);
-      p->temp[3] = (Byte)(val >> 24);
-      p->dest = dest + 4;
-      p->state = BCJ2_DEC_STATE_OK;
     }
   }
-  */
 
+  // src = p->bufs[BCJ2_STREAM_MAIN];
   for (;;)
   {
+    /*
     if (BCJ2_IS_32BIT_STREAM(p->state))
       p->state = BCJ2_DEC_STATE_OK;
     else
+    */
     {
       if (p->range < kTopValue)
       {
         if (p->bufs[BCJ2_STREAM_RC] == p->lims[BCJ2_STREAM_RC])
         {
           p->state = BCJ2_STREAM_RC;
+          p->temp = v;
           return SZ_OK;
         }
         p->range <<= 8;
         p->code = (p->code << 8) | *(p->bufs[BCJ2_STREAM_RC])++;
       }
-
       {
         const Byte *src = p->bufs[BCJ2_STREAM_MAIN];
         const Byte *srcLim;
-        Byte *dest;
-        SizeT num = (SizeT)(p->lims[BCJ2_STREAM_MAIN] - src);
-        
-        if (num == 0)
+        Byte *dest = p->dest;
         {
-          p->state = BCJ2_STREAM_MAIN;
-          return SZ_OK;
+          const SizeT rem = (SizeT)(p->lims[BCJ2_STREAM_MAIN] - src);
+          SizeT num = (SizeT)(p->destLim - dest);
+          if (num >= rem)
+            num = rem;
+        #define NUM_ITERS 4
+        #if (NUM_ITERS & (NUM_ITERS - 1)) == 0
+          num &= ~((SizeT)NUM_ITERS - 1);   // if (NUM_ITERS == (1 << x))
+        #else
+          num -= num % NUM_ITERS; // if (NUM_ITERS != (1 << x))
+        #endif
+          srcLim = src + num;
         }
-        
-        dest = p->dest;
-        if (num > (SizeT)(p->destLim - dest))
+
+        #define NUM_SHIFT_BITS  24
+        #define ONE_ITER(indx) { \
+          const unsigned b = src[indx]; \
+          *dest++ = (Byte)b; \
+          v = (v << NUM_SHIFT_BITS) | b; \
+          if (((b + (0x100 - 0xe8)) & 0xfe) == 0) break; \
+          if (((v - (((UInt32)0x0f << (NUM_SHIFT_BITS)) + 0x80)) & \
+              ((((UInt32)1 << (4 + NUM_SHIFT_BITS)) - 0x1) << 4)) == 0) break; \
+            /* ++dest */; /* v = b; */ }
+
+        if (src != srcLim)
+        for (;;)
         {
-          num = (SizeT)(p->destLim - dest);
-          if (num == 0)
-          {
-            p->state = BCJ2_DEC_STATE_ORIG;
-            return SZ_OK;
-          }
+            /* The dependency chain of 2-cycle for (v) calculation is not big problem here.
+               But we can remove dependency chain with v = b in the end of loop. */
+          ONE_ITER(0)
+          #if (NUM_ITERS > 1)
+            ONE_ITER(1)
+          #if (NUM_ITERS > 2)
+            ONE_ITER(2)
+          #if (NUM_ITERS > 3)
+            ONE_ITER(3)
+          #if (NUM_ITERS > 4)
+            ONE_ITER(4)
+          #if (NUM_ITERS > 5)
+            ONE_ITER(5)
+          #if (NUM_ITERS > 6)
+            ONE_ITER(6)
+          #if (NUM_ITERS > 7)
+            ONE_ITER(7)
+          #endif
+          #endif
+          #endif
+          #endif
+          #endif
+          #endif
+          #endif
+
+          src += NUM_ITERS;
+          if (src == srcLim)
+            break;
         }
-       
-        srcLim = src + num;
 
-        if (p->temp[3] == 0x0F && (src[0] & 0xF0) == 0x80)
-          *dest = src[0];
-        else for (;;)
+        if (src == srcLim)
+      #if (NUM_ITERS > 1)
+        for (;;)
+      #endif
         {
-          Byte b = *src;
-          *dest = b;
-          if (b != 0x0F)
+        #if (NUM_ITERS > 1)
+          if (src == p->lims[BCJ2_STREAM_MAIN] || dest == p->destLim)
+        #endif
           {
-            if ((b & 0xFE) == 0xE8)
-              break;
-            dest++;
-            if (++src != srcLim)
-              continue;
-            break;
+            const SizeT num = (SizeT)(src - p->bufs[BCJ2_STREAM_MAIN]);
+            p->bufs[BCJ2_STREAM_MAIN] = src;
+            p->dest = dest;
+            p->ip += (UInt32)num;
+            /* state BCJ2_STREAM_MAIN has more priority than BCJ2_STATE_ORIG */
+            p->state =
+              src == p->lims[BCJ2_STREAM_MAIN] ?
+                (unsigned)BCJ2_STREAM_MAIN :
+                (unsigned)BCJ2_DEC_STATE_ORIG;
+            p->temp = v;
+            return SZ_OK;
           }
-          dest++;
-          if (++src == srcLim)
-            break;
-          if ((*src & 0xF0) != 0x80)
-            continue;
-          *dest = *src;
-          break;
+        #if (NUM_ITERS > 1)
+          ONE_ITER(0)
+          src++;
+        #endif
         }
-        
-        num = (SizeT)(src - p->bufs[BCJ2_STREAM_MAIN]);
-        
-        if (src == srcLim)
+
         {
-          p->temp[3] = src[-1];
-          p->bufs[BCJ2_STREAM_MAIN] = src;
+          const SizeT num = (SizeT)(dest - p->dest);
+          p->dest = dest; // p->dest += num;
+          p->bufs[BCJ2_STREAM_MAIN] += num; // = src;
           p->ip += (UInt32)num;
-          p->dest += num;
-          p->state =
-            p->bufs[BCJ2_STREAM_MAIN] ==
-            p->lims[BCJ2_STREAM_MAIN] ?
-              (unsigned)BCJ2_STREAM_MAIN :
-              (unsigned)BCJ2_DEC_STATE_ORIG;
-          return SZ_OK;
         }
-        
         {
           UInt32 bound, ttt;
-          CProb *prob;
-          Byte b = src[0];
-          Byte prev = (Byte)(num == 0 ? p->temp[3] : src[-1]);
-          
-          p->temp[3] = b;
-          p->bufs[BCJ2_STREAM_MAIN] = src + 1;
-          num++;
-          p->ip += (UInt32)num;
-          p->dest += num;
-          
-          prob = p->probs + (unsigned)(b == 0xE8 ? 2 + (unsigned)prev : (b == 0xE9 ? 1 : 0));
-          
-          _IF_BIT_0
+          CBcj2Prob *prob; // unsigned index;
+          /*
+          prob = p->probs + (unsigned)((Byte)v == 0xe8 ?
+              2 + (Byte)(v >> 8) :
+              ((v >> 5) & 1));  // ((Byte)v < 0xe8 ? 0 : 1));
+          */
           {
-            _UPDATE_0
+            const unsigned c = ((v + 0x17) >> 6) & 1;
+            prob = p->probs + (unsigned)
+                (((0 - c) & (Byte)(v >> NUM_SHIFT_BITS)) + c + ((v >> 5) & 1));
+                // (Byte)
+                // 8x->0     : e9->1     : xxe8->xx+2
+                // 8x->0x100 : e9->0x101 : xxe8->xx
+                // (((0x100 - (e & ~v)) & (0x100 | (v >> 8))) + (e & v));
+                // (((0x101 + (~e | v)) & (0x100 | (v >> 8))) + (e & v));
+          }
+          ttt = *prob;
+          bound = (p->range >> kNumBitModelTotalBits) * ttt;
+          if (p->code < bound)
+          {
+            // bcj2_stats[prob - p->probs][0]++;
+            p->range = bound;
+            *prob = (CBcj2Prob)(ttt + ((kBitModelTotal - ttt) >> kNumMoveBits));
             continue;
           }
-          _UPDATE_1
-            
+          {
+            // bcj2_stats[prob - p->probs][1]++;
+            p->range -= bound;
+            p->code -= bound;
+            *prob = (CBcj2Prob)(ttt - (ttt >> kNumMoveBits));
+          }
         }
       }
     }
-
     {
-      UInt32 val;
-      unsigned cj = (p->temp[3] == 0xE8) ? BCJ2_STREAM_CALL : BCJ2_STREAM_JUMP;
+      /* (v == 0xe8 ? 0 : 1) uses setcc instruction with additional zero register usage in x64 MSVC. */
+      // const unsigned cj = ((Byte)v == 0xe8) ? BCJ2_STREAM_CALL : BCJ2_STREAM_JUMP;
+      const unsigned cj = (((v + 0x57) >> 6) & 1) + BCJ2_STREAM_CALL;
       const Byte *cur = p->bufs[cj];
       Byte *dest;
       SizeT rem;
-      
       if (cur == p->lims[cj])
       {
         p->state = cj;
         break;
       }
-      
-      val = GetBe32(cur);
+      v = GetBe32a(cur);
       p->bufs[cj] = cur + 4;
-
-      p->ip += 4;
-      val -= p->ip;
+      {
+        const UInt32 ip = p->ip + 4;
+        v -= ip;
+        p->ip = ip;
+      }
       dest = p->dest;
       rem = (SizeT)(p->destLim - dest);
-      
       if (rem < 4)
       {
-        p->temp[0] = (Byte)val; if (rem > 0) dest[0] = (Byte)val; val >>= 8;
-        p->temp[1] = (Byte)val; if (rem > 1) dest[1] = (Byte)val; val >>= 8;
-        p->temp[2] = (Byte)val; if (rem > 2) dest[2] = (Byte)val; val >>= 8;
-        p->temp[3] = (Byte)val;
+        if ((unsigned)rem > 0) { dest[0] = (Byte)v;  v >>= 8;
+        if ((unsigned)rem > 1) { dest[1] = (Byte)v;  v >>= 8;
+        if ((unsigned)rem > 2) { dest[2] = (Byte)v;  v >>= 8; }}}
+        p->temp = v;
         p->dest = dest + rem;
         p->state = BCJ2_DEC_STATE_ORIG_0 + (unsigned)rem;
         break;
       }
-      
-      SetUi32(dest, val);
-      p->temp[3] = (Byte)(val >> 24);
+      SetUi32(dest, v)
+      v >>= 24;
       p->dest = dest + 4;
     }
   }
@@ -252,6 +278,13 @@ SRes Bcj2Dec_Decode(CBcj2Dec *p)
     p->range <<= 8;
     p->code = (p->code << 8) | *(p->bufs[BCJ2_STREAM_RC])++;
   }
-
   return SZ_OK;
 }
+
+#undef NUM_ITERS
+#undef ONE_ITER
+#undef NUM_SHIFT_BITS
+#undef kTopValue
+#undef kNumBitModelTotalBits
+#undef kBitModelTotal
+#undef kNumMoveBits
