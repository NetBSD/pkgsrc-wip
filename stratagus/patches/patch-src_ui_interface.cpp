# $NetBSD$

Don't assume that we've enabled OpenGL support.

--- ./src/ui/interface.cpp.orig	2019-07-06 12:41:25.523375960 -0700
+++ ./src/ui/interface.cpp	2019-07-06 12:42:09.515534108 -0700
@@ -733,11 +733,13 @@
 		case SDLK_SLASH:
 		case SDLK_BACKSLASH:
 			if (KeyModifiers & ModifierAlt) {
+#if defined(USE_OPENGL) || defined(USE_GLES)
 				if (GLShaderPipelineSupported) {
 					char shadername[1024] = { '\0' };
 					LoadShaders(key == SDLK_SLASH ? 1 : -1, shadername);
 					SetMessage("%s", shadername);
 				}
+#endif
 			}
 			break;
 
