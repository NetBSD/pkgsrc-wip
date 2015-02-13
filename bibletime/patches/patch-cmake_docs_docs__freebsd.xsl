$NetBSD: patch-cmake_docs_docs__freebsd.xsl,v 1.1 2015/02/13 15:18:00 nros Exp $
* use right xsl file
--- cmake/docs/docs_freebsd.xsl.orig	2014-07-05 14:29:03.000000000 +0000
+++ cmake/docs/docs_freebsd.xsl
@@ -1,5 +1,5 @@
 <?xml version='1.0'?>
 <xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
-	<xsl:import href="/usr/local/share/xsl/docbook/html/chunk.xsl"/>
+	<xsl:import href="@PREFIX@/share/xsl/docbook/html/chunk.xsl"/>
 	<xsl:param name="use.id.as.filename" select="1"/>
 </xsl:stylesheet>
