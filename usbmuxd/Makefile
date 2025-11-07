# $NetBSD$

DISTNAME=	usbmuxd-1.1.1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.libimobiledevice.org/
COMMENT=	Multiplexing connections over USB for Apple iOS devices
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf gmake pkg-config

USBMUXD_USER?=	usbmux
USBMUXD_GROUP?=	usbmux
PKG_GROUPS=	${USBMUXD_USER}
PKG_USERS=	${USBMUXD_USER}:${USBMUXD_GROUP}

RCD_SCRIPTS=	usbmuxd
FILES_SUBST+=	USBMUXD_USER=${USBMUXD_USER:Q}
FILES_SUBST+=	USBMUXD_GROUP=${USBMUXD_GROUP:Q}

post-patch:
	cd ${WRKSRC} && autoconf

.include "../../wip/libimobiledevice/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
