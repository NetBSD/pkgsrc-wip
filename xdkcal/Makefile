# $NetBSD: Makefile,v 1.2 2004/04/01 13:52:29 bubuchka Exp $

DISTNAME=		xdkcal-0.9d
CATEGORIES=		wip time
MASTER_SITES=		http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/

MAINTAINER=		mishka@apk.od.ua
HOMEPAGE=		http://www.shiratori.riec.tohoku.ac.jp/~jir/linux/products/xdkcal/index-e.html
COMMENT=		X Desktop Calendar

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_BUILDLINK3=		yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

do-install:
		${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/xdkcal ${PREFIX}/bin
		${INSTALL_MAN_DIR} ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/xdkcal.1x ${PREFIX}/man/man1/xdkcal.1

.include "../../mk/bsd.pkg.mk"
