# $NetBSD: options.mk,v 1.19 2018/05/11 13:47:35 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.modular-xorg-server
PKG_SUPPORTED_OPTIONS=	inet6 debug dtrace
PKG_SUGGESTED_OPTIONS=	inet6
.if ${X11_TYPE} == "modular"
PKG_SUPPORTED_OPTIONS+=	dri
PKG_SUGGESTED_OPTIONS+=	dri
.endif

PKG_SUPPORTED_OPTIONS+=	devd
PKG_SUPPORTED_OPTIONS+=	xkb_evdev

PKG_SUPPORTED_OPTIONS+=	revert_flink
PKG_SUPPORTED_OPTIONS+=	revert_randr_lease
PKG_SUPPORTED_OPTIONS+=	add_scfb_driver
PKG_SUPPORTED_OPTIONS+=	add_modesetting_driver

PKG_SUPPORTED_OPTIONS+=	allow_unprivileged
PKG_SUPPORTED_OPTIONS+=	vtsw_kdsetmode_xsrc
PKG_SUPPORTED_OPTIONS+=	always_add_wsfb
PKG_SUPPORTED_OPTIONS+=	sharevts_xsrc_netbsd
PKG_SUPPORTED_OPTIONS+=	strict_xsrc_netbsd

PKG_SUPPORTED_OPTIONS+=	modesetting_on_intel
PKG_SUPPORTED_OPTIONS+=	try_dev_wskbd

PKG_SUPPORTED_OPTIONS+=	ws_drivers_openbsd

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	devd
.endif

.if ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	revert_flink
PKG_SUGGESTED_OPTIONS+=	revert_randr_lease
.endif

# Add scfb driver in xf86AutoConfig.c
.if ${OPSYS} == "FreeBSD"
PKG_SUGGESTED_OPTIONS+=	add_scfb_driver
.endif

# Add modesetting driver in xf86AutoConfig.c
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	add_modesetting_driver
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	allow_unprivileged
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	vtsw_kdsetmode_xsrc
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	always_add_wsfb
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	sharevts_xsrc_netbsd
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	strict_xsrc_netbsd
.endif

# Patch from OpenBSD to aggressively use the modesetting driver on intel integrated graphics
# .if ${OPSYS} == "OpenBSD" || ${OPSYS} == "NetBSD"
.if ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS+=	modesetting_on_intel
.endif

# From NetBSD 1.20.4 but extended to amd64 and i386
# .if ${OPSYS} == "NetBSD"
# PKG_SUGGESTED_OPTIONS+= try_dev_wskbd
# .endif

# From OpenBSD 6.5 xenocara xserver 1.19.7
# .if ${OPSYS} == "OpenBSD" || ${OPSYS} == "NetBSD"
.if ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS+=	ws_drivers_openbsd
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dri dtrace

.if !empty(PKG_OPTIONS:Mdri)
.include "../../graphics/libepoxy/buildlink3.mk"
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=11
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxshmfence/buildlink3.mk"
PLIST.dri=		yes
CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-dri2
CONFIGURE_ARGS+=	--enable-dri3
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-glamor
CONFIGURE_ARGS+=	--enable-present
MESON_ARGS+=		-Ddri1=true
MESON_ARGS+=		-Ddri2=true
MESON_ARGS+=		-Ddri3=true
MESON_ARGS+=		-Dglx=true
MESON_ARGS+=		-Dglamor=true
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
MESON_ARGS+=		-Ddri1=false
MESON_ARGS+=		-Ddri2=false
MESON_ARGS+=		-Ddri3=false
MESON_ARGS+=		-Dglx=false
MESON_ARGS+=		-Dglamor=false
pre-build: disable-modesetting
.PHONY: disable-modesetting
disable-modesetting:
	(${ECHO} "all:"; ${ECHO} "install:") > ${WRKSRC}/hw/xfree86/drivers/modesetting/Makefile
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
MESON_ARGS+=		-Dipv6=true
.else
CONFIGURE_ARGS+=	--disable-ipv6
MESON_ARGS+=		-Dipv6=false
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
MESON_ARGS+=		--buildtype=debug
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
# SUBST_CLASSES+=			devd_config
# SUBST_STAGE.devd_config=	post-configure
# SUBST_MESSAGE.devd_config=	Patching config/Makefile for devd
# SUBST_FILES.devd_config+=	config/Makefile
# SUBST_SED.devd_config+=		-e 's|config\.c|config.c devd.c|g'
# SUBST_SED.devd_config+=		-e 's|config\.lo|config.lo devd.lo|g'
# SUBST_CLASSES+=			devd_dix
# SUBST_STAGE.devd_dix=		post-configure
# SUBST_MESSAGE.devd_dix=		Patching include/dix-config.h for devd
# SUBST_FILES.devd_dix+=		include/dix-config.h
# SUBST_SED.devd_dix+=		-e 's|/\* \#undef CONFIG_UDEV \*/|\#define CONFIG_DEVD 1 |'
CPPFLAGS+=	-DCONFIG_DEVD=1
MESON_ARGS+=	-Ddevd=true
.endif

.if !empty(PKG_OPTIONS:Mxkb_evdev)
MESON_ARGS+=	-Dxkb_default_rules=evdev
.else
MESON_ARGS+=	-Dxkb_default_rules=base
.endif

.if !empty(PKG_OPTIONS:Mrevert_flink)
CPPFLAGS+=	-DREVERT_FLINK
.endif

.if !empty(PKG_OPTIONS:Mrevert_randr_lease)
CPPFLAGS+=	-DREVERT_RANDR_LEASE

SUBST_CLASSES+=		lease
SUBST_STAGE.lease=	post-configure
SUBST_MESSAGE.lease=	Removing definition of XF86_LEASE_VERSION
SUBST_FILES.lease+=	hw/xfree86/modes/xf86Crtc.h
SUBST_SED.lease+=	-e 's|XF86_LEASE_VERSION|REVERT_XF86_LEASE_VERSION|g'
.endif

.if !empty(PKG_OPTIONS:Madd_scfb_driver)
CPPFLAGS+=	-DADD_SCFB_DRIVER
.endif

.if !empty(PKG_OPTIONS:Madd_modesetting_driver)
CPPFLAGS+=	-DADD_MODESETTING_DRIVER
.endif

.if !empty(PKG_OPTIONS:Mallow_unprivileged)
CPPFLAGS+=	-DALLOW_UNPRIVILEGED
.endif

.if !empty(PKG_OPTIONS:Mvtsw_kdsetmode_xsrc)
CPPFLAGS+=	-DVTSW_KDSETMODE_XSRC
.endif

.if !empty(PKG_OPTIONS:Malways_add_wsfb)
CPPFLAGS+=	-DALWAYS_ADD_WSFB
.endif

.if !empty(PKG_OPTIONS:Msharevts_xsrc_netbsd)
CPPFLAGS+=	-DSHAREVTS_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mstrict_xsrc_netbsd)
CPPFLAGS+=	-DSTRICT_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mmodesetting_on_intel)
CPPFLAGS+=	-DMODESETTING_ON_INTEL
.endif

.if !empty(PKG_OPTIONS:Mtry_dev_wskbd)
CPPFLAGS+=	-DTRY_DEV_WSKBD
CPPFLAGS+=	-DCONFIG_WSCONS=1
MESON_ARGS+=	-Dwscons=true
.endif

.if !empty(PKG_OPTIONS:Mws_drivers_openbsd)
CPPFLAGS+=	-DWS_DRIVERS_OPENBSD
.endif
