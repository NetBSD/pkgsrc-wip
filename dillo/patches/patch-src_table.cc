$NetBSD$

Avoid ctype(3) undefined behaviours.

--- src/table.cc.orig	2026-01-06 16:25:07.244361847 +0000
+++ src/table.cc
@@ -51,7 +51,7 @@ void Html_tag_open_table(DilloHtml *html
    CssLength cssLength;
 
    if ((attrbuf = a_Html_get_attr(html, tag, tagsize, "border")))
-      border = isdigit(attrbuf[0]) ? strtol (attrbuf, NULL, 10) : 1;
+      border = isdigit((unsigned char)attrbuf[0]) ? strtol (attrbuf, NULL, 10) : 1;
    if ((attrbuf = a_Html_get_attr(html, tag, tagsize, "cellspacing"))) {
       cellspacing = strtol (attrbuf, NULL, 10);
       if (html->DocType == DT_HTML && html->DocTypeVersion >= 5.0f)
