# $NetBSD: Makefile,v 1.5 2005/07/21 16:34:00 thomasklausner Exp $

DISTNAME=	gnome-clipboard-daemon-1.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
COMMENT=	Program that keeps the content of your X clipboard in memory

NO_CONFIGURE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PKGNAME:C/-[^-]*$//} ${PREFIX}/bin/

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
