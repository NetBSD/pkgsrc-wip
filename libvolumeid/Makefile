# $NetBSD: Makefile,v 1.3 2008/02/04 23:14:39 tnn2 Exp $

DISTNAME=		libvolume-0.77
CATEGORIES=		sysutils
MASTER_SITES=           http://www.coris.org.uk/mrk/pkgsrc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		mkirby@NetBSD.org
HOMEPAGE=		http://www.kernel.org/pub/linux/utils/kernel/hotplug/udev.html
COMMENT=		Provides file system information for a given volume device

MAKE_ENV=       	E=${ECHO_MSG:Q} RANLIB=${RANLIB:Q} AR=${AR:Q} Q=@ \
                	CC=${CC:Q} prefix=${PREFIX}

# Linux has UDEV
NOT_FOR_PLATFORM=	Linux-*-*

INSTALLATION_DIRS=	include lib lib/pkgconfig

do-install:
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.pc ${PREFIX}/lib/pkgconfig/libvolume_id.pc
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.h ${PREFIX}/include/libvolume_id.h
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.a ${PREFIX}/lib/libvolume_id.a
	${INSTALL_PROGRAM} ${WRKSRC}/libvolume_id.so.0 ${PREFIX}/lib/libvolume_id.so.0
	${LN} -sf ${PREFIX}/lib/libvolume_id.so.0 ${PREFIX}/lib/libvolume_id.so

.include "../../mk/bsd.pkg.mk"
