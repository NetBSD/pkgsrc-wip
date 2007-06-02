# $NetBSD: Makefile,v 1.7 2007/06/02 01:14:24 hoka_adam Exp $

DISTNAME=	bsdinstaller-20070528
PKGNAME=	libinstaller-5.99.1
PKGREVISION=	1
CATEGORIES=	devel

MASTER_SITES=	http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/lib/libinstaller

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	BSD Installer library

FILESDIR=	${.CURDIR}/../../wip/bsdinstaller/files

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	functions.c
SUBST_SED.conf=		-e "s|@@prefix@@|${PREFIX}|g"
SUBST_MESSAGE.conf=	Fixing hardcoded paths.

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
