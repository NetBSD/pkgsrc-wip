# $NetBSD: Makefile,v 1.1.1.1 2003/12/26 14:59:37 poppnk Exp $
#

DISTNAME=	compare-1.11
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/compare/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	ftp://ftp.berlios.de/pub/compare/AN-1.11
COMMENT=	Fast binary comparision between two files

USE_GMAKE=	yes
USE_BUILDLINK2=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compare/OBJ/*/compare ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/compare/compare.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/man/man4/makefiles.4 ${PREFIX}/man/man4/
	${INSTALL_MAN} ${WRKSRC}/man/man4/makerules.4 ${PREFIX}/man/man4/

.include "../../mk/bsd.pkg.mk"
