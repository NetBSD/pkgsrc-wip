$NetBSD: patch-src_af_util_xp_ut__mbtowc.cpp,v 1.1 2015/06/15 09:01:24 nros Exp $
* remove bom if it comes with the conversion
  makes the rulers look correct on startup
--- src/af/util/xp/ut_mbtowc.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/util/xp/ut_mbtowc.cpp
@@ -192,7 +192,24 @@ int UT_UCS4_mbtowc::mbtowc (UT_UCS4Char 
 	gsize bytes_read = 0;
 	gsize bytes_written = 0;
 	GError* error = NULL;
-	gchar* out = g_convert_with_iconv(inptr, inlen, (GIConv)cd, &bytes_read, &bytes_written, &error);
+	gchar* out = NULL;
+        char bom_le[4] = {-1,-2,0,0};
+	char bom_be[4] = {-2,-1,0,0};
+	
+	out = g_convert_with_iconv(inptr, inlen, (GIConv)cd, &bytes_read, &bytes_written, &error);
+	// if we get a bom with the conversion redo it to get one without a bom
+	if (out && bytes_written == 8)
+	{
+                if (memcmp(out, bom_be, 4) == 0 || memcmp(out, bom_le, 4) == 0)
+                {
+                        bytes_read = 0;
+                        bytes_written = 0;
+                        error = NULL;
+                        FREEP(out);
+			out = g_convert_with_iconv(inptr, inlen, (GIConv)cd, &bytes_read, &bytes_written, &error);
+                }
+        }
+	
 	if (out && bytes_written == 4)
 	{
 		memcpy(&wc, out, 4);
