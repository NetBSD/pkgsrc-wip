$NetBSD: patch-lib_ext2fs_bitops.c,v 1.1 2014/12/10 12:54:23 makoto Exp $

/usr/include/strings.h:60:14: note: previous declaration of 'popcount32' was here
 unsigned int popcount32(__uint32_t) __constfunc;

--- lib/ext2fs/bitops.c~	2014-07-03 23:33:48.000000000 +0900
+++ lib/ext2fs/bitops.c	2014-12-10 21:13:14.000000000 +0900
@@ -123,7 +123,11 @@ static unsigned int popcount8(unsigned i
 	return (res + (res >> 4)) & 0x0F;
 }
 
+#ifdef __NetBSD__
+       unsigned int popcount32(__uint32_t w)
+#else
 static unsigned int popcount32(unsigned int w)
+#endif
 {
 	unsigned int res = w - ((w >> 1) & 0x55555555);
 	res = (res & 0x33333333) + ((res >> 2) & 0x33333333);
