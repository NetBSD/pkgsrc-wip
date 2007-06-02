# $NetBSD: Makefile,v 1.4 2007/06/02 03:34:43 hoka_adam Exp $

PKGNAME=	dfuife_curses-1.5.1
CATEGORIES=	sysutils

.include "../../wip/bsdinstaller/bsdinstaller.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}/installer/src/frontends/ncurses

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI curses frontend

USE_NCURSES=	yes

do-install:
	${INSTALL_DATA_DIR} -p ${PREFIX}/share/dfuife_curses
	${INSTALL_PROGRAM} -o root -g wheel ${WRKSRC}/dfuife_curses ${PREFIX}/sbin/
	${INSTALL_DATA} -o root -g wheel -m 444 ${WRKSRC}/fred.txt ${PREFIX}/share/dfuife_curses/

.include "../../wip/libdfui/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
