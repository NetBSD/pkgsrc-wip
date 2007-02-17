# $NetBSD: Makefile,v 1.1 2007/02/17 18:19:02 mwicks Exp $
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

.include "../../mk/bsd.pkg.mk"
