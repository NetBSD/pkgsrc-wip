# $NetBSD$

DISTNAME=	pmonitor
PKGNAME=	pmonitor-0.0.20160101
CATEGORIES=	sysutils pkgtools
MASTER_SITES=	https://netbsd.org/~joerg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://netbsd.org/~joerg/
COMMENT=	Watch for hanging commands or orphaned child processes
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pmonitor ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pmonitor.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
