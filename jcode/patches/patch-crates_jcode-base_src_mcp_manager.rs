$NetBSD$

Spawn the test MCP server with /bin/sh rather than /bin/bash.

bash is a pkgsrc package on NetBSD and lives in ${PREFIX}/bin, so the
hardcoded shebang made the test fail to spawn. The script uses no bashisms.

--- crates/jcode-base/src/mcp/manager.rs.orig
+++ crates/jcode-base/src/mcp/manager.rs
@@ -623,7 +623,10 @@ mod provenance_integration_tests {
     /// initialize, tools/list, and tools/call with canned JSON-RPC replies.
     fn write_fake_mcp_server(dir: &std::path::Path) -> std::path::PathBuf {
         let path = dir.join("fake-mcp-server.sh");
-        let script = r##"#!/bin/bash
+        // POSIX sh, not bash: the script below uses no bashisms, and /bin/bash
+        // does not exist on every unix (on NetBSD bash lives in pkgsrc under
+        // /usr/pkg/bin), which made this test fail to spawn the server.
+        let script = r##"#!/bin/sh
 while IFS= read -r line; do
   id=$(echo "$line" | grep -o '"id":[0-9]*' | grep -o '[0-9]*' | head -1)
   case "$line" in
