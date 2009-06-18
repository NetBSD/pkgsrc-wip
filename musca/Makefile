# $NetBSD: Makefile,v 1.4 2009/06/18 12:18:10 thomasklausner Exp $
#

DISTNAME=	musca-0.9.22
CATEGORIES=	x11
MASTER_SITES=	http://aerosuidae.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ishit@users.sourceforge.jp
HOMEPAGE=	http://aerosuidae.net/musca/
COMMENT=	Simple dynamic window manager for X

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musca ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/musca.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
