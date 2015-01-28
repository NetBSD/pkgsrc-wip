--- PerlLib/HTC/SLURM_handler.pm.orig	2014-08-15 08:34:45.000000000 -0500
+++ PerlLib/HTC/SLURM_handler.pm	2014-08-15 08:35:47.000000000 -0500
--- PerlLib/HTC/SLURM_handler.pm.orig	2014-04-23 15:59:17.000000000 +0000
+++ PerlLib/HTC/SLURM_handler.pm
@@ -42,6 +42,7 @@ sub submit_job_to_grid {
     
     $cmd .= " $shell_script 2>&1 ";
         
+    print STDERR "\nExecuting $cmd\n";
 
     my $job_id_text = `$cmd`;
     
