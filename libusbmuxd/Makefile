# $NetBSD$

DISTNAME=	libusbmuxd-2.0.2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/libusbmuxd/releases/download/2.0.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	weabot@protonmail.com
HOMEPAGE=	https://www.libimobiledevice.org/
COMMENT=	Communication interface library for usbmuxd
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

.include "../../wip/libplist2/buildlink3.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libusbmuxd-2.0.pc.in

.include "../../mk/bsd.pkg.mk"
