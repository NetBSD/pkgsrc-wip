# $NetBSD: options.mk,v 1.1 2012/09/22 16:45:49 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pcsxr
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls
PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=	yes
.endif
