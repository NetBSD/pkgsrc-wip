$NetBSD$

--- report.c.orig	2018-08-08 23:14:18.000000000 +0000
+++ report.c
@@ -97,21 +97,31 @@ void report_Report(run_t* run) {
         " externalCmd     : %s\n"
         " fuzzStdin       : %s\n"
         " timeout         : %ld (sec)\n"
+#if defined(_HF_ARCH_LINUX)
         " ignoreAddr      : %p\n"
+#endif
         " ASLimit         : %" PRIu64
         " (MiB)\n"
         " RSSLimit        : %" PRIu64
         " (MiB)\n"
         " DATALimit       : %" PRIu64
         " (MiB)\n"
+#if defined(_HF_ARCH_LINUX)
         " targetPid       : %d\n"
         " targetCmd       : %s\n"
+#endif
         " wordlistFile    : %s\n",
         localtmstr, run->global->mutate.mutationsPerRun,
         run->global->exe.externalCommand == NULL ? "NULL" : run->global->exe.externalCommand,
         run->global->exe.fuzzStdin ? "TRUE" : "FALSE", run->global->timing.tmOut,
-        run->global->linux.ignoreAddr, run->global->exe.asLimit, run->global->exe.rssLimit,
-        run->global->exe.dataLimit, run->global->linux.pid, run->global->linux.pidCmd,
+#if defined(_HF_ARCH_LINUX)
+        run->global->linux.ignoreAddr,
+#endif
+	run->global->exe.asLimit, run->global->exe.rssLimit,
+        run->global->exe.dataLimit,
+#if defined(_HF_ARCH_LINUX)
+        run->global->linux.pid, run->global->linux.pidCmd,
+#endif
         run->global->mutate.dictionaryFile == NULL ? "NULL" : run->global->mutate.dictionaryFile);
 
 #if defined(_HF_ARCH_LINUX)
