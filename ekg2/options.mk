# $NetBSD: options.mk,v 1.2 2009/09/20 22:05:14 shindenmorr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ekg2
PKG_SUPPORTED_OPTIONS=	libgadu jabber
PKG_SUGGESTED_OPTIONS=	libgadu jabber

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjabber)
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
PLIST.jabber=	yes
.endif

.if !empty(PKG_OPTIONS:Mlibgadu)
.include "../../wip/libgadu/buildlink3.mk"
PLIST.gg+=	yes
.endif
