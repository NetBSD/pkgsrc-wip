# $NetBSD$

DISTNAME=	progman-0.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcs/}
GITHUB_TAG=	195c1da675cd861b0f6d3253182c8da03d3dca6e

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/jcs/progman
COMMENT=	Window manager resembling Windows 3's Program Manager
LICENSE=	mit 

USE_TOOLS+=	pkg-config

CFLAGS+=	"-DINFTIM=-1"
LDFLAGS+=	-lXext

MAKE_FLAGS+=	PREFIX=${DESTDIR:Q}${PREFIX:Q}
MAKE_FLAGS+=	MANDIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
