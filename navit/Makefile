# $NetBSD$

GITHUB_PROJECT=	navit
DISTNAME=	v0.5.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=    1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=navit-gps/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	fekete.zoltan@minux.hu
HOMEPAGE=	https://github.com/navit-gps/navit/
COMMENT=	GPS car navigation system
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/navit-0.5.1
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=		cmake pkg-config

CMAKE_ARGS+=    -DLIB_DIR=${PREFIX}/lib/navit \
                -DMAN_DIR=${PREFIX}/man \
		-DUSE_PLUGINS=0 \
		-DSAMPLE_MAP=0 \
		-DSVG2PNG=0 \
		-DUSE_NATIVE_LANGUAGE_SUPPORT=0
		

# DEPENDS+=       gettext-lib-[0-9]*:../../devel/gettext-lib
DEPENDS+=       png>=1.6:../../graphics/png
DEPENDS+=       freetype2>=2.9:../../graphics/freetype2
DEPENDS+=       glib2>=2.0:../../devel/glib2
DEPENDS+=       python27-[0-9]*:../../lang/python27
DEPENDS+=       gtk2-[0-9]*:../../x11/gtk2
DEPENDS+=       librsvg-[2-9]*:../../graphics/librsvg
DEPENDS+=       imlib-[0-9]*:../../graphics/imlib2


.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
# .include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=opt:-ldl:${BUILDLINK_LDADD.dl:M*}
.include "../../mk/bsd.pkg.mk"
