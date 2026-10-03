$NetBSD$

Avoid re-parsing every task file on each idle claim poll. When queue.json
is empty there is nothing to claim, so check it first and skip the full
load_state, which reads and serde-parses all historical task files (finished
or not). Idle CPU previously scaled with total task-store bytes x workers x 5 Hz.

--- crates/tui/src/task_manager.rs.orig
+++ crates/tui/src/task_manager.rs
@@ -2188,6 +2188,12 @@
     async fn claim_next_task(&self) -> Result<Option<(String, ExecutionTask, CancellationToken)>> {
         let mut state = self.state.lock().await;
         let _transaction = self.lock_store().await?;
+        // Cheap idle-poll fast path: when the queue is empty there is nothing to
+        // claim, so skip the full task-store reload (which re-parses every task
+        // file, finished or not) and return immediately.
+        if self.queue_on_disk_is_empty()? {
+            return Ok(None);
+        }
         self.refresh_locked(&mut state)?;
         if self.cancel_token.is_cancelled() {
             return Ok(None);
@@ -2969,6 +2975,22 @@
             sleep(wait).await;
             wait = (wait * 2).min(Duration::from_millis(50));
         }
+    }
+
+    /// Whether `queue.json` holds no queued tasks.
+    ///
+    /// The idle claim poll calls this before `refresh_locked` so an empty queue
+    /// skips the full task-store reload. Reading and parsing only `queue.json`
+    /// is O(queue size), not O(all historical task bytes).
+    fn queue_on_disk_is_empty(&self) -> Result<bool> {
+        if !self.queue_path.exists() {
+            return Ok(true);
+        }
+        let content = fs::read_to_string(&self.queue_path)
+            .with_context(|| format!("Failed to read queue file {}", self.queue_path.display()))?;
+        let parsed: QueueFile = serde_json::from_str(&content)
+            .with_context(|| format!("Failed to parse queue file {}", self.queue_path.display()))?;
+        Ok(parsed.queue.is_empty())
     }
 
     fn refresh_locked(&self, state: &mut ManagerState) -> Result<()> {
