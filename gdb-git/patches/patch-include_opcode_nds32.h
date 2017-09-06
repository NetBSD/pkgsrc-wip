$NetBSD$

--- include/opcode/nds32.h.orig	2017-09-04 13:40:58.000000000 +0000
+++ include/opcode/nds32.h
@@ -50,8 +50,8 @@ static const int nds32_r54map[] ATTRIBUT
   -1, -1, -1, -1, -1, -1, -1, -1
 };
 
-#define __BIT(n)		(1 << (n))
-#define __MASK(n)		(__BIT (n) - 1)
+#define N32_BIT(n)		(1 << (n))
+#define __MASK(n)		(N32_BIT (n) - 1)
 #define __MF(v, off, bs)	(((v) & __MASK (bs)) << (off))
 #define __GF(v, off, bs)	(((v) >> off) & __MASK (bs))
 #define __SEXT(v, bs)		((((v) & ((1 << (bs)) - 1)) ^ (1 << ((bs) - 1))) - (1 << ((bs) - 1)))
