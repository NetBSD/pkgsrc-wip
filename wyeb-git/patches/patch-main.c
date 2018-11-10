$NetBSD$

Use the correct data type for modification time.

--- main.c.orig	2018-11-10 14:18:57.000000000 +0000
+++ main.c
@@ -2895,7 +2895,7 @@ static char *histdata(bool rest, bool al
 	int size = all ? 0 : confint("histviewsize");
 
 	int start = 0;
-	__time_t mtime = 0;
+	time_t mtime = 0;
 	for (int j = 2; j > 0; j--) for (int i = histfnum - 1; i >= 0; i--)
 	{
 		if (!rest && size && num >= size) break;
