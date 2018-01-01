# $NetBSD: Makefile,v 1.2 2015/09/06 20:10:45 yhardy Exp $

GITHUB_PROJECT=	Commander-Genius
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-2.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=gerstrong/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v200Release
DISTFILES=	${DEFAULT_DISTFILES} GsKit-${GSKIT_VER}.tar.gz
GSKIT_VER=	f925d1362f0bc99598141a97d5a200d5e6a41391
SITES.GsKit-${GSKIT_VER}.tar.gz= \
-https://github.com/gerstrong/GsKit/archive/${GSKIT_VER}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clonekeenplus.sourceforge.net/
COMMENT=	The ultimate Commander Keen interpreter
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/Commander-Genius-${GITHUB_TAG:S/^v//}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=LINUX64
CMAKE_ARGS+=	-DGAMES_SHAREDIR=${PREFIX}/share
CMAKE_ARGS+=	-DDOCDIR=${PREFIX}/share/doc/commandergenius
#CMAKE_ARGS+=	-DUSE_SDL2=NO

INSTALLATION_DIRS=	bin share/doc/commandergenius

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${MV} ${WRKDIR}/GsKit-${GSKIT_VER}/* ${WRKSRC}/GsKit/

post-install:
	cd ${WRKSRC}/vfsroot && ${FIND} . -type d | while read d; do \
		${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/commandergenius/$$d" || exit 1; \
	done
	cd ${WRKSRC}/vfsroot && ${FIND} . -type f | while read f; do \
		${INSTALL_DATA} "$$f" "${DESTDIR}${PREFIX}/share/commandergenius/$${f%/*}" || exit 1; \
	done

.include "options.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
