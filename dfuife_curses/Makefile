# $NetBSD: Makefile,v 1.3 2007/06/02 00:55:59 hoka_adam Exp $

DISTNAME=	bsdinstaller-20070528
PKGNAME=	dfuife_curses-1.5.1
CATEGORIES=	sysutils

MASTER_SITES=	http://rnrdoctor.sytes.net/~replaced/bsdinstaller/
WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/frontends/ncurses

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI curses frontend

USE_NCURSES=	yes

FILESDIR=	${.CURDIR}/../../wip/bsdinstaller/files

pre-configure:
	${CP} ${FILESDIR}/Config ${WRKDIR}/${DISTNAME}/installer/src/Config

do-install:
	${INSTALL_DATA_DIR} -p ${PREFIX}/share/dfuife_curses
	${INSTALL_PROGRAM} -o root -g wheel ${WRKSRC}/dfuife_curses ${PREFIX}/sbin/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/fred.txt ${PREFIX}/share/dfuife_curses/

.include "../../wip/libdfui/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
