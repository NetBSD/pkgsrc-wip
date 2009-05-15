# $NetBSD: Makefile,v 1.1.1.1 2009/05/15 16:36:14 ishit Exp $
#

DISTNAME=	musca-0.9.22
CATEGORIES=	wip x11
MASTER_SITES=	http://aerosuidae.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ishit@users.sourceforge.jp
HOMEPAGE=	http://aerosuidae.net/musca/
COMMENT=	Simple dynamic window manager for X

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musca ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
