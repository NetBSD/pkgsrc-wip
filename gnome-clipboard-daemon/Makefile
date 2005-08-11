# $NetBSD: Makefile,v 1.6 2005/08/11 10:08:22 absd Exp $

DISTNAME=	gnome-clipboard-daemon-1.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
COMMENT=	Program that keeps the content of your X clipboard in memory

USE_TOOLS+=	pkg-config

NO_CONFIGURE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PKGNAME:C/-[^-]*$//} ${PREFIX}/bin/

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
