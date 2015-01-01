# $NetBSD: options.mk,v 1.1 2015/01/01 08:12:48 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.eog
PKG_SUPPORTED_OPTIONS=	dbus jpeg lcms python
PKG_SUGGESTED_OPTIONS=	dbus jpeg lcms python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
CONFIGURE_ARGS+=	--with-libjpeg
.else
CONFIGURE_ARGS+=	--without-libjpeg
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dbus
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

.if !empty(PKG_OPTIONS:Mlcms)
.include "../../graphics/lcms2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cms
.else
CONFIGURE_ARGS+=	--without-cms
.endif

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-python
.else
CONFIGURE_ARGS+=	--disable-python
.endif
