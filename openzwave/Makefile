# $NetBSD$

# Upstream has both a web site and github, and says that the releases
# on github are not actually releases.  We use releases from the
# website (which is the old website with not-old releases).

DISTNAME=	openzwave-1.6.1123
CATEGORIES=	comms
MASTER_SITES=	http://old.openzwave.com/downloads/

# \todo Define shortened variants of PKGVERSION as 1.6 and 1.6.0 for
# PLIST usage.

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.openzwave.com/
#HOMEPAGE=	https://github.com/OpenZWave/open-zwave/
#HOMEPAGE=	http://bamboo.my-ho.st/bamboo/allPlans.action
COMMENT=	Library for Z-Wave controllers
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	cpp/build/libopenzwave.pc.in
PKGCONFIG_OVERRIDE+=	cpp/hidapi/pc/hidapi-hidraw.pc.in
PKGCONFIG_OVERRIDE+=	cpp/hidapi/pc/hidapi-libusb.pc.in
PKGCONFIG_OVERRIDE+=	cpp/hidapi/pc/hidapi.pc.in

# \todo Remeeiate bashism and file upstream PR.
CHECK_PORTABILITY_SKIP+=	cpp/examples/MinOZW/MinOZW.in

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
