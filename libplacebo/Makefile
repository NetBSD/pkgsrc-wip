# $NetBSD$

DISTNAME=	libplacebo-v6.338.1
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	multimedia
MASTER_SITES=	https://code.videolan.org/videolan/libplacebo/-/archive/v${PKGVERSION}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.videolan.org/videolan/libplacebo
COMMENT=	GPU-accelerated image/video processing primitives and shaders
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-glad2-[0-9]*:../../wip/py-glad2

MESON_ARGS+=	-Ddemos=false
MESON_ARGS+=	-Ddovi=disabled
MESON_ARGS+=	-Dglslang=disabled
MESON_ARGS+=	-Dlcms=enabled
MESON_ARGS+=	-Dopengl=enabled
MESON_ARGS+=	-Dshaderc=disabled
MESON_ARGS+=	-Dvulkan=disabled
MESON_ARGS+=	-Dxxhash=enabled

USE_TOOLS+=	pkg-config

USE_LANGUAGES=	c c++

.include "../../devel/meson/build.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
