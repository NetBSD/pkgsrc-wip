# $NetBSD$

DISTNAME=	mayo-0.9.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=fougue/}
GITHUB_PROJECT=	mayo
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fougue/mayo
COMMENT=	3D CAD viewer and converter based on Qt + OpenCascade 
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS=	git

CMAKE_CONFIGURE_ARGS+=	-DMayo_BuildPluginAssimp="ON"

.include "../../mk/bsd.prefs.mk"

.include "../../devel/cmake/build.mk"

.include "../../wip/occt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
