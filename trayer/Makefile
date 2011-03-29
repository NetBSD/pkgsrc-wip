# $NetBSD: Makefile,v 1.7 2011/03/29 16:15:11 rsmarples Exp $

TR_VERSION=	1.0
DISTNAME=	trayer-${TR_VERSION}
PKGREVISION=    3
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/fvwm-crystal/

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://fvwm-crystal.org/
COMMENT=	Standalone tray app

USE_TOOLS+=	gmake pkg-config
MAKE_JOBS_SAFE=	no

# trayer uses GTK_OBJECT_FLAGS which has been deprecated
# this is an easy fix
CFLAGS+=	-DGTK_COMPILATION
BUILD_MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

do-install:
	cp ${WRKSRC}/trayer ${PREFIX}/bin/


.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.if ${X11_TYPE} == "modular"
.include "../../x11/libXmu/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
