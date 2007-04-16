# $NetBSD: options.mk,v 1.1.1.1 2007/04/16 19:00:24 shindenmorr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ekg2
PKG_SUPPORTED_OPTIONS=	libgadu jabber
PKG_SUGGESTED_OPTIONS=	libgadu jabber

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjabber)
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
PLIST_SUBST+=	JABBER=""
.else
PLIST_SUBST+=	JABBER="@comment "
.endif

.if !empty(PKG_OPTIONS:Mlibgadu)
.include "../../wip/libgadu/buildlink3.mk"
PLIST_SUBST+=	GG=""
.else
PLIST_SUBST+=	GG="@comment "
.endif
