# $NetBSD: Makefile,v 1.9 2010/06/13 22:47:05 thomasklausner Exp $
#

DISTNAME=	clipboard-daemon-1.0
PKGNAME=	gnome-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
COMMENT=	Program that keeps the content of your X clipboard in memory
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clipboard-daemon ${DESTDIR}${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
