# $NetBSD: Makefile,v 1.19 2018/05/13 03:45:07 ryoon Exp $

DISTNAME=	xf86-video-wsfb-0.4.0
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg wsdisplay framebuffer video driver

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-wsfb

PKG_SUPPORTED_OPTIONS=
PKG_SUGGESTED_OPTIONS=

PKG_SUPPORTED_OPTIONS+=	ramdac_xsrc_netbsd
PKG_SUPPORTED_OPTIONS+=	hwcursor_xsrc_netbsd
PKG_SUPPORTED_OPTIONS+=	luna68k_xsrc_netbsd
PKG_SUPPORTED_OPTIONS+=	bgra_xsrc_netbsd
PKG_SUPPORTED_OPTIONS+=	wildcat_xsrc_netbsd
PKG_SUPPORTED_OPTIONS+=	modesetting_fb_xsrc_netbsd
PKG_SUPPORTED_OPTIONS+=	strict_xsrc_netbsd

# As of 2019-01-30 core ramdac code and ramdac drivers
# removed from xorg server
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	ramdac_xsrc_netbsd
.endif

.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	hwcursor_xsrc_netbsd
PKG_SUGGESTED_OPTIONS+=	luna68k_xsrc_netbsd
PKG_SUGGESTED_OPTIONS+=	bgra_xsrc_netbsd
PKG_SUGGESTED_OPTIONS+=	wildcat_xsrc_netbsd
PKG_SUGGESTED_OPTIONS+=	modesetting_fb_xsrc_netbsd
PKG_SUGGESTED_OPTIONS+=	strict_xsrc_netbsd
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mramdac_xsrc_netbsd)
CPPFLAGS+=	-DRAMDAC_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mhwcursor_xsrc_netbsd)
CPPFLAGS+=	-DHWCURSOR_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mluna68k_xsrc_netbsd)
CPPFLAGS+=	-DLUNA68K_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mbgra_xsrc_netbsd)
CPPFLAGS+=	-DBGRA_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mwildcat_xsrc_netbsd)
CPPFLAGS+=	-DWILDCAT_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mmodesetting_fb_xsrc_netbsd)
CPPFLAGS+=	-DMODESETTING_FB_XSRC_NETBSD
.endif

.if !empty(PKG_OPTIONS:Mstrict_xsrc_netbsd)
CPPFLAGS+=	-DSTRICT_XSRC_NETBSD
.endif

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
