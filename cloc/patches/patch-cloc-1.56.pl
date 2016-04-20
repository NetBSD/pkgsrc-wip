$NetBSD$

--- cloc-1.56.pl.orig	2016-04-20 15:59:30.000000000 +0000
+++ cloc-1.56.pl
@@ -1051,8 +1051,8 @@ foreach (my $F = 0; $F < scalar @fh - 1;
             $Ignored{$file_R} = "--exclude-lang=$Lang_R}";
             next;
         }
-        if (!defined @{$Filters_by_Language{$Lang_L} } or
-            !defined @{$Filters_by_Language{$Lang_R} }
+        if (!defined {$Filters_by_Language{$Lang_L} } or
+            !defined {$Filters_by_Language{$Lang_R} }
            ) {
             if (($Lang_L eq "(unknown)") or ($Lang_R eq "(unknown)")) {
                 $Ignored{$fh[$F  ]}{$file_L} = "language unknown (#1)";
@@ -1376,7 +1376,7 @@ foreach my $file (sort keys %unique_sour
         $Ignored{$file} = "--exclude-lang=$Language{$file}";
         next;
     }
-    if (!defined @{$Filters_by_Language{$Language{$file}} }) {
+    if (!defined {$Filters_by_Language{$Language{$file}} }) {
         if ($Language{$file} eq "(unknown)") {
             $Ignored{$file} = "language unknown (#1)";
         } else {
@@ -1507,7 +1507,7 @@ sub combine_results {                   
                    )?
                    $}x) {
                 if ($report_type eq "by language") {
-                    next unless defined @{$rhaa_Filters_by_Language->{$1}};
+                    next unless defined {$rhaa_Filters_by_Language->{$1}};
                     # above test necessary to avoid trying to sum reports
                     # of reports (which have no language breakdown).
                     $found_language = 1;
