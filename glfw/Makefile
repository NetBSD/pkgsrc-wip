# $NetBSD: Makefile,v 1.1.1.1 2010/11/17 13:45:13 ryo-on Exp $
#

DISTNAME=	glfw-2.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glfw/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.glfw.org/
COMMENT=	GLFW is a free, Open Source, multi-platform library of OpenGL
#LICENSE=	zlib/libpng license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lib/win32/libglfw.pc.in
PKGCONFIG_OVERRIDE+=	lib/cocoa/libglfw.pc.in
PKGCONFIG_OVERRIDE+=	lib/carbon/libglfw.pc.in

BUILD_TARGET=	x11
INSTALL_TARGET=	x11-install

MAKE_FLAGS=	SOFLAGS=-shared

PKGCONFIG_OVERRIDE+=	libglfw.pc.in

do-configure:
	cd ${WRKSRC} && \
	${SH} compile.sh

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
