# $NetBSD$

#https://github.com/OpenZWave/open-zwave/archive/v1.6.tar.gz
GITHUB_PROJECT=	open-zwave
VERSION=	1.6
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
GITHUB_TAG=	v${VERSION}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenZWave/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/OpenZWave/open-zwave/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/open-zwave-1.6
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	cpp/build/libopenzwave.pc.in
PKGCONFIG_OVERRIDE+=	cpp/hidapi/pc/hidapi-hidraw.pc.in
PKGCONFIG_OVERRIDE+=	cpp/hidapi/pc/hidapi-libusb.pc.in
PKGCONFIG_OVERRIDE+=	cpp/hidapi/pc/hidapi.pc.in

# \todo Figure out where this comes from.
CHECK_PORTABILITY_SKIP+=	cpp/examples/MinOZW/MinOZW.in

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
