# $NetBSD$

DISTNAME=	libusbmuxd-1.0.10
CATEGORIES=	comms
MASTER_SITES=	http://www.libimobiledevice.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	weabot@protonmail.com
HOMEPAGE=	http://www.libimobiledevice.org/
COMMENT=	Communication interface library for usbmuxd
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=	pkgconf>=0.9.10:../../devel/pkgconf

.include "../../textproc/libplist/buildlink3.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libusbmuxd.pc.in

.include "../../mk/bsd.pkg.mk"
