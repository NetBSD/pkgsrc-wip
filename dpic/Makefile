# $NetBSD: Makefile,v 1.5 2012/09/28 21:24:38 asau Exp $
#

DISTNAME=		dpic
PKGNAME=		dpic-07.2.2
CATEGORIES=		textproc
MASTER_SITES=		http://www.ece.uwaterloo.ca/~aplevich/dpic/

MAINTAINER=		mwicks@kettering.edu
HOMEPAGE=		http://www.ece.uwaterloo.ca/~aplevich/dpic/
COMMENT=		Replacement for pic/gpic that supports more output formats
# also creative commons v3
LICENSE=		2-clause-bsd AND gnu-gpl-v3

BUILD_TARGET=		dpic
INSTALLATION_DIRS+=	share/doc/dpic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dpic ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/dpic_man.txt ${PREFIX}/share/doc/dpic
	${INSTALL_DATA} ${WRKSRC}/doc/examples/Examples.txt ${PREFIX}/share/doc/dpic

.include "../../mk/bsd.pkg.mk"
