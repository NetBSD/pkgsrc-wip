# $NetBSD$

DISTNAME=	navit-gps
PKGNAME=	navit-0
CATEGORIES=	geography

MAINTAINER=	fekete.zoltan@minux.hu
HOMEPAGE=	https://github.com/navit-gps/navit
COMMENT=	GPS car navigation system
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=   navit-gps
GIT_REPO.navit-gps= https://github.com/navit-gps/navit.git
GIT_REVISION=       d2413503fc583c1d96e3247f2d1621dc4f50b362
_GIT_FLAGS?=        --depth 1

CONFLICTS=	navit-[0-9]*

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CFLAGS.NetBSD+= -DUSE_SYS_ENDIAN_H

USE_TOOLS+=	cmake pkg-config

CMAKE_ARGS+=    -DLIB_DIR=${PREFIX}/lib/navit
CMAKE_ARGS+=    -DMAN_DIR=${PREFIX}/${PKGMANDIR}/man1
CMAKE_ARGS+=    -DUSE_PLUGINS=0
CMAKE_ARGS+=	-DSAMPLE_MAP=1
CMAKE_ARGS+=	-DSVG2PNG=0
CMAKE_ARGS+=	-DUSE_NATIVE_LANGUAGE_SUPPORT=1


.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
+BUILDLINK_API_DEPENDS.png+=		  png>=1.6
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"
+BUILDLINK_API_DEPENDS.freetype2+=	  freetype2>=2.9
.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		  glib2>=2.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=opt:-ldl:${BUILDLINK_LDADD.dl:M*}
.include "../../geography/gpsd/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
