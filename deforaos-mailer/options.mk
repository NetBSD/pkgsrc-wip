# $NetBSD: options.mk,v 1.2 2012/12/26 17:02:47 khorben Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.deforaos-mailer
PKG_SUPPORTED_OPTIONS=	embedded

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded)
MAKE_FLAGS+=	CPPFLAGS=-DEMBEDDED
.endif
