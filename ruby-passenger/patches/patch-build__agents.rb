$NetBSD: patch-build__agents.rb,v 1.3 2014/05/06 13:40:31 fhajny Exp $

Add a simple target to skip the Apache/Nginx binaries.
--- build/agents.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ build/agents.rb
@@ -184,3 +184,13 @@ end
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
