$NetBSD$

--- game/anim/Anim_Blend.cpp.orig	2019-02-02 17:51:30.000000000 +0000
+++ game/anim/Anim_Blend.cpp
@@ -3666,11 +3666,7 @@ bool idDeclModelDef::Parse( const char *
 			}
 
 			for( i = ANIMCHANNEL_ALL + 1; i < ANIM_NumAnimChannels; i++ ) {
-#if MACOS_X || __linux__
 				if ( !strcasecmp( channelNames[ i ], token2.c_str() ) )
-#else
-				if ( !stricmp( channelNames[ i ], token2.c_str() ) )
-#endif
 				{
 					break;
 				}
