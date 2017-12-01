# $NetBSD: options.mk,v 1.5 2017/04/12 13:03:08 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mupdf
PKG_SUPPORTED_OPTIONS=	curl opengl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		opengl

#
# curl support
#
.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.else
MAKE_ENV+=	HAVE_CURL=no
.endif

#
# glut support
#
.if !empty(PKG_OPTIONS:Mopengl)
PLIST.opengl=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.else
MAKE_ENV+=	HAVE_GLUT=no
.endif
