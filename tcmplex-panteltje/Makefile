# $NetBSD: Makefile,v 1.2 2006/02/07 11:30:53 sohsmith Exp $

DISTNAME=	tcmplex-panteltje-0.4.7
CATEGORIES=	multimedia
MASTER_SITES=	http://ip51cf87c4.direct-adsl.nl/panteltje/dvd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	steve@sohara.org
HOMEPAGE=	http://ip51cf87c4.direct-adsl.nl/panteltje/dvd/
COMMENT=	Re-write of the A/V multiplexer from the transcode distribution

BUILD_TARGET=	a.out

DOCSDIR=	${PREFIX}/share/doc/tcmplex-panteltje

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${PREFIX}/bin/${PKGBASE}
	${MKDIR} ${DOCSDIR}
	for file in CHANGES COPYRIGHT LICENSE README; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${DOCSDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
