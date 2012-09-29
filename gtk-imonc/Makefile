# $NetBSD: Makefile,v 1.6 2012/09/29 00:50:40 asau Exp $

DISTNAME=	gtk-imonc-0.6.4.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://zeank.in-berlin.de/download/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://zeank.in-berlin.de/gtkimonc/
COMMENT=	GTK version of the fli4l monitoring tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

LIBS.Darwin+=	-lX11

INSTALLATION_DIRS=	bin share/gnome/apps/Internet share/gtk-imonc/pixmaps

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
