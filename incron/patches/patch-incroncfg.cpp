$NetBSD$

Do not hardcode system paths. This is pkgsrc-specific.

--- incroncfg.cpp.orig	2023-02-02 20:15:05.818702837 +0000
+++ incroncfg.cpp
@@ -24,7 +24,7 @@
 #include "incroncfg.h"
 
 
-#define INCRON_CFG_DEFAULT "/etc/incron.conf"
+#define INCRON_CFG_DEFAULT "@PKG_SYSCONFBASE@/incron.conf"
 
 
 typedef std::map<std::string, std::string> CFG_MAP;
@@ -37,11 +37,11 @@ CFG_MAP IncronCfg::m_defaults;
 
 void IncronCfg::Init()
 {
-  m_defaults.insert(CFG_MAP::value_type("system_table_dir", "/etc/incron.d"));
-  m_defaults.insert(CFG_MAP::value_type("user_table_dir", "/var/spool/incron"));
-  m_defaults.insert(CFG_MAP::value_type("allowed_users", "/etc/incron.allow"));
-  m_defaults.insert(CFG_MAP::value_type("denied_users", "/etc/incron.deny"));
-  m_defaults.insert(CFG_MAP::value_type("lockfile_dir", "/var/run"));
+  m_defaults.insert(CFG_MAP::value_type("system_table_dir", "@PKG_SYSCONFBASE@/incron.d"));
+  m_defaults.insert(CFG_MAP::value_type("user_table_dir", "@VARBASE@/spool/incron"));
+  m_defaults.insert(CFG_MAP::value_type("allowed_users", "@PKG_SYSCONFBASE@/incron.allow"));
+  m_defaults.insert(CFG_MAP::value_type("denied_users", "@PKG_SYSCONFBASE@/incron.deny"));
+  m_defaults.insert(CFG_MAP::value_type("lockfile_dir", "@VARBASE@/run"));
   m_defaults.insert(CFG_MAP::value_type("lockfile_name", "incrond"));
   m_defaults.insert(CFG_MAP::value_type("editor", ""));
 }
