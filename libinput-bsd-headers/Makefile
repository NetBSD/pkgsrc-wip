# $NetBSD$

.include "../../wip/libinput-bsd/Makefile.common"
PKGNAME=	${DISTNAME:S/bsd/bsd-headers/}

COMMENT=	headers for wscons(4) and kqueue(2) based port of libinput

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	include/linux/freebsd include/linux/linux
HDRSRC=			${WRKSRC}/include/linux

do-install:
	${INSTALL_DATA} ${HDRSRC}/freebsd/input-event-codes.h ${DESTDIR}${PREFIX}/include/linux/freebsd
	${INSTALL_DATA} ${HDRSRC}/freebsd/input.h ${DESTDIR}${PREFIX}/include/linux/freebsd
	${INSTALL_DATA} ${HDRSRC}/linux/input-event-codes.h ${DESTDIR}${PREFIX}/include/linux/linux
	${INSTALL_DATA} ${HDRSRC}/linux/input.h ${DESTDIR}${PREFIX}/include/linux/linux
	${INSTALL_DATA} ${HDRSRC}/input-event-codes.h ${DESTDIR}${PREFIX}/include/linux/
	${INSTALL_DATA} ${HDRSRC}/input.h ${DESTDIR}${PREFIX}/include/linux

.include "../../mk/bsd.pkg.mk"
