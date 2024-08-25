# $NetBSD$

GIT_REPOSITORIES=	openrw
GIT_REPO.openrw=	git@github.com:rwengine/openrw.git

PKGNAME=	openrw-0
CATEGORIES=	games

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openrw.org/
COMMENT=	Open Source recreation of Grand Theft Auto III
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/openrw

USE_CMAKE=	yes

USE_LANGUAGES=	c c++


CMAKE_CONFIGURE_ARGS+=	-D_FFMPEG_AVCODEC_INCLUDE_DIRS=${PREFIX}/include/ffmpeg4
CMAKE_CONFIGURE_ARGS+=	-D_FFMPEG_AVCODEC_LIBRARY_DIRS=${PREFIX}/lib/ffmpeg4
CMAKE_CONFIGURE_ARGS+=	-D_FFMPEG_AVFORMAT_LIBRARY_DIRS=${PREFIX}/lib/ffmpeg4

.include "../../wip/mk/git-package.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
