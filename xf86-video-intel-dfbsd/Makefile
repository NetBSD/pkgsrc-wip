# $NetBSD: Makefile,v 1.41 2018/05/15 10:50:19 wiz Exp $

# Use the commit id to obtain a snapshot of the form:
# http://cgit.freedesktop.org/xorg/driver/xf86-video-intel/snapshot/xf86-video-intel-78d7a09b0343829c81257024b164b0b3764392ac.tar.xz

# 2019-03-01 sna: Switch back to hwcursor on the next cursor update
COMMIT_ID=	6afed33b2d673d88674f0c76efe500ae414e8e1b

# 2019-02-21 Fix build on i686
# COMMIT_ID=	9e6e003e3468dca674ac848e2669af973da02fd4

# 2019-01-21 sna/uxa: Fix colormap handling at screen depth 30. (v2)
# COMMIT_ID=	33ee0c3b21ea279e08d0863fcb2e874f0974b00e

# 2019-01-10 sna: Switch off old outputs on topology changes
# COMMIT_ID=	c37c7ee0748ba828ec5d2c7304cd2a17af2c8109

# 2018-05-12 configure: Set DRI1 to autodiscover
# COMMIT_ID=	359477215092ac1b602ad1e2f17a28963d9224c2

# sna: Use the first active crtc as the primary output fallback
# COMMIT_ID=	cb6ba2da056f3298a765b4da5cd626343c00a533

# 2017-02-28 intel: Fix checking xf86LoadKernelModule for success
# COMMIT_ID=	78d7a09b0343829c81257024b164b0b3764392ac

# DISTNAME=	xf86-video-intel-2.99.917
PORTNAME=	xf86-video-intel
DISTNAME=	${PORTNAME}-${COMMIT_ID}
PKGNAME=	${PORTNAME}-2.99.917
PKGREVISION=	7
CATEGORIES=	x11
# MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
# EXTRACT_SUFX=	.tar.bz2
MASTER_SITES=	http://cgit.freedesktop.org/xorg/driver/${PORTNAME}/snapshot/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver

CONFLICTS+=	xf86-video-i810-[0-9]*

# Enabled by default
# CONFIGURE_ARGS+=	--enable-dri
# CONFIGURE_ARGS+=	--enable-dri2

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config automake autoconf autoreconf

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

# From DragonFly dports x11-drivers/xf86-video-intel29 2.99.2017.01.06
CONFIGURE_ENV.DragonFly+=	xorg_cv_cc_flag__Wno_maybe_uninitialized=no

# DragonFly version 4.6-RELEASE, maybe other versions prior to 4.7
# need -D_WITH_GETLINE=1 according to:
# https://github.com/DragonFlyBSD/DPorts/issues/184
# FreeBSD ports now patches files individually.
# CFLAGS.FreeBSD+=		-D_WITH_GETLINE=1
CFLAGS.DragonFly+=		-D_WITH_GETLINE=1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
SUBST_CLASSES+=			jmp_buf
SUBST_STAGE.jmp_buf=		post-patch
SUBST_MESSAGE.jmp_buf=		Prefer to use dfly specific sigjmp_buf for less errors
SUBST_FILES.jmp_buf=		src/sna/sna.h
SUBST_FILES.jmp_buf+=		src/sna/sna_accel.c
SUBST_SED.jmp_buf=		-e 's@[[:<:]]jmp_buf[[:>:]]@sigjmp_buf@g'
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-intel
PKG_SUPPORTED_OPTIONS=	uxa dri3 debug xvmc
PKG_SUPPORTED_OPTIONS+=	set_dbg_no_unsynchronized_userptr
PKG_SUPPORTED_OPTIONS+=	set_dbg_no_llc
PKG_SUPPORTED_OPTIONS+=	list_h_xserver
PKG_SUPPORTED_OPTIONS+=	kgem_null_bo
PKG_SUPPORTED_OPTIONS+=	handler_xsrc_netbsd
PKG_SUPPORTED_OPTIONS+=	reset_cursor_xsrc_netbsd
PKG_SUPPORTED_OPTIONS+=	strict_xsrc_netbsd
PKG_SUGGESTED_OPTIONS=
# PKG_SUGGESTED_OPTIONS+=	set_dbg_no_unsynchronized_userptr
# PKG_SUGGESTED_OPTIONS+=	set_dbg_no_llc

CONFIGURE_ARGS.FreeBSD+=	--disable-udev

.if ${OPSYS} == "FreeBSD"
PKG_SUGGESTED_OPTIONS+=	uxa
PKG_SUGGESTED_OPTIONS+=	set_dbg_no_unsynchronized_userptr
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	uxa
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	xvmc
.endif

.if ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	set_dbg_no_llc
.endif

# Sync list.h definitions with xorg server, presumably safer.
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	list_h_xserver
.endif

# bo object possibly null in kgem.c
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	kgem_null_bo
.endif

# .if ${OPSYS} == "NetBSD"
# PKG_SUGGESTED_OPTIONS+= handler_xsrc_netbsd
# .endif

# .if ${OPSYS} == "NetBSD"
# PKG_SUGGESTED_OPTIONS+= reset_cursor_xsrc_netbsd
# .endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	strict_xsrc_netbsd
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	xvmc

.if !empty(PKG_OPTIONS:Muxa)
CONFIGURE_ARGS+=	--with-default-accel=uxa
.endif

.if !empty(PKG_OPTIONS:Mdri3)
CONFIGURE_ARGS+=	--enable-dri3
# .else
# CONFIGURE_ARGS+=	--disable-dri3
.endif

# Debug flags recommended for server and drivers by:
# https://www.x.org/wiki/Development/Documentation/ServerDebugging/
# enable-debug crashes xorg DragonFly in __kgem_bo_map__cpu
.if !empty(PKG_OPTIONS:Mdebug)
CFLAGS+=		-O0 -g3
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mxvmc)
# Seems required for actual xvmc support
.include "../../x11/xcb-util/buildlink3.mk"
PLIST.xvmc=		yes
.endif

.if !empty(PKG_OPTIONS:Mset_dbg_no_unsynchronized_userptr)
CPPFLAGS+=	-DSET_DBG_NO_UNSYNCHRONIZED_USERPTR
.endif

.if !empty(PKG_OPTIONS:Mset_dbg_no_llc)
CPPFLAGS+=	-DSET_DBG_NO_LLC
.endif

.if !empty(PKG_OPTIONS:Mlist_h_xserver)
CPPFLAGS+=	-DLIST_H_XSERVER
.endif

.if !empty(PKG_OPTIONS:Mkgem_null_bo)
CPPFLAGS+=	-DKGEM_NULL_BO
.endif

.if !empty(PKG_OPTIONS:Mhandler_xsrc_netbsd)
CPPFLAGS+=	-DHANDLER_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mreset_cursor_xsrc_netbsd)
CPPFLAGS+=	-DRESET_CURSOR_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mstrict_xsrc_netbsd)
CPPFLAGS+=	-DSTRICT_XSRC_NETBSD
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
