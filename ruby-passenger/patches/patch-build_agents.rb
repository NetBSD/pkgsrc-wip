$NetBSD: patch-build_agents.rb,v 1.1 2015/04/02 15:40:14 fhajny Exp $

Add a simple target to skip the Apache/Nginx binaries.
--- build/agents.rb.orig	2013-10-26 22:00:00.000000000 +0000
+++ build/agents.rb
@@ -169,3 +169,9 @@ end
 task 'common:clean' do
   sh "rm -rf #{AGENT_OUTPUT_DIR}"
 end
+
+desc "Build just the agents"
+task :agents => [
+  AGENT_OUTPUT_DIR + AGENT_EXE,
+  :native_support
+]
