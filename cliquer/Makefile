# $NetBSD: Makefile,v 1.1 2014/07/28 22:25:43 jihbed Exp $

DISTNAME=	cliquer-1.21
CATEGORIES=	math
MASTER_SITES=	http://users.tkk.fi/~pat/cliquer/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://users.tkk.fi/~pat/cliquer/
COMMENT=	C routines for finding cliques in an arbitrary weighted graph
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
