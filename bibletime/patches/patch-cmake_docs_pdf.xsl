$NetBSD: patch-cmake_docs_pdf.xsl,v 1.1 2015/02/13 15:18:00 nros Exp $
* use right xsl file
--- cmake/docs/pdf.xsl.orig	2014-07-05 14:29:03.000000000 +0000
+++ cmake/docs/pdf.xsl
@@ -1,4 +1,4 @@
 <?xml version='1.0'?>
 <xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
-	<xsl:import href="/usr/share/sgml/docbook/xsl-stylesheets-1.75.2/fo/docbook.xsl"/>
+	<xsl:import href="@PREFIX@/share/xsl/docbook/fo/docbook.xsl"/>
 </xsl:stylesheet>
