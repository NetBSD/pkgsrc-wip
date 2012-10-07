# $NetBSD: Makefile,v 1.5 2012/10/07 16:33:35 asau Exp $

DISTNAME=	tcmplex-panteltje-0.4.7
CATEGORIES=	multimedia
MASTER_SITES=	http://ip51cf87c4.direct-adsl.nl/panteltje/dvd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	steve@sohara.org
HOMEPAGE=	http://ip51cf87c4.direct-adsl.nl/panteltje/dvd/
COMMENT=	Re-write of the A/V multiplexer from the transcode distribution

BUILD_TARGET=	a.out

DOCSDIR=	${PREFIX}/share/doc/tcmplex-panteltje

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCSDIR}
	for file in CHANGES COPYRIGHT LICENSE README; do \
		${INSTALL_DATA} ${WRKSRC}/$$file ${DESTDIR}${DOCSDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
