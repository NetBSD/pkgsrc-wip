# $NetBSD: Makefile,v 1.2 2007/09/10 14:16:04 krub1 Exp $

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

do-install:
	${INSTALL_LIB_DIR} ${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.pc ${PREFIX}/lib/pkgconfig/libvolume_id.pc
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.h ${PREFIX}/include/libvolume_id.h
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.a ${PREFIX}/lib/libvolume_id.a
	${INSTALL_PROGRAM} ${WRKSRC}/libvolume_id.so.0 ${PREFIX}/lib/libvolume_id.so.0
	${LN} -sf ${PREFIX}/lib/libvolume_id.so.0 ${PREFIX}/lib/libvolume_id.so

.include "../../mk/bsd.pkg.mk"
