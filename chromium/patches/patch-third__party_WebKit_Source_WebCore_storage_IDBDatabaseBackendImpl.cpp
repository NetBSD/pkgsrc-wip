$NetBSD: patch-third__party_WebKit_Source_WebCore_storage_IDBDatabaseBackendImpl.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/storage/IDBDatabaseBackendImpl.cpp.orig	2011-04-13 08:12:17.000000000 +0000
+++ third_party/WebKit/Source/WebCore/storage/IDBDatabaseBackendImpl.cpp
@@ -100,7 +100,7 @@ IDBDatabaseBackendImpl::IDBDatabaseBacke
 
     bool success = extractMetaData(m_sqliteDatabase->db(), m_name, m_version, m_id);
     ASSERT_UNUSED(success, success == (m_id != InvalidId));
-    if (!setMetaData(m_sqliteDatabase->db(), m_name, m_version, m_id))
+    if (!setMetaData(m_sqliteDatabase->db(), m_name, m_version, (int64_t&)m_id))
         ASSERT_NOT_REACHED(); // FIXME: Need better error handling.
     loadObjectStores();
 }
