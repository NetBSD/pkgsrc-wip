# $NetBSD: Makefile,v 1.1.1.1 2004/01/25 19:27:37 minskim Exp $

DISTNAME=	gnome-clipboard-daemon-1.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://members.chello.nl/~h.lai/gnome-clipboard-daemon/
COMMENT=	Program that keeps the content of your X clipboard in memory

USE_BUILDLINK2=	yes
NO_CONFIGURE=	yes
USE_X11=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PKGNAME:C/-[^-]*$//} ${PREFIX}/bin/

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
