# $NetBSD: options.mk,v 1.4 2010/03/14 23:06:04 shindenmorr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ekg2
PKG_SUPPORTED_OPTIONS=	gg jabber
PKG_SUGGESTED_OPTIONS=	gg jabber
PLIST_VARS+=		gg jabber

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjabber)
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
CONFIGURE_ARGS+=	--with-expat
PLIST.jabber=	yes
.else
CONFIGURE_ARGS+=	--without-expat
.endif

.if !empty(PKG_OPTIONS:Mgg)
.include "../../wip/libgadu/buildlink3.mk"
PLIST.gg=	yes
.endif
