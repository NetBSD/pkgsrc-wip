# $NetBSD: Makefile,v 1.4 2010/06/13 22:47:06 thomasklausner Exp $

DISTNAME=	gtk-imonc-0.6.4.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://zeank.in-berlin.de/download/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://zeank.in-berlin.de/gtkimonc/
COMMENT=	GTK version of the fli4l monitoring tool

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
LIBS+=		-lX11
.endif

INSTALLATION_DIRS=	bin share/gnome/apps/Internet share/gtk-imonc/pixmaps

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
