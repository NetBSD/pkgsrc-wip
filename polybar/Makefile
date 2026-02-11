# $NetBSD$

DISTNAME=	polybar-3.7.2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=polybar/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/polybar/polybar/
COMMENT=	Fast and easy-to-use status bar
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-xcbgen-[0-9]*:../../x11/py-xcbgen

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DSPHINX_BUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}

# uses inotify
ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
