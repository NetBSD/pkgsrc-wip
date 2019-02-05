 - Explicity ignore fwrite return value.
 - Support NetBSD's iconv() prototype.

--- src/xlstool.c
+++ src/xlstool.c
@@ -124,7 +124,7 @@ static const DWORD colors[] =
 void dumpbuf(BYTE* fname,long size,BYTE* buf)
 {
     FILE *f = fopen((char *)fname, "wb");
-    fwrite (buf, 1, size, f);
+    (void)fwrite (buf, 1, size, f);
     fclose(f);
 
 }
@@ -220,7 +220,11 @@ static char* unicode_decode_iconv(const char *s, size_t len, size_t *newlen, con
             out_ptr = outbuf;
             while(inlenleft)
             {
+#if defined(__NetBSD__) || defined(__sun)
+                st = iconv(ic, &src_ptr, &inlenleft, (char **)&out_ptr,(size_t *) &outlenleft);
+#else
                 st = iconv(ic, (char **)&src_ptr, &inlenleft, (char **)&out_ptr,(size_t *) &outlenleft);
+#endif
                 if(st == (size_t)(-1))
                 {
                     if(errno == E2BIG)
