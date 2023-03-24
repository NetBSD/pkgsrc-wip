$NetBSD$

Add support for UMAPINFO.

--- src/m_menu.c.orig	2023-02-26 17:42:09.000000000 +0000
+++ src/m_menu.c
@@ -6300,6 +6300,83 @@ void M_Init (void)
     CV_RegisterVar(&cv_oof_2s);
 }
 
+
+// [MB] 2023-03-23: Modify episode menu with data from UMAPINFO
+// If clear is false, the new entries are appended to the existing menu
+static void M_EpisodeMenuFromUMAPINFO (void)
+{
+    boolean   modified = false;
+    emenu_t * episode  = umapinfo.emenu;
+
+    // Accept clear only for the first UMAPINFO map entry
+    if( umapinfo.emenu_clear )
+    {
+        modified        = true;
+        EpiDef.numitems = 0;
+        GenPrintf(EMSG_debug, "UMAPINFO: Default episode menu cleared\n");
+    }
+
+    while( episode )
+    {
+        // UMAPINFO allows 8 episodes, currently only 5 are supported
+        if( EpiDef.numitems < 5 )
+        {
+            // EpisodeMenu[EpiDef.numitems].status is below
+            // FIXME: Cast to char* is ugly
+            // Is it possible to declared elements const in menuitem_t?
+            EpisodeMenu[EpiDef.numitems].patch = (char*)episode->patch;
+            EpisodeMenu[EpiDef.numitems].text  = (char*)episode->name;
+            // EpisodeMenu[EpiDef.numitems].itemaction is not changed
+            if( episode->key[0] )
+            {
+                // UMAPINFO value is defined as quoted string
+                // The first character is used, if string is not empty
+                byte k = (byte)episode->key[0];
+
+                EpisodeMenu[EpiDef.numitems].alphaKey = k;
+            }
+            EpiDef.numitems++;
+            GenPrintf(EMSG_debug, "UMAPINFO: Episode entry added\n");
+        }
+        modified = true;
+        episode  = episode->next;
+    }
+
+    // Use patches only if all episodes have a valid patch
+    if( modified )
+    {
+        boolean  use_patches = true;
+        uint16_t i;
+
+        // FIXME: This should check if the patches are valid too
+        for( i = 0; i < EpiDef.numitems; i++ )
+            if( EpisodeMenu[i].patch == NULL )
+                use_patches = false;
+
+        GenPrintf(EMSG_debug, "UMAPINFO: Modified episode menu ");
+        if( use_patches )
+            GenPrintf(EMSG_debug, "(using patches):\n");
+        else
+            GenPrintf(EMSG_debug, "(using strings):\n");
+
+        for( i = 0; i < EpiDef.numitems; i++ )
+        {
+            GenPrintf(EMSG_debug, "    Episode %u: ", (unsigned int) i + 1u);
+            if( use_patches )
+                GenPrintf(EMSG_debug, "%s\n", EpisodeMenu[i].patch);
+            else
+                GenPrintf(EMSG_debug, "%s\n", EpisodeMenu[i].text);
+
+            EpisodeMenu[i].status = IT_CALL;
+            if( use_patches )
+                EpisodeMenu[i].status |= IT_PATCH;
+            else
+                EpisodeMenu[i].status |= IT_STRING2;
+        }
+    }
+}
+
+
 // Called once after gamemode has been determined, game dependent
 void M_Configure (void)
 {
@@ -6382,6 +6459,9 @@ void M_Configure (void)
           cv_nextmap.defaultvalue = "11";
           // We need to remove the fifth episode.
           EpiDef.numitems--;
+
+          // [MB] 2023-03-23: Support for UMAPINFO added
+          M_EpisodeMenuFromUMAPINFO();
           break;
       case heretic:
           cv_nextmap.PossibleValue = exmy_cons_t;
