# $NetBSD$

DISTNAME=	libusbsio-2.1.11-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	devel
MASTER_SITES=	https://www.nxp.com/downloads/en/libraries/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nxp.com/design/design-center/software/development-software/libusbsio-host-library-for-usb-enabled-mcus:LIBUSBSIO
COMMENT=	Library to communicate with serial I/O devices on supported NXP boards
#LICENSE=	# TODO: (see mk/license.mk)

MAKE_FILE=	makefile
USE_TOOLS+=	gmake pkg-config

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
