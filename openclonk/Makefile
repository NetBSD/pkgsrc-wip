# $NetBSD$

PKGNAME=	openclonk-${VERSION}
DISTNAME=	openclonk-${PKGVERSION_NOREV}-src
VERSION=	8.1
CATEGORIES=	games
MASTER_SITES=	http://www.openclonk.org/builds/release/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://www.openclonk.org/
COMMENT=	Open source successor of the Clonk gaming series
LICENSE=	isc

WRKSRC=		${WRKDIR}/openclonk-release-${PKGVERSION_NOREV}-src
EXTRACT_USING=	gtar
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GCC_REQD+=	4.9

#CMAKE_ARGS+=	-DCMAKE_INTERPROCEDURAL_OPTIMIZATION=FALSE
MAKE_FLAGS+=	VERBOSE=1

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
