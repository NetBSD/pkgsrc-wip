# $NetBSD$

DISTNAME=		piglit-0.0.0
CATEGORIES=		graphics x11
MASTER_SITES=		http://cgit.freedesktop.org/piglit

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		https://piglit.freedesktop.org/
COMMENT=		OpenGL driver testing framework
LICENSE=		mit AND gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd

GIT_REPOSITORIES=	piglit
GIT_REPO.piglit=	http://anongit.freedesktop.org/git/piglit.git
GIT_MODULE.piglit=	piglit
WRKSRC=			${WRKDIR}/${PKGBASE}

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

DEPENDS+=		${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
DEPENDS+=		${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=		${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=		${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=		${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

REPLACE_PYTHON=		piglit piglit-*.py replayer/replayer.py

# A static PLIST would be several megabytes and the contents rapidly changes.
GENERATE_PLIST+=	cd ${DESTDIR}${PREFIX} &&			\
			find lib/piglit \( -type f -or -type l \) -print ;

CMAKE_CONFIGURE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/piglit/lib

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../wip/mk/git-package.mk"

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/waffle/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
