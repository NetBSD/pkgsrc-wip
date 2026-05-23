$NetBSD$

NetBSD df does not accept -P (POSIX output format, GNU-specific).
Drop it so the dashboard disk-space panel works.

--- crates/fresh-editor/plugins/dashboard.ts.orig
+++ crates/fresh-editor/plugins/dashboard.ts
@@ -1408,7 +1408,7 @@
     const rows: { mount: string; pct: number; used: string; size: string }[] = [];
     try {
         for (const m of mounts) {
-            const { stdout, ok } = await run("df", ["-hP", m], "", 3000);
+            const { stdout, ok } = await run("df", ["-h", m], "", 3000);
             if (!ok) continue;
             const lns = stdout.split("\n").filter((l) => l.length > 0);
             if (lns.length < 2) continue;
