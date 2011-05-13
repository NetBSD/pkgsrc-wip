# $NetBSD: options.mk,v 1.1 2011/05/13 23:25:16 mwdavies Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdeutils
PKG_SUPPORTED_OPTIONS=	cups
PKG_SUGGESTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/py-cups/buildlink3.mk"
PLIST.cups=		yes
.endif
