# $NetBSD: options.mk,v 1.4 2014/05/22 21:41:48 szptvlfn Exp $

PKG_OPTIONS_VAR=    PKG_OPTIONS.xmonad-contrib
PKG_SUPPORTED_OPTIONS= xft2
PKG_SUGGESTED_OPTIONS= xft2

.include "../../mk/bsd.options.mk"

USE_TOOLS+=	patch

.if !empty(PKG_OPTIONS:Mxft2)
.include "../../x11/hs-X11-xft/buildlink3.mk"
.else
post-configure:
	${RUN} cd ${WRKSRC} && \
		${PATCH} <../../files/no_use_xft
.endif
