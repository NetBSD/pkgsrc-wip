$NetBSD: patch-third__party_WebKit_Source_WebCore_storage_IDBDatabaseBackendImpl.cpp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/WebKit/Source/WebCore/storage/IDBDatabaseBackendImpl.cpp.orig	2011-05-24 08:03:11.000000000 +0000
+++ third_party/WebKit/Source/WebCore/storage/IDBDatabaseBackendImpl.cpp
@@ -72,9 +72,9 @@ IDBDatabaseBackendImpl::IDBDatabaseBacke
 {
     ASSERT(!m_name.isNull());
 
-    bool success = m_backingStore->extractIDBDatabaseMetaData(m_name, m_version, m_id);
+    bool success = m_backingStore->extractIDBDatabaseMetaData(m_name, m_version, (int64_t &)m_id);
     ASSERT_UNUSED(success, success == (m_id != InvalidId));
-    if (!m_backingStore->setIDBDatabaseMetaData(m_name, m_version, m_id, m_id == InvalidId))
+    if (!m_backingStore->setIDBDatabaseMetaData(m_name, m_version, (int64_t &)m_id, m_id == InvalidId))
         ASSERT_NOT_REACHED(); // FIXME: Need better error handling.
     loadObjectStores();
 }
