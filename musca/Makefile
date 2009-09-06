# $NetBSD: Makefile,v 1.5 2009/09/06 23:38:27 thomasklausner Exp $
#

DISTNAME=	musca-0.9.22
CATEGORIES=	wm
MASTER_SITES=	http://aerosuidae.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ishit@users.sourceforge.jp
HOMEPAGE=	http://aerosuidae.net/musca/Musca_Window_Manager
COMMENT=	Simple dynamic window manager for X
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/musca ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/musca.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
