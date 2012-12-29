$NetBSD: patch-sql_chartablesql.cpp,v 1.1 2012/12/29 14:51:33 othyro Exp $

Removing unnecessary function qualifier.

--- sql/chartablesql.cpp.orig	2010-12-28 12:30:54.000000000 +0000
+++ sql/chartablesql.cpp
@@ -57,7 +57,7 @@ QVariant CharSqlModel::data(const QModel
 			// Read the unicode value
 			unicode = value.toInt();
 			// Convert unicode to a char
-			unicodeToChar = QString::QString(QChar(unicode)); //"\'" + QString::QString(QChar(unicode)) + "\'";
+			unicodeToChar = QString(QChar(unicode)); //"\'" + QString::QString(QChar(unicode)) + "\'";
 			return unicodeToChar;
 		} else {
 			// Last column (error weight)
