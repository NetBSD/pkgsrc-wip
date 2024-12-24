# $NetBSD$

DISTNAME=	libopenshot-0.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenShot/}
GITHUB_PROJECT=	libopenshot
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://www.openshot.org/libopenshot/
COMMENT=	Powerful, cross-platform open-source C++ video editing library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
FORCE_CXX_STD=	gnu++17

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	swig4>=4.0.0:../../wip/swig4

CMAKE_CONFIGURE_ARGS+=	-DRUBY_EXECUTABLE=${RUBY}

# for tests
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

.include "../../devel/catch2/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../net/cppzmq/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../wip/libopenshot-audio/buildlink3.mk"
.include "../../graphics/babl/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../devel/unittest-cpp/buildlink3.mk"

.include "../../devel/cmake/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
