# $NetBSD: options.mk,v 1.2 2008/12/04 21:44:28 leot1990 Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.dwm
PKG_SUPPORTED_OPTIONS=		xinerama

.include "../../mk/bsd.options.mk"

# If we don't want the Xinerama support we delete XINERAMALIBS and
# XINERAMAFLAGS lines, otherwise the Xinerama support is the default.
.if !empty(PKG_OPTIONS:Mxinerama)
SUBST_CLASSES+=		options
SUBST_STAGE.options=	pre-build
SUBST_MESSAGE.options=	Toggle the Xinerama support
SUBST_FILES.options=	config.mk
SUBST_SED.options+=	-e '/XINERAMA/ s/^\#//'
.  include "../../x11/libXinerama/buildlink3.mk"
.else
.  include "../../x11/libX11/buildlink3.mk"
.endif
