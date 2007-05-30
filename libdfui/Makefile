# $NetBSD: Makefile,v 1.4 2007/05/30 21:01:23 hoka_adam Exp $

DISTNAME=	bsdinstaller-20070528
PKGNAME=	libdfui-4.99.1
CATEGORIES=	devel

MASTER_SITES=	http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/lib/libdfui

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	Abstract user interface protocol library

CONFLICTS=	libdfui<4.99

FILESDIR=	${.CURDIR}/../../wip/bsdinstaller/files

post-extract:
	${CP} ${FILESDIR}/Config ${WRKDIR}/${DISTNAME}/installer/src/Config

do-install:
	${INSTALL_DATA_DIR} -p ${PREFIX}/include/dfui
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/libdfui.a ${PREFIX}/lib/
	${INSTALL_PROGRAM} -o root -g wheel -m 444 ${WRKSRC}/libdfui.so.4 ${PREFIX}/lib/
	${LN} -sf ${PREFIX}/lib/libdfui.so.4 ${PREFIX}/lib/libdfui.so
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/dfui.h ${PREFIX}/include/dfui/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/dump.h ${PREFIX}/include/dfui/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/lang.h ${PREFIX}/include/dfui/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/system.h ${PREFIX}/include/dfui/

.include "../../devel/libaura/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
