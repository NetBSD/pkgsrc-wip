$NetBSD$

Do not install MPI support.

--- src/Build.PL.orig	2017-10-17 19:27:18.000000000 +0000
+++ src/Build.PL
@@ -128,9 +128,7 @@ if(my $any = $build->args('AnyDBM_ISA'))
 }
 
 #ask for MPI
-my $go = $build->y_n("\nMAKER supports distributed parallelization via MPI.\n".
-		     "Would you like to configure MAKER for MPI (This\n".
-		     "requires that you have an MPI client installed)?", 'N');
+my $go = 0;
 $build->feature(mpi_support => $go);
 $build->config_mpi() if($go);
 
