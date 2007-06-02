# $NetBSD: Makefile,v 1.8 2007/06/02 03:34:43 hoka_adam Exp $

PKGNAME=	libinstaller-5.99.1
PKGREVISION=	1
CATEGORIES=	devel

.include "../../wip/bsdinstaller/bsdinstaller.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/lib/libinstaller

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	BSD Installer library

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	functions.c
SUBST_SED.conf=		-e "s|@@prefix@@|${PREFIX}|g"
SUBST_MESSAGE.conf=	Fixing hardcoded paths.

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
