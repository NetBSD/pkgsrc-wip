# $NetBSD: Makefile,v 1.2 2004/01/22 19:41:44 rillig Exp $

DISTNAME=	tetrinetx-1.13.16+qirc-1.40c
PKGNAME=	tetrinetx-1.13.16
CATEGORIES=	games
MASTER_SITES=   http://tetrinetx.sourceforge.net/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Server for an addictive 6 player tetris game

WRKSRC=		${WRKDIR}/${DISTNAME}
SHAREDIR=	${LOCALBASE}/share/tetrinetx
USE_BUILDLINK2=	YES
BINARY=		tetrix.netbsd

do-build:
	(cd ${WRKSRC}/src && \
	gcc -O2 -fno-strength-reduce -L${LOCALBASE}/lib -ladns -I${LOCALBASE}/include \
		-Wall -DSHAREDIR="\"${SHAREDIR}\"" -DLOCALBASE="\"${LOCALBASE}\"" \
		main.c -o ../bin/${BINARY} ${TETRINETX_LDFLAGS})

do-install:
	@${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BINARY} ${LOCALBASE}/bin/tetrix
	${INSTALL_DATA} -m 644 ${WRKSRC}/bin/game.conf ${SHAREDIR}
	${INSTALL_DATA} -m 644 ${WRKSRC}/bin/game.secure ${SHAREDIR}
	${INSTALL_DATA} -m 644  ${WRKSRC}/bin/game.motd ${SHAREDIR}
	${INSTALL_DATA} -m 644  ${WRKSRC}/bin/game.pmotd ${SHAREDIR}
	@${INSTALL_SCRIPT} -m 751 ${FILESDIR}/tetrinetx ${LOCALBASE}/etc/rc.d

.include "../../net/adns/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == SunOS
TETRINETX_LDFLAGS= -lsocket -lnsl -lresolv
.endif
