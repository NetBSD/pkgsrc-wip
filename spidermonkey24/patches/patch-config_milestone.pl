$NetBSD$

Use of defined() for array is deprecated.

--- config/milestone.pl.orig	2013-11-19 19:42:43.000000000 +0000
+++ config/milestone.pl
@@ -56,7 +56,7 @@ $MILESTONE_FILE  = "$TOPSRCDIR/config/mi
 #
 my $milestone = Moz::Milestone::getOfficialMilestone($MILESTONE_FILE);
 
-if (defined(@TEMPLATE_FILE)) {
+if (@TEMPLATE_FILE) {
   my $TFILE;
 
   foreach $TFILE (@TEMPLATE_FILE) {
