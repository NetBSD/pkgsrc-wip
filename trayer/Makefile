# $NetBSD: Makefile,v 1.8 2012/01/12 23:15:24 thomasklausner Exp $

DISTNAME=	trayer-1.0
PKGREVISION=    4
CATEGORIES=	x11
MASTER_SITES=	http://download.gna.org/fvwm-crystal/trayer/1.0/

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://fvwm-crystal.org/
COMMENT=	Standalone tray app
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config
MAKE_JOBS_SAFE=	no

# trayer uses GTK_OBJECT_FLAGS which has been deprecated
# this is an easy fix
CFLAGS+=	-DGTK_COMPILATION
BUILD_MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

INSTALLATION_DIRS=	bin share/doc/trayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trayer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/trayer

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
