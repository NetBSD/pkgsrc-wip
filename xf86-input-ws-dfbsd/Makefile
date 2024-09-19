# $NetBSD: Makefile,v 1.3 2018/03/07 11:57:42 wiz Exp $

DISTNAME=	xf86-input-ws-1.3.0.20151010
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xenocara.org/
COMMENT=	OpenBSDs wscons input driver for modular X.org

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-input-ws

PKG_SUPPORTED_OPTIONS=
PKG_SUGGESTED_OPTIONS=

PKG_SUPPORTED_OPTIONS+=	keyboard_button_xsrc_netbsd
# .if ${OPSYS} == "NetBSD"
# PKG_SUGGESTED_OPTIONS+= keyboard_button_xsrc_netbsd
# .endif

PKG_SUPPORTED_OPTIONS+=	undef_tpanel_xsrc_netbsd
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	undef_tpanel_xsrc_netbsd
.endif

PKG_SUPPORTED_OPTIONS+=	calibration_kernel_xsrc_netbsd
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	calibration_kernel_xsrc_netbsd
.endif

PKG_SUPPORTED_OPTIONS+=	strict_xsrc_netbsd
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	strict_xsrc_netbsd
.endif

PKG_SUPPORTED_OPTIONS+=	read_eio_xenocara_openbsd
.if ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS+=	read_eio_xenocara_openbsd
.endif

PKG_SUPPORTED_OPTIONS+=	strict_xenocara_openbsd
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
PKG_SUGGESTED_OPTIONS+=	strict_xenocara_openbsd
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkeyboard_button_xsrc_netbsd)
CPPFLAGS+=	-DKEYBOARD_BUTTON_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mundef_tpanel_xsrc_netbsd)
CPPFLAGS+=	-DUNDEF_TPANEL_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mcalibration_kernel_xsrc_netbsd)
CPPFLAGS+=	-DCALIBRATION_KERNEL_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mstrict_xsrc_netbsd)
CPPFLAGS+=	-DSTRICT_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mstrict_xenocara_openbsd)
CPPFLAGS+=	-DSTRICT_XENOCARA_OPENBSD
.endif

.if !empty(PKG_OPTIONS:Mread_eio_xenocara_openbsd)
CPPFLAGS+=	-DREAD_EIO_XENOCARA_OPENBSD
.endif

.if !empty(PKG_OPTIONS:Mstrict_xenocara_openbsd)
CPPFLAGS+=	-DSTRICT_XENOCARA_OPENBSD
.endif

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
