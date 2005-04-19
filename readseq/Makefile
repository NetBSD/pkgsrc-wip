# $NetBSD: Makefile,v 1.3 2005/04/19 23:44:17 daprice Exp $
#

DISTNAME=		readseq
PKGNAME=		${DISTNAME}-20031211
CATEGORIES=		local
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		ftp://ftp.ebi.ac.uk/pub/software/unix/
COMMENT=		Widely Used Tool to Convert Various Sequence Formats

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/readseq ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/Formats ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/Readme ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/Readseq.help ${PREFIX}/share/doc/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
