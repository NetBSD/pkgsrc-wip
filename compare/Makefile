# $NetBSD: Makefile,v 1.5 2005/05/24 10:29:26 rillig Exp $
#

DISTNAME=		compare-1.11
CATEGORIES=		sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/compare/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.berlios.de/pub/compare/AN-1.11
COMMENT=		Fast binary comparision between two files

USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compare/OBJ/*/compare ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/compare/compare.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/man4/makefiles.4 ${PREFIX}/man/man4/
	${INSTALL_MAN} ${WRKSRC}/man/man4/makerules.4 ${PREFIX}/man/man4/

.include "../../mk/bsd.pkg.mk"
