# $NetBSD$

GITHUB_PROJECT=	wlroots
GITHUB_TAG=	0.10.1
DISTNAME=	0.10.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=swaywm/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/swaywm/wlroots/
COMMENT=	Wayland compositor library
LICENSE=	mit

WRKSRC=	${WRKDIR}/wlroots-0.10.1

.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../wip/libinput/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
