$NetBSD: patch-lily_volta-repeat-iterator.cc,v 1.1 2013/11/13 07:26:35 thomasklausner Exp $

--- lily/volta-repeat-iterator.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/volta-repeat-iterator.cc
@@ -103,7 +103,7 @@ Volta_repeat_iterator::next_element (boo
     {
       if (alt_count_)
         {
-          string repstr = to_string (rep_count_ - alt_count_ + done_count_) + ".";
+          string repstr = ::to_string (rep_count_ - alt_count_ + done_count_) + ".";
           if (done_count_ <= 1)
             {
               alt_restores_ = SCM_EOL;
@@ -142,7 +142,7 @@ Volta_repeat_iterator::next_element (boo
             }
 
           if (done_count_ == 1 && alt_count_ < rep_count_)
-            repstr = "1.--" + to_string (rep_count_ - alt_count_ + done_count_) + ".";
+            repstr = "1.--" + ::to_string (rep_count_ - alt_count_ + done_count_) + ".";
 
           if (done_count_ <= alt_count_)
             add_repeat_command (scm_list_n (ly_symbol2scm ("volta"),
