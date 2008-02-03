# $NetBSD: Makefile,v 1.7 2008/02/03 14:13:46 tnn2 Exp $
#

DISTNAME=		compare-1.11
CATEGORIES=		sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/compare/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.berlios.de/pub/compare/AN-1.11
COMMENT=		Fast binary comparision between two files

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compare/OBJ/*/compare ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/compare/compare.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/man/man4/makefiles.4 ${PREFIX}/${PKGMANDIR}/man4/
	${INSTALL_MAN} ${WRKSRC}/man/man4/makerules.4 ${PREFIX}/${PKGMANDIR}/man4/

.include "../../mk/bsd.pkg.mk"
