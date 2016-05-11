$NetBSD$

# Patch for SLURM plugin
--- PerlLib/HPC/SLURM_handler.pm.orig	2016-01-28 15:46:19.663726750 +0000
+++ PerlLib/HPC/SLURM_handler.pm
@@ -41,11 +41,12 @@ sub submit_job_to_grid {
      ##with SLURM max expected running time should preferably be specified, otherwise the scheduler will assume default value for the partition; structure is days-hours:minutes:seconds like so 1-02:30:00  
     
     $cmd .= " $shell_script 2>&1 ";
+    print STDERR "\nExecuting $cmd\n";
         
 
     my $job_id_text = `$cmd`;
     
-    # print STDERR "\n$job_id_text\n";
+    print STDERR "\n$job_id_text\n";
     
     my $ret = $?;
     
@@ -82,7 +83,7 @@ sub job_running_or_pending_on_grid {
         confess "Error, need job ID as parameter";
     }
     
-    # print STDERR "Polling grid to check status of job: $job_id\n";
+    print STDERR "Polling grid to check status of job: $job_id\n";
     
     my $response = `sacct -j $job_id`;
     #print STDERR "Response:\n$response\n";
