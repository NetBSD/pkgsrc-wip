# $NetBSD$

DISTNAME=	libopenshot-0.2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenShot/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://www.openshot.org/libopenshot/
COMMENT=	Powerful, cross-platform open-source C++ video editing library
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libopenshot-0.2.5
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

DEPENDS+=	swig4>=4.0.0:../../wip/swig4

.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../wip/cppzmq/buildlink3.mk"
.include "../../wip/libopenshot-audio/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../devel/unittest-cpp/buildlink3.mk"

#.include "../../lang/python/pyversion.mk"
.include "../../lang/python37/buildlink3.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
