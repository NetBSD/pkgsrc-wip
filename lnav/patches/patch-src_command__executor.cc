$NetBSD: patch-src_command__executor.cc,v 1.1 2023/05/24 22:42:53 he Exp $

Allow time_t to be long long, and adapt formats and casts accordingly.
Also, cast a size_t before printing; unknown size so difficult to match
format appropriately.

--- src/command_executor.cc.orig	2025-02-12 19:26:00.000000000 +0000
+++ src/command_executor.cc
@@ -541,10 +541,10 @@ execute_sql(exec_context& ec, const std:
                     snprintf(row_count_buf,
                              sizeof(row_count_buf),
                              ANSI_BOLD("%'d") " row%s matched in " ANSI_BOLD(
-                                 "%ld.%03ld") " seconds",
+                                 "%lld.%03ld") " seconds",
                              row_count,
                              row_count == 1 ? "" : "s",
-                             diff_tv.tv_sec,
+                             (long long)diff_tv.tv_sec,
                              std::max((long) diff_tv.tv_usec / 1000, 1L));
                     retval = row_count_buf;
                     if (dls.has_log_time_column()) {
