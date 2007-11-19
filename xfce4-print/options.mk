# $NetBSD: options.mk,v 1.2 2007/11/19 14:18:10 marttikuparinen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-print
PKG_SUPPORTED_OPTIONS=	cups

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
PLIST_SUBST+=		CUPS=
.else
CONFIGURE_ARGS+=	--disable-cups
PLIST_SUBST+=		CUPS="@comment "
.endif
