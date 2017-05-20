# $NetBSD$

DISTNAME=	openmw-0.41.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenMW/}

HOMEPAGE=	https://openmw.org/
COMMENT=	Free game engine reimplementation for TES III: Morrowind
LICENSE=	gnu-gpl-v3

GITHUB_TAG=	openmw-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.bullet+=	bullet>=2.83
BUILDLINK_API_DEPENDS.osg+=	osg>=3.3.4

.include "../../archivers/unshield/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../wip/bullet/buildlink3.mk" # XXX requires version in wip
.include "../../wip/mygui-git/buildlink3.mk" # XXX
.include "../../wip/osg/buildlink3.mk" # XXX requires version in wip
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
