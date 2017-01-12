$NetBSD$

This fixes an issue with sqlite that prevents clementine from updating
its database.

--- src/core/database.cpp.orig	2017-01-12 02:11:37.431771144 +0000
+++ src/core/database.cpp
@@ -265,6 +265,16 @@ QSqlDatabase Database::Connect() {
   StaticInit();
 
   {
+#ifdef SQLITE_DBCONFIG_ENABLE_FTS3_TOKENIZER
+	  QVariant v = db.driver()->handle();
+	  if (!(v.isValid() && qstrcmp(v.typeName(), "sqlite3*"))) {
+		  sqlite3* handle = *static_cast<sqlite3**>(v.data());
+		  if (handle) {
+			  sqlite3_db_config(handle, SQLITE_DBCONFIG_ENABLE_FTS3_TOKENIZER, 1, NULL);
+		  }
+	  }
+#endif
+
     QSqlQuery set_fts_tokenizer("SELECT fts3_tokenizer(:name, :pointer)", db);
     set_fts_tokenizer.bindValue(":name", "unicode");
     set_fts_tokenizer.bindValue(
