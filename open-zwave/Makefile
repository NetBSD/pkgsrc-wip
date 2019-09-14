# $NetBSD$

# Originally we packaged the v1.6 releaes, but upstream seems to avoid
# using master (the stable branch), as there are frequent
# fixes/updates to config files, but no new release tags.  We
# construct a faux release number by using 1.6 (the release), .0, and
# the commit number along master since 1.6, in order to sort under a
# possible 1.6.1.
GITHUB_PROJECT=	open-zwave
VERSION=	1.6.0.913	# faux
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
GITHUB_TAG=	2f2b314f7d8c7b2fc943e57f09bcf9bb6670adbc
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenZWave/}

# \todo Define shortened variants of PKGVERSION as 1.6 and 1.6.0 for
# PLIST usage.

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/OpenZWave/open-zwave/
COMMENT=	Library for Z-Wave controllers
LICENSE=	gnu-lgpl-v3

#WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
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
