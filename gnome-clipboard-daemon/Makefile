# $NetBSD: Makefile,v 1.3 2005/04/11 21:12:31 tvierling Exp $

DISTNAME=	gnome-clipboard-daemon-1.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
COMMENT=	Program that keeps the content of your X clipboard in memory

NO_CONFIGURE=	yes
USE_X11=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PKGNAME:C/-[^-]*$//} ${PREFIX}/bin/

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
