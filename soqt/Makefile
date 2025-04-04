# $NetBSD: $

DISTNAME=		SoQt-1.6.3
PKGNAME=		${DISTNAME:tl}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=coin3d/}
GITHUB_PROJECT=		soqt
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=	rumko@NetBSD.org
HOMEPAGE=	http://www.coin3d.org/lib/soqt/
COMMENT=	Legacy library that provides glue between Coin and Qt
LICENSE=	gnu-gpl-v2

GITHUB_SUBMODULES=	coin3d soanydata soanydata-1_1_0 data \
			coin3d sogui 426cd49 src/Inventor/Qt/common

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

REPLACE_PERL+=	cfg/gendsp.pl.in cfg/doxy4win.pl

SUBST_CLASSES=		cmake
SUBST_STAGE.cmake=	post-install
SUBST_FILES.cmake+=	cmake-pkgsrc-build/src/soqt-export.cmake
SUBST_SED.cmake+=	-e 's|${WRKDIR}/.buildlink|${PREFIX}|g'

.include "../../mk/bsd.prefs.mk"

.include "../../devel/cmake/build.mk"

.include "../../wip/Coin/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
