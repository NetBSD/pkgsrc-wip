$NetBSD$

Workaround for terminal background query hang on NetBSD.
Change default theme from "auto" to "dark" to avoid OSC 11 query
that can block indefinitely when terminal doesn't respond properly.

--- src/main.rs.orig	2025-05-14 03:25:00.000000000 +0000
+++ src/main.rs
@@ -59,7 +59,7 @@ struct Cli {
     no_images: bool,

     /// Force syntax highlight theme background (light or dark)
-    #[arg(long, value_enum, default_value = "auto")]
+    #[arg(long, value_enum, default_value = "dark")]
     theme: ThemeMode,

     /// Enable startup performance logging
