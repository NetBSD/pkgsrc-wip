$NetBSD: patch-chrome_browser_history_in__memory__url__index.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- chrome/browser/history/in_memory_url_index.cc.orig	2011-05-24 08:01:42.000000000 +0000
+++ chrome/browser/history/in_memory_url_index.cc
@@ -864,8 +864,8 @@ bool InMemoryURLIndex::RestoreWordIDHist
       return false;
     WordID word_id = iter->word_id();
     HistoryIDSet history_id_set;
-    const RepeatedField<int64>& history_ids(iter->history_id());
-    for (RepeatedField<int64>::const_iterator jiter = history_ids.begin();
+    const RepeatedField<int64_t>& history_ids(iter->history_id());
+    for (RepeatedField<int64_t>::const_iterator jiter = history_ids.begin();
          jiter != history_ids.end(); ++jiter)
       history_id_set.insert(*jiter);
     word_id_history_map_[word_id] = history_id_set;
