$NetBSD$

--- lib/utils/mu-readline.cc.orig	2024-04-24 01:19:02.086438386 +0000
+++ lib/utils/mu-readline.cc
@@ -73,7 +73,11 @@ Mu::have_readline()
 void
 Mu::setup_readline(const std::string& histpath, size_t maxlines)
 {
+#if defined(__NetBSD__)
+	is_a_tty  = 1;
+#else
 	is_a_tty  = !!::isatty(::fileno(stdout));
+#endif
 	hist_path = histpath;
 	max_lines = maxlines;
 
