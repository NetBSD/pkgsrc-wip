# $NetBSD: options.mk,v 1.2 2013/06/20 07:25:59 yvs4sf Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mtr
PKG_SUPPORTED_OPTIONS=		gtk
PKG_SUPPORTED_OPTIONS+=		inet6
PKG_SUGGESTED_OPTIONS=		inet6
#PKG_SUPPORTED_OPTIONS+=	ipinfo
#PKG_SUGGESTED_OPTIONS+=	ipinfo

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
USE_TOOLS+=		pkg-config
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

#.if empty(PKG_OPTIONS:Mipinfo)
#CONFIGURE_ARGS+=	--without-ipinfo
#.endif
