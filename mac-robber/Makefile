# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:27 othyro Exp $
#

DISTNAME=		mac-robber-1.00
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mac-robber/}
LICENSE=		gnu-gpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.sleuthkit.org/mac-robber/
COMMENT=		Collect mac-times from a computer

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} mac-robber.c -o mac-robber

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mac-robber ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mac-robber
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mac-robber

.include "../../mk/bsd.pkg.mk"
