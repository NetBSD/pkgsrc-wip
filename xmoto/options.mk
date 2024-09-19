# $NetBSD: options.mk,v 1.1 2014/08/09 18:33:51 nros Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmoto
PKG_SUPPORTED_OPTIONS=	nls
PLIST_VARS+=		nls
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=		msgfmt
PLIST.NLS=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
