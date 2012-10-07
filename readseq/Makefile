# $NetBSD: Makefile,v 1.4 2012/10/07 14:12:40 asau Exp $
#

DISTNAME=		readseq
PKGNAME=		${DISTNAME}-20031211
CATEGORIES=		local
MASTER_SITES=		ftp://ftp.ebi.ac.uk/pub/software/unix/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		ftp://ftp.ebi.ac.uk/pub/software/unix/
COMMENT=		Widely Used Tool to Convert Various Sequence Formats

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/readseq ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/Formats ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/Readme ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/Readseq.help ${DESTDIR}${PREFIX}/share/doc/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
