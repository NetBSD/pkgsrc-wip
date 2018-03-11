$NetBSD$

We dont have Linux::Pid currently.

--- Makefile.PL.orig	2018-03-05 00:05:54.000000000 +0000
+++ Makefile.PL
@@ -202,10 +202,6 @@ my %optional_features = (
         },
         description => 'Move Bugs Between Installations'
     },
-    oracle => {
-        description => 'Oracle database support',
-        prereqs => { runtime => { requires => { 'DBD::Oracle' => '1.19' } } }
-    },
     s3 => {
         description => 'Amazon S3 Attachment Storage',
         prereqs => {
@@ -239,7 +235,7 @@ my %optional_features = (
         description => 'JSON-RPC Interface',
         prereqs     => {
             runtime =>
-                { requires => { 'JSON::RPC' => '== 1.01', 'Test::Taint' => '1.06' } }
+                { requires => { 'JSON::RPC' => '1.01', 'Test::Taint' => '1.06' } }
         }
     },
     graphical_reports => {
@@ -298,19 +294,11 @@ my %optional_features = (
             runtime => {
                 requires => {
                     'Test::Taint' => '1.06',
-                    'JSON::RPC' => '==1.01',
+                    'JSON::RPC' => '1.01',
                 }
             }
         }
     },
-    linux_pid => {
-        description => 'Linux::PID for MozReview',
-        prereqs => {
-            runtime => {
-                requires => { 'Linux::Pid' => 0 },
-            },
-        },
-    },
     jobqueue => {
         description => 'Mail Queueing',
         prereqs     => {
@@ -391,14 +379,12 @@ my @bmo_features = grep {
     !m{
         ^
         (?: pg
-          | oracle
           | mod_perl
           | psgi
           | sqlite
           | auth_ldap
           | auth_radius
           | smtp_auth
-          | linux_pid
           | updates)
         $
     }mxs;
