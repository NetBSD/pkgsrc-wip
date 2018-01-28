# $NetBSD: options.mk,v 1.17 2017/02/21 14:56:14 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.modular-xorg-server
PKG_SUPPORTED_OPTIONS=	inet6 debug dtrace
PKG_SUPPORTED_OPTIONS+=	devd
PKG_SUGGESTED_OPTIONS=	inet6
.if ${X11_TYPE} == "modular"
PKG_SUPPORTED_OPTIONS+=	dri dri3
PKG_SUGGESTED_OPTIONS+=	dri
PKG_SUGGESTED_OPTIONS+=	dri3
.endif

# dri3 requires kernel support for dma_buf
# .if ${OPSYS} == "Linux"
# PKG_SUGGESTED_OPTIONS+=	dri3
# .endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	devd
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dri dtrace
PLIST_VARS+=		dri3

.if !empty(PKG_OPTIONS:Mdri)

.  if !empty(PKG_OPTIONS:Mdri3)
CONFIGURE_ARGS+=	--enable-dri3
PLIST.dri3=		yes
.include "../../x11/dri3proto/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-dri3
.  endif

.include "../../graphics/libepoxy/buildlink3.mk"
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=11
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/dri2proto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxshmfence/buildlink3.mk"
.include "../../x11/presentproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
PLIST.dri=		yes
CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-dri2
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-glamor
CONFIGURE_ARGS+=	--enable-present
.else
###
### XXX Perhaps we should allow for a built-in glx without dri enabled?
###
CONFIGURE_ARGS+=	--disable-dri
CONFIGURE_ARGS+=	--disable-dri2
CONFIGURE_ARGS+=	--disable-dri3
CONFIGURE_ARGS+=	--disable-glx
CONFIGURE_ARGS+=	--disable-glamor
CONFIGURE_ARGS+=	--disable-present
pre-build: disable-modesetting
.PHONY: disable-modesetting
disable-modesetting:
	(${ECHO} "all:"; ${ECHO} "install:") > ${WRKSRC}/hw/xfree86/drivers/modesetting/Makefile
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
# Debug flags -O0 -g3 recommended by: 
# https://www.x.org/wiki/Development/Documentation/ServerDebugging/
# CFLAGS+=		-ggdb
CFLAGS+=		-O0 -g3
.endif

.if !empty(PKG_OPTIONS:Mdtrace)
PLIST.dtrace=		yes
CONFIGURE_ARGS+=	--with-dtrace
.else
CONFIGURE_ARGS+=	--without-dtrace
.endif

.if !empty(PKG_OPTIONS:Mdevd)
SUBST_CLASSES+=			devd_config
SUBST_STAGE.devd_config=	pre-build
SUBST_MESSAGE.devd_config=	Patching config/Makefile for devd
SUBST_FILES.devd_config+=	config/Makefile
SUBST_SED.devd_config+=		-e 's|config\.c|config.c devd.c|g'
SUBST_SED.devd_config+=		-e 's|config\.lo|config.lo devd.lo|g'
SUBST_CLASSES+=			devd_dix
SUBST_STAGE.devd_dix=		post-configure
SUBST_MESSAGE.devd_dix=		Patching include/dix-config.h for devd 
SUBST_FILES.devd_dix+=		include/dix-config.h	
SUBST_SED.devd_dix+=		-e 's|/\* \#undef CONFIG_UDEV \*/|\#define CONFIG_DEVD 1 |'
.endif
