$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/lzma_sdk/C/Bra86.c.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/lzma_sdk/C/Bra86.c
@@ -1,82 +1,187 @@
-/* Bra86.c -- Converter for x86 code (BCJ)
-2021-02-09 : Igor Pavlov : Public domain */
+/* Bra86.c -- Branch converter for X86 code (BCJ)
+2023-04-02 : Igor Pavlov : Public domain */
 
 #include "Precomp.h"
 
 #include "Bra.h"
+#include "CpuArch.h"
 
-#define Test86MSByte(b) ((((b) + 1) & 0xFE) == 0)
 
-SizeT x86_Convert(Byte *data, SizeT size, UInt32 ip, UInt32 *state, int encoding)
+#if defined(MY_CPU_SIZEOF_POINTER) \
+    && ( MY_CPU_SIZEOF_POINTER == 4 \
+      || MY_CPU_SIZEOF_POINTER == 8)
+  #define BR_CONV_USE_OPT_PC_PTR
+#endif
+
+#ifdef BR_CONV_USE_OPT_PC_PTR
+#define BR_PC_INIT  pc -= (UInt32)(SizeT)p; // (MY_uintptr_t)
+#define BR_PC_GET   (pc + (UInt32)(SizeT)p)
+#else
+#define BR_PC_INIT  pc += (UInt32)size;
+#define BR_PC_GET   (pc - (UInt32)(SizeT)(lim - p))
+// #define BR_PC_INIT
+// #define BR_PC_GET   (pc + (UInt32)(SizeT)(p - data))
+#endif
+
+#define BR_CONVERT_VAL(v, c) if (encoding) v += c; else v -= c;
+// #define BR_CONVERT_VAL(v, c) if (!encoding) c = (UInt32)0 - c; v += c;
+
+#define Z7_BRANCH_CONV_ST(name) z7_BranchConvSt_ ## name
+
+#define BR86_NEED_CONV_FOR_MS_BYTE(b) ((((b) + 1) & 0xfe) == 0)
+
+#ifdef MY_CPU_LE_UNALIGN
+  #define BR86_PREPARE_BCJ_SCAN  const UInt32 v = GetUi32(p) ^ 0xe8e8e8e8;
+  #define BR86_IS_BCJ_BYTE(n)    ((v & ((UInt32)0xfe << (n) * 8)) == 0)
+#else
+  #define BR86_PREPARE_BCJ_SCAN
+  // bad for MSVC X86 (partial write to byte reg):
+  #define BR86_IS_BCJ_BYTE(n)    ((p[n - 4] & 0xfe) == 0xe8)
+  // bad for old MSVC (partial write to byte reg):
+  // #define BR86_IS_BCJ_BYTE(n)    (((*p ^ 0xe8) & 0xfe) == 0)
+#endif
+
+static
+Z7_FORCE_INLINE
+Z7_ATTRIB_NO_VECTOR
+Byte *Z7_BRANCH_CONV_ST(X86)(Byte *p, SizeT size, UInt32 pc, UInt32 *state, int encoding)
 {
-  SizeT pos = 0;
-  UInt32 mask = *state & 7;
   if (size < 5)
-    return 0;
-  size -= 4;
-  ip += 5;
+    return p;
+ {
+  // Byte *p = data;
+  const Byte *lim = p + size - 4;
+  unsigned mask = (unsigned)*state;  // & 7;
+#ifdef BR_CONV_USE_OPT_PC_PTR
+  /* if BR_CONV_USE_OPT_PC_PTR is defined: we need to adjust (pc) for (+4),
+        because call/jump offset is relative to the next instruction.
+     if BR_CONV_USE_OPT_PC_PTR is not defined : we don't need to adjust (pc) for (+4),
+         because  BR_PC_GET uses (pc - (lim - p)), and lim was adjusted for (-4) before.
+  */
+  pc += 4;
+#endif
+  BR_PC_INIT
+  goto start;
 
-  for (;;)
+  for (;; mask |= 4)
   {
-    Byte *p = data + pos;
-    const Byte *limit = data + size;
-    for (; p < limit; p++)
-      if ((*p & 0xFE) == 0xE8)
-        break;
-
+    // cont: mask |= 4;
+  start:
+    if (p >= lim)
+      goto fin;
     {
-      SizeT d = (SizeT)(p - data) - pos;
-      pos = (SizeT)(p - data);
-      if (p >= limit)
-      {
-        *state = (d > 2 ? 0 : mask >> (unsigned)d);
-        return pos;
-      }
-      if (d > 2)
-        mask = 0;
-      else
-      {
-        mask >>= (unsigned)d;
-        if (mask != 0 && (mask > 4 || mask == 3 || Test86MSByte(p[(size_t)(mask >> 1) + 1])))
-        {
-          mask = (mask >> 1) | 4;
-          pos++;
-          continue;
-        }
-      }
+      BR86_PREPARE_BCJ_SCAN
+      p += 4;
+      if (BR86_IS_BCJ_BYTE(0))  { goto m0; }  mask >>= 1;
+      if (BR86_IS_BCJ_BYTE(1))  { goto m1; }  mask >>= 1;
+      if (BR86_IS_BCJ_BYTE(2))  { goto m2; }  mask = 0;
+      if (BR86_IS_BCJ_BYTE(3))  { goto a3; }
     }
+    goto main_loop;
+
+  m0: p--;
+  m1: p--;
+  m2: p--;
+    if (mask == 0)
+      goto a3;
+    if (p > lim)
+      goto fin_p;
 
-    if (Test86MSByte(p[4]))
+    // if (((0x17u >> mask) & 1) == 0)
+    if (mask > 4 || mask == 3)
     {
-      UInt32 v = ((UInt32)p[4] << 24) | ((UInt32)p[3] << 16) | ((UInt32)p[2] << 8) | ((UInt32)p[1]);
-      UInt32 cur = ip + (UInt32)pos;
-      pos += 5;
-      if (encoding)
-        v += cur;
-      else
-        v -= cur;
-      if (mask != 0)
+      mask >>= 1;
+      continue; // goto cont;
+    }
+    mask >>= 1;
+    if (BR86_NEED_CONV_FOR_MS_BYTE(p[mask]))
+      continue; // goto cont;
+    // if (!BR86_NEED_CONV_FOR_MS_BYTE(p[3])) continue; // goto cont;
+    {
+      UInt32 v = GetUi32(p);
+      UInt32 c;
+      v += (1 << 24);  if (v & 0xfe000000) continue; // goto cont;
+      c = BR_PC_GET;
+      BR_CONVERT_VAL(v, c)
       {
-        unsigned sh = (mask & 6) << 2;
-        if (Test86MSByte((Byte)(v >> sh)))
+        mask <<= 3;
+        if (BR86_NEED_CONV_FOR_MS_BYTE(v >> mask))
         {
-          v ^= (((UInt32)0x100 << sh) - 1);
-          if (encoding)
-            v += cur;
-          else
-            v -= cur;
+          v ^= (((UInt32)0x100 << mask) - 1);
+          #ifdef MY_CPU_X86
+          // for X86 : we can recalculate (c) to reduce register pressure
+            c = BR_PC_GET;
+          #endif
+          BR_CONVERT_VAL(v, c)
         }
         mask = 0;
       }
-      p[1] = (Byte)v;
-      p[2] = (Byte)(v >> 8);
-      p[3] = (Byte)(v >> 16);
-      p[4] = (Byte)(0 - ((v >> 24) & 1));
+      // v = (v & ((1 << 24) - 1)) - (v & (1 << 24));
+      v &= (1 << 25) - 1;  v -= (1 << 24);
+      SetUi32(p, v)
+      p += 4;
+      goto main_loop;
     }
-    else
+
+  main_loop:
+    if (p >= lim)
+      goto fin;
+    for (;;)
     {
-      mask = (mask >> 1) | 4;
-      pos++;
+      BR86_PREPARE_BCJ_SCAN
+      p += 4;
+      if (BR86_IS_BCJ_BYTE(0))  { goto a0; }
+      if (BR86_IS_BCJ_BYTE(1))  { goto a1; }
+      if (BR86_IS_BCJ_BYTE(2))  { goto a2; }
+      if (BR86_IS_BCJ_BYTE(3))  { goto a3; }
+      if (p >= lim)
+        goto fin;
+    }
+
+  a0: p--;
+  a1: p--;
+  a2: p--;
+  a3:
+    if (p > lim)
+      goto fin_p;
+    // if (!BR86_NEED_CONV_FOR_MS_BYTE(p[3])) continue; // goto cont;
+    {
+      UInt32 v = GetUi32(p);
+      UInt32 c;
+      v += (1 << 24);  if (v & 0xfe000000) continue; // goto cont;
+      c = BR_PC_GET;
+      BR_CONVERT_VAL(v, c)
+      // v = (v & ((1 << 24) - 1)) - (v & (1 << 24));
+      v &= (1 << 25) - 1;  v -= (1 << 24);
+      SetUi32(p, v)
+      p += 4;
+      goto main_loop;
     }
   }
+
+fin_p:
+  p--;
+fin:
+  // the following processing for tail is optional and can be commented
+  /*
+  lim += 4;
+  for (; p < lim; p++, mask >>= 1)
+    if ((*p & 0xfe) == 0xe8)
+      break;
+  */
+  *state = (UInt32)mask;
+  return p;
+ }
 }
+
+
+#define Z7_BRANCH_CONV_ST_FUNC_IMP(name, m, encoding) \
+Z7_NO_INLINE \
+Z7_ATTRIB_NO_VECTOR \
+Byte *m(name)(Byte *data, SizeT size, UInt32 pc, UInt32 *state) \
+  { return Z7_BRANCH_CONV_ST(name)(data, size, pc, state, encoding); }
+
+Z7_BRANCH_CONV_ST_FUNC_IMP(X86, Z7_BRANCH_CONV_ST_DEC, 0)
+#ifndef Z7_EXTRACT_ONLY
+Z7_BRANCH_CONV_ST_FUNC_IMP(X86, Z7_BRANCH_CONV_ST_ENC, 1)
+#endif
