# $NetBSD: Makefile,v 1.5 2012/10/03 13:59:35 asau Exp $
#

DISTNAME=		mac-robber-1.00
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mac-robber/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.sleuthkit.org/mac-robber/
COMMENT=		Collect mac-times from a computer

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} mac-robber.c -o mac-robber

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mac-robber ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mac-robber
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mac-robber

.include "../../mk/bsd.pkg.mk"
