# $NetBSD: Makefile,v 1.1.1.1 2004/04/01 12:45:05 bubuchka Exp $

DISTNAME=		xdkcal-0.9d
CATEGORIES=		wip time
MASTER_SITES=		http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/index-e.html
COMMENT=		X Desktop Calendar

GNU_CONFIGURE=		yes
USE_X11=		yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/xdkcal ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/xdkcal.1x ${PREFIX}/man/man1/xdkcal.1

.include "../../mk/bsd.pkg.mk"
