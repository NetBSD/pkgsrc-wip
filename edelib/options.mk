# $NetBSD: options.mk,v 1.1 2010/06/01 19:24:22 christtrekker Exp $

.if !empty(PKG_OPTIONS:Mdbus)
.  include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mfam) || !empty(PKG_OPTIONS:Mfam-only)
.  include "../../mk/fam.buildlink3.mk"
.  if !empty(PKG_OPTIONS:Mfam-only)
CONFIGURE_ARGS+=	--enable-fam-only
.  else
CONFIGURE_ARGS+=	--disable-fam-only
.  endif
.endif

.if !empty(PKG_OPTIONS:Mlargefile)
CONFIGURE_ARGS+=	--enable-largefile
.else
CONFIGURE_ARGS+=	--disable-largefile
.endif

.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mshared)
PLIST.shlibs=yes
CONFIGURE_ARGS+=	--enable-shared
.else
PLIST.statlibs=yes
CONFIGURE_ARGS+=	--disable-shared
.endif
