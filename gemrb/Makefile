# $NetBSD: Makefile,v 1.14 2015/08/18 21:31:46 yhardy Exp $

DISTNAME=	gemrb-0.8.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=gemrb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gemrb.org/
COMMENT=	Open Source clone of the Infinity Engine
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

REPLACE_PYTHON=	admin/extend2da.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.8.0.1

CMAKE_ARGS+=		-DDISABLE_WERROR=1
CMAKE_ARGS+=		-DINSOURCEBUILD=1
CMAKE_ARGS+=		-DMAN_DIR:PATH=${PREFIX}/${PKGMANDIR}/man6
CMAKE_ARGS+=		-DEXAMPLE_CONF_DIR:PATH=${PREFIX}/share/examples/gemrb
CMAKE_ARGS+=		-DCMAKE_SKIP_RPATH:BOOL=FALSE
CMAKE_ARGS+=		-DSDL_BACKEND:STRING=SDL2

CFLAGS+=		-Wl,-R${PREFIX}/lib/gemrb
CXXFLAGS+=		-Wl,-R${PREFIX}/lib/gemrb

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
