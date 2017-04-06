$NetBSD$

--- source/Host/netbsd/Host.cpp.orig	2017-03-30 22:14:30.000000000 +0000
+++ source/Host/netbsd/Host.cpp
@@ -52,15 +52,12 @@ using namespace lldb;
 using namespace lldb_private;
 
 size_t Host::GetEnvironment(StringList &env) {
-  char *v;
-  char **var = environ;
-  for (; var != NULL && *var != NULL; ++var) {
-    v = ::strchr(*var, (int)'-');
-    if (v == NULL)
-      continue;
-    env.AppendString(v);
-  }
-  return env.GetSize();
+  char **host_env = environ;
+  char *env_entry;
+  size_t i;
+  for (i = 0; (env_entry = host_env[i]) != NULL; ++i)
+    env.AppendString(env_entry);
+  return i;
 }
 
 static bool GetNetBSDProcessArgs(const ProcessInstanceInfoMatch *match_info_ptr,
