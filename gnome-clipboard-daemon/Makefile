# $NetBSD: Makefile,v 1.7 2005/11/05 17:10:31 rillig Exp $

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
	${INSTALL_PROGRAM} ${WRKSRC}/gnome-clipboard-daemon ${PREFIX}/bin/

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
