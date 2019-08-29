# $NetBSD: Makefile,v 1.3 2018/08/22 09:43:57 wiz Exp $

GIT_COMMIT=	a98426ae69b43396cb22bb62316e270fb1f9d8f1
DISTNAME=	${GIT_COMMIT}
PKGNAME=	swc-0.0.20190810
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/swc/archive/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	swc-${GIT_COMMIT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/swc
COMMENT=	small Wayland compositor implemented as a library
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

WRKSRC=		${WRKDIR}/swc-${GIT_COMMIT}

PKGCONFIG_OVERRIDE+=	swc.pc.in

.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../wip/wld/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
