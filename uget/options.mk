# $NetBSD: options.mk,v 1.1 2013/03/03 17:55:48 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uget
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS+=	nls
PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
USE_TOOLS+=		gmake
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
