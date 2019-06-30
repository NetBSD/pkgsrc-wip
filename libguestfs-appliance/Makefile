# $NetBSD$

DISTNAME=	appliance-1.38.0
PKGNAME=	libguestfs-${DISTNAME}
CATEGORIES=	emulators filesystems
MASTER_SITES=	http://download.libguestfs.org/binaries/appliance/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libguestfs.org/guestfs-building.1.html\#using-a-prebuilt-binary-appliance
COMMENT=	Fixed appliance binaries for libguestfs
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2.1

BUILD_DEPENDS+=	qemu-[0-9]*:../../emulators/qemu

EXTRACT_USING=	bsdtar
NO_CONFIGURE=	yes
USE_TOOLS+=	pax
WRKSRC=		${WRKDIR}/appliance

CHECK_WRKREF_SKIP+=	lib/guestfs/*
INSTALLATION_DIRS+=	lib/guestfs

do-build:
	${PREFIX}/bin/qemu-img convert -f raw -O qcow2 -c \
	  ${WRKSRC}/root ${WRKSRC}/root.qcow2
	rm ${WRKSRC}/root
	ln -s root.qcow2 ${WRKSRC}/root

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/lib/guestfs/.

.include "../../mk/bsd.pkg.mk"
