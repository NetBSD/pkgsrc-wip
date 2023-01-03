$NetBSD$

--- dtools/xtmDbTools.c.orig	1997-05-04 22:27:52.000000000 +0000
+++ dtools/xtmDbTools.c
@@ -1813,7 +1813,7 @@ XTM_DB_STATUS
 
     /* Insert the date in the sorted list. */
     lst_status = LstLinkSearchFirst( *list_ref, 
-                                     (void *) record.date,
+                                     (void *)(uintptr_t)record.date,
                                      (EQUALS_FUNC_TYPE) dateSortFunc );
 
     if( lst_status == LST_OK )
@@ -1896,7 +1896,7 @@ XTM_DB_STATUS
           case XTM_DB_DAY_NOTE:
             lst_status = LstLinkSearchFirst( 
                            *note_list_ref, 
-                           (void *) entry_record.entry.time_stamp,
+                           (void *)(uintptr_t)entry_record.entry.time_stamp,
                            (EQUALS_FUNC_TYPE) entryIdSortFunc );
 
             if( lst_status == LST_OK )
@@ -1910,7 +1910,7 @@ XTM_DB_STATUS
           case XTM_DB_DAY_ENTRY:
             lst_status = LstLinkSearchFirst( 
                            *entry_list_ref, 
-                           (void *) entry_record.entry.time_stamp,
+                           (void *)(uintptr_t)entry_record.entry.time_stamp,
                            (EQUALS_FUNC_TYPE) entryTimeSortFunc );
 
             if( lst_status == LST_OK )
@@ -1984,7 +1984,7 @@ XTM_DB_STATUS
         case XTM_DB_DAY_NOTE:
           lst_status = LstLinkSearchFirst( 
                          *note_list_ref, 
-                         (void *) entry_record.entry.time_stamp,
+                         (void *)(uintptr_t)entry_record.entry.time_stamp,
                          (EQUALS_FUNC_TYPE) entryIdSortFunc );
 
           if( lst_status == LST_OK )
@@ -1998,7 +1998,7 @@ XTM_DB_STATUS
         case XTM_DB_DAY_ENTRY:
           lst_status = LstLinkSearchFirst( 
                          *entry_list_ref, 
-                         (void *) entry_record.entry.time_stamp,
+                         (void *)(uintptr_t)entry_record.entry.time_stamp,
                          (EQUALS_FUNC_TYPE) entryTimeSortFunc );
 
           if( lst_status == LST_OK )
@@ -2072,7 +2072,7 @@ XTM_DB_STATUS
       case XTM_DB_DAY_NOTE:
         lst_status = LstLinkSearchFirst( 
                        *note_list_ref, 
-                       (void *) entry_record.entry.time_stamp,
+                       (void *)(uintptr_t)entry_record.entry.time_stamp,
                        (EQUALS_FUNC_TYPE) entryIdSortFunc );
 
         if( lst_status == LST_OK )
@@ -2086,7 +2086,7 @@ XTM_DB_STATUS
       case XTM_DB_DAY_ENTRY:
         lst_status = LstLinkSearchFirst( 
                        *entry_list_ref, 
-                       (void *) entry_record.entry.time_stamp,
+                       (void *)(uintptr_t)entry_record.entry.time_stamp,
                        (EQUALS_FUNC_TYPE) entryTimeSortFunc );
 
         if( lst_status == LST_OK )
