# $NetBSD: Makefile,v 1.4 2012/10/07 14:01:16 asau Exp $
#

DISTNAME=	uImage-2.6.24+git20080430-r0-om-gta01
PKGNAME=	qemu-neo1973-images-4351
CATEGORIES=	wip
MASTER_SITES=	http://buildhost.openmoko.org/daily/neo1973/deploy/glibc/images/neo1973/ \
		http://buildhost.automated.it/OM2007.2/
EXTRACT_SUFX=	.bin
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		u-boot-gta01bv4-1.3.1+svnr4297+gitb29661fc1151077776454288051bc9a488351ce8-r3${EXTRACT_SUFX} \
		Openmoko-openmoko-devel-image-glibc-ipk-P1-Snapshot-20080430-om-gta01.rootfs.jffs2

MAINTAINER=	noud4@home.nl
HOMEPAGE=	http://openmoko.org/
COMMENT=	Qemu Neo1973 Openmoko fileimage, kernel and booter

DEPENDS+=	qemu-neo1973>=4250:../../wip/qemu-neo1973

WRKSRC=		${WRKDIR}
NO_BUILD=	YES

INSTALLATION_DIRS=	qemu-neo1973/libexec/openmoko

do-extract:
.for f in ${DISTFILES}
	${CP} ${DISTDIR}/${f} ${WRKSRC}
.endfor

do-install:
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/qemu-neo1973/libexec/openmoko
.endfor

.include "../../mk/bsd.pkg.mk"
