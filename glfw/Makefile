# $NetBSD: Makefile,v 1.5 2014/10/19 17:42:27 nros Exp $
#

DISTNAME=	glfw-2.7.9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glfw/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.glfw.org/
COMMENT=	GLFW is a free, Open Source, multi-platform library of OpenGL
LICENSE=	zlib

USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	lib/win32/libglfw.pc.in
PKGCONFIG_OVERRIDE+=	lib/cocoa/libglfw.pc.in
PKGCONFIG_OVERRIDE+=	lib/carbon/libglfw.pc.in
PKGCONFIG_OVERRIDE+=	lib/x11/libglfw.pc.in

PKGCONFIG_OVERRIDE_STAGE=post-configure


BUILD_TARGET=	x11
INSTALL_TARGET=	x11-dist-install

MAKE_FLAGS=	SOFLAGS=-shared

do-configure:
	cd ${WRKSRC} && \
	${PKGSRC_ENV} ${MAKE_ENV} ${SH} compile.sh

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
