# $NetBSD: Makefile,v 1.2 2009/05/27 15:41:32 ishit Exp $
#

DISTNAME=	musca-0.9.22
CATEGORIES=	wip x11
MASTER_SITES=	http://aerosuidae.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ishit@users.sourceforge.jp
HOMEPAGE=	http://aerosuidae.net/musca/
COMMENT=	Simple dynamic window manager for X

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musca ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
