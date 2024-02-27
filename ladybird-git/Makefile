# $NetBSD: Makefile,v 1.18 2015/09/13 07:33:05 thomasklausner Exp $

DISTNAME=	ladybird-0.0.0
CATEGORIES=	www
GIT_REPO=	https://github.com/SerenityOS/serenity.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ladybird.dev/
COMMENT=	Independent web browser from scratch from SerenityOS
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++20
GCC_REQD+=		12

CMAKE_ARGS+=		-S Ladybird
# build broken with make
CMAKE_GENERATOR=	ninja

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/cmake-pkgsrc-build/lib

SUBST_CLASSES+=		fontpath
SUBST_FILES.fontpath+=	Userland/Libraries/LibCore/StandardPaths.cpp
SUBST_SED.fontpath+=	-e "s,/usr/local/share/fonts,${PREFIX}/share/fonts,"
SUBST_MESSAGE.fontpath=	Fixing path to fonts.
SUBST_STAGE.fontpath=	pre-build

.include "../../devel/cmake/build.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
