$NetBSD$

The paths of cross tools are not in PATH.
The clang binary is actually a link provided by cwrappers and can maybe not
accept the '-target' argument option.

--- tools/winebuild/utils.c.orig	2024-11-05 15:46:16.161936319 +0000
+++ tools/winebuild/utils.c
@@ -129,6 +129,8 @@ static struct strarray get_tools_path(vo
     {
         strarray_addall( &dirs, tools_path );
         strarray_addall( &dirs, strarray_frompath( getenv( "PATH" )));
+	strarray_add( &dirs, "@MINGW32_32_PATH@" );
+	strarray_add( &dirs, "@MINGW32_64_PATH@" );
         done = 1;
     }
     return dirs;
@@ -299,16 +301,6 @@ struct strarray get_as_command(void)
     {
         strarray_add( &args, file );
     }
-    else if ((file = find_binary( NULL, "clang" )))
-    {
-        strarray_add( &args, file );
-        if (target_alias)
-        {
-            strarray_add( &args, "-target" );
-            strarray_add( &args, target_alias );
-        }
-        using_cc = 1;
-    }
 
     if (using_cc)
     {
