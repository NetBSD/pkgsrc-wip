# $NetBSD: Makefile,v 1.1.1.1 2004/12/27 14:26:58 thomasklausner Exp $
#

DISTNAME=		ncc-2.1
CATEGORIES=		devel
MASTER_SITES=		http://students.ceid.upatras.gr/~sxanth/ncc/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://students.ceid.upatras.gr/~sxanth/ncc/index.html
COMMENT=		Compiler that produces program analysis information

USE_BUILDLINK3=		yes
BUILD_TARGET=		tout
CFLAGS+=		-DNOGNU=\\\"${PREFIX}/share/ncc/nognu\\\"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objdir/ncc ${PREFIX}/bin
	${LN} -s ncc ${PREFIX}/bin/nccar
	${LN} -s ncc ${PREFIX}/bin/nccc++
	${LN} -s ncc ${PREFIX}/bin/nccld
	${INSTALL_PROGRAM} ${WRKSRC}/nccnav/nccnav ${PREFIX}/bin
	${LN} -s nccnav ${PREFIX}/bin/nccnavi
	${INSTALL_DATA_DIR} ${PREFIX}/share/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/nognu ${PREFIX}/share/ncc
	${INSTALL_MAN} ${WRKSRC}/ncc.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/KEYS.txt ${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/TROUBLES ${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/doc/hacking.* ${PREFIX}/share/doc/ncc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ncc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
