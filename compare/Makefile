# $NetBSD: Makefile,v 1.10 2013/01/20 03:38:39 othyro Exp $
#

DISTNAME=	compare-1.16
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/compare/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.berlios.de/pub/compare/AN-1.11
COMMENT=	Fast binary comparision between two files
LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM=	*-*-x86_64

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/compare/OBJ/*/compare ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/compare/compare.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/man/man4/makefiles.4 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/
	${INSTALL_MAN} ${WRKSRC}/man/man4/makerules.4 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man4/

.include "../../mk/bsd.pkg.mk"
