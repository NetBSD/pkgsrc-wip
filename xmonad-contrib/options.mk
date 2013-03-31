# $NetBSD: options.mk,v 1.2 2013/03/31 00:59:49 szptvlfn Exp $

PKG_OPTIONS_VAR=    PKG_OPTIONS.xmonad-contrib
PKG_SUPPORTED_OPTIONS= xft2
PKG_SUGGESTED_OPTIONS= xft2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxft2)
.include "../../wip/hs-x11-xft/buildlink3.mk"
.else
post-configure:
	${RUN} cd ${WRKSRC} && \
		${PATCH} <../../files/no_use_xft
.endif
