# $NetBSD: Makefile,v 1.4 2004/04/25 23:47:32 thomasklausner Exp $

DISTNAME=	tetrinetx-1.13.16+qirc-1.40c
PKGNAME=	tetrinetx-1.13.16
CATEGORIES=	games
MASTER_SITES=   http://tetrinetx.sourceforge.net/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Server for an addictive 6 player tetris game

WRKSRC=		${WRKDIR}/${DISTNAME}
SHAREDIR=	${PREFIX}/share/tetrinetx
USE_BUILDLINK3=	YES
BINARY=		tetrix.netbsd

LIBS.SunOS=	-lsocket -lnsl -lresolv

do-build:
	(cd ${WRKSRC}/src && \
	gcc -O2 -fno-strength-reduce -Wl,-R${LOCALBASE}/lib \
		-L${LOCALBASE}/lib -ladns -I${LOCALBASE}/include \
		-Wall -DSHAREDIR="\"${SHAREDIR}\"" -DPREFIX="\"${PREFIX}\"" \
		main.c -o ../bin/${BINARY} ${LIBS})

do-install:
	@${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BINARY} ${PREFIX}/bin/tetrix
	${INSTALL_DATA} -m 644 ${WRKSRC}/bin/game.conf ${SHAREDIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/bin/game.secure ${SHAREDIR}
	${INSTALL_DATA} -m 644  ${WRKSRC}/bin/game.motd ${SHAREDIR}
	${INSTALL_DATA} -m 644  ${WRKSRC}/bin/game.pmotd ${SHAREDIR}
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/tetrinetx ${PREFIX}/etc/rc.d

.include "../../net/adns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
