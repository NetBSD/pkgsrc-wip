# $NetBSD: options.mk,v 1.1 2012/10/29 04:41:12 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.piedock
PKG_SUPPORTED_OPTIONS=	gtk kde
PKG_SUGGESTED_OPTIONS+=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-gtk
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if !empty(PKG_OPTIONS:Mkde)
CONFIGURE_ARGS+=	--enable-kde
.include "../../x11/kdelibs4/buildlink3.mk" # XXX Is it KDE3 or KDE4
.else
CONFIGURE_ARGS+=	--disable-kde
.endif
