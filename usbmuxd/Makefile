# $NetBSD$

DISTNAME=	usbmuxd-1.1.0
CATEGORIES=	comms
MASTER_SITES=	http://www.libimobiledevice.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.libimobiledevice.org/
COMMENT=	Multiplexing connections over USB for Apple iOS devices
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../wip/libimobiledevice/buildlink3.mk"
.include "../../wip/libusbmuxd/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
