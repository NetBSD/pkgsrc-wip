# $NetBSD: Makefile,v 1.21 2018/09/22 11:30:23 leot Exp $

PKGNAME=	cwm-6.3.9999
CATEGORIES=	wm
GIT_REPO=	https://github.com/chneukirchen/cwm

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/chneukirchen/cwm
COMMENT=	Portable version of the window manager from OpenBSD (git)
LICENSE=	isc

USE_TOOLS+=	pkg-config yacc

INSTALL_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
