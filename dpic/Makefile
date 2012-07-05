# $NetBSD: Makefile,v 1.4 2012/07/05 03:32:19 othyro Exp $
#

PKGNAME=		dpic-07.2.2
DISTNAME=		dpic
CATEGORIES=		textproc
MASTER_SITES=		http://www.ece.uwaterloo.ca/~aplevich/dpic/

MAINTAINER=		mwicks@kettering.edu
HOMEPAGE=		http://www.ece.uwaterloo.ca/~aplevich/dpic/
COMMENT=		Replacement for pic/gpic that supports more output formats
LICENSE=		2-clause-bsd gnu-gpl-v3 # also creative commons v3

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		dpic
INSTALLATION_DIRS+=	share/doc/dpic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dpic ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/dpic_man.txt ${PREFIX}/share/doc/dpic
	${INSTALL_DATA} ${WRKSRC}/doc/examples/Examples.txt ${PREFIX}/share/doc/dpic

.include "../../mk/bsd.pkg.mk"
