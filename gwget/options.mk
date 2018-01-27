# $NetBSD: options.mk,v 1.1.1.1 2010/03/19 19:40:00 jihbed Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.gwget
PKG_SUPPORTED_OPTIONS=		libnotify epiphany-extension epiphany-version
PKG_SUGGESTED_OPTIONS=		libnotify epiphany-extension epiphany-version

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mepiphany-extension)
DEPENDS+=		epiphany-extensions>=2.28.1:../../www/epiphany-extensions
CONFIGURE_ARGS+=	--enable-epiphany-extension
.endif

.if !empty(PKG_OPTIONS:Mepiphany-version)
CONFIGURE_ARGS+=	--with-epiphany-version
.  include "../../www/epiphany/buildlink3.mk"
.endif

.if !empty (PKG_OPTIONS:Mlibnotify)
BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.3.2
.  include "../../sysutils/libnotify/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libnotify
.endif
