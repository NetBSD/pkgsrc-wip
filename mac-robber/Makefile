# $NetBSD: Makefile,v 1.1.1.1 2006/04/20 10:53:48 poppnk Exp $
#

DISTNAME=		mac-robber-1.00
CATEGORIES=		wip sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mac-robber/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://heanet.dl.sourceforge.net/sourceforge/mac-robber/
COMMENT=		Collect mac-times from a computer

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} mac-robber.c -o mac-robber

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mac-robber ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mac-robber
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mac-robber

.include "../../mk/bsd.pkg.mk"
