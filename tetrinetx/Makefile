# $NetBSD: Makefile,v 1.1.1.1 2003/09/02 06:06:25 xtraeme Exp $

DISTNAME=	tetrinetx-1.13.16+qirc-1.40c
PKGNAME=	tetrinetx-1.13.16
CATEGORIES=	games
MASTER_SITES=   http://tetrinetx.sourceforge.net/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Addictive 6 player tetris game

WRKSRC=		${WRKDIR}/${DISTNAME}
SHAREDIR=	${PREFIX}/share/tetrinetx
USE_BUILDLINK2=	YES
BINARY=		tetrix.netbsd

do-build:
	(cd ${WRKSRC}/src && \
	gcc -O2 -fno-strength-reduce -L/usr/pkg/lib -ladns -I/usr/pkg/include \
		-Wall main.c -o ../bin/${BINARY})

do-install:
	@${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BINARY} ${PREFIX}/bin/tetrix
	${INSTALL_DATA} -m 644 ${WRKSRC}/bin/game.conf ${SHAREDIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/bin/game.secure ${SHAREDIR}
	${INSTALL_DATA} -m 644  ${WRKSRC}/bin/game.motd ${SHAREDIR}
	${INSTALL_DATA} -m 644  ${WRKSRC}/bin/game.pmotd ${SHAREDIR}
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/tetrinetx ${PREFIX}/etc/rc.d

.include "../../net/adns/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
