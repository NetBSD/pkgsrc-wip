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

CMAKE_CONFIGURE_ARGS+=	-DSOQT_USE_QT5=OFF -DSOQT_USE_QT6=ON -DSOQT_VERBOSE=ON

REPLACE_PERL+=	cfg/gendsp.pl.in cfg/doxy4win.pl

SUBST_CLASSES=		unbl3
SUBST_MESSAGE.unbl3=	Undoing buildlink3 paths in cmake exports.
SUBST_STAGE.unbl3=	post-install
SUBST_FILES.unbl3+=	${DESTDIR}${PREFIX}/lib/cmake/${DISTNAME}/soqt-export.cmake
SUBST_SED.unbl3+=	-e "s|${BUILDLINK_DIR}/lib/||g"
SUBST_SED.unbl3+=	-e "s|${BUILDLINK_DIR}/include|${PREFIX}/include|g"

.include "../../mk/bsd.prefs.mk"

.include "../../devel/cmake/build.mk"

.include "../../wip/Coin/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
