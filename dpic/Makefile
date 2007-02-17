# $NetBSD: Makefile,v 1.2 2007/02/17 22:43:47 mwicks Exp $
#

PKGNAME=		dpic-07.2.2
DISTNAME=		dpic
CATEGORIES=		textproc
MASTER_SITES=		http://www.ece.uwaterloo.ca/~aplevich/dpic/

MAINTAINER=		mwicks@kettering.edu
HOMEPAGE=		http://www.ece.uwaterloo.ca/~aplevich/dpic/
COMMENT=		Replacement for pic/gpic that supports more output formats

BUILD_TARGET=		dpic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dpic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dpic
	${INSTALL_DATA} ${WRKSRC}/doc/dpic_man.txt ${PREFIX}/share/doc/dpic
	${INSTALL_DATA} ${WRKSRC}/doc/examples/Examples.txt ${PREFIX}/share/doc/dpic

.include "../../mk/bsd.pkg.mk"

