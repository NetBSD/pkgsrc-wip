# $NetBSD: Makefile,v 1.1.1.1 2005/02/23 18:57:07 daprice Exp $
#

DISTNAME=		lucy-1.18p
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/Lucy/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.tigr.org/software
COMMENT=		Sequence Cleanup Program

USE_BUILDLINK3=		YES
WRKSRC=			${WRKDIR}/lucy-1.18p

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lucy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lucy.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/lucy
.for EXAMPLE in PUC19 PUC19splice PUC19splice.for PUC19splice.rev \
	atie.seq atie.qul atie.2nd pSPORT1splice pSPORT1vector ARMTM40TR.seq \
	ARMTM40TR.qul lucy.ps lucy.debug
	${INSTALL_DATA} ${WRKSRC}/${EXAMPLE} ${PREFIX}/share/examples/lucy
.endfor

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
