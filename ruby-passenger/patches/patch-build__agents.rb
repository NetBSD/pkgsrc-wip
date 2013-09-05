$NetBSD: patch-build__agents.rb,v 1.2 2013/09/05 10:55:51 fhajny Exp $

Add a simple target to skip the Apache/Nginx binaries.
--- build/agents.rb.orig	2013-08-27 13:09:37.803991263 +0000
+++ build/agents.rb
@@ -179,3 +179,13 @@ end
 task 'common:clean' do
 	sh "rm -rf #{AGENT_OUTPUT_DIR}"
 end
+
+desc "Build just the agents"
+task :agents => [
+	AGENT_OUTPUT_DIR + 'PassengerHelperAgent',
+	AGENT_OUTPUT_DIR + 'PassengerLoggingAgent',
+	AGENT_OUTPUT_DIR + 'PassengerWatchdog',
+	AGENT_OUTPUT_DIR + 'SpawnPreparer',
+	AGENT_OUTPUT_DIR + 'EnvPrinter',
+	:native_support
+]
