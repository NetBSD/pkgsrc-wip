$NetBSD: patch-build__agents.rb,v 1.4 2014/10/29 12:59:17 fhajny Exp $

Add a simple target to skip the Apache/Nginx binaries.
--- build/agents.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ build/agents.rb
@@ -188,3 +188,13 @@ end
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
