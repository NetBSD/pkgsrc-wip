# $NetBSD: Makefile,v 1.3 2007/05/30 17:41:48 hoka_adam Exp $

PKGNAME=	libinstaller-5.1
DISTNAME=	bsdinstaller-20070628
CATEGORIES=	devel

MASTER_SITES=	http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/lib/libinstaller

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	BSD Installer library

FILESDIR=	${.CURDIR}/../../wip/bsdinstaller/files

pre-configure:
	${CP} ${FILESDIR}/Config ${WRKDIR}/${DISTNAME}/installer/src/Config

do-install:
	${INSTALL_DATA_DIR} -p ${PREFIX}/include/installer
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/libinstaller.a ${PREFIX}/lib/
	${INSTALL_PROGRAM} -o root -g wheel -m 444 ${WRKSRC}/libinstaller.so.5 ${PREFIX}/lib/
	${LN} -sf ${PREFIX}/lib/libinstaller.so.5 ${PREFIX}/lib/libinstaller.so
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/commands.h ${PREFIX}/include/installer/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/confed.h ${PREFIX}/include/installer/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/diskutil.h ${PREFIX}/include/installer/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/functions.h ${PREFIX}/include/installer/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/package.h ${PREFIX}/include/installer/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/uiutil.h ${PREFIX}/include/installer/


.include "../../wip/libdfui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
