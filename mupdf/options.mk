# $NetBSD: options.mk,v 1.2 2013/10/26 22:26:29 leot1990 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mupdf
PKG_SUPPORTED_OPTIONS=	curl

.include "../../mk/bsd.options.mk"

#
# curl support
#
.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.else
MAKE_FLAGS+=	NOCURL=yes
.endif
