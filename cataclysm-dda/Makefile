# $NetBSD: Makefile,v 1.1 2015/08/18 21:49:07 yhardy Exp $

DISTNAME=	${GITHUB_TAG}
PKGNAME=	cataclysm-dda-0.12
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=CleverRaven/}
GITHUB_PROJECT=	Cataclysm-DDA
GITHUB_TAG=	0.C
DIST_SUBDIR=	cataclysm-dda

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://en.cataclysmdda.com/
COMMENT=	Roguelike set in a post-apocalyptic world
LICENSE=	cc-by-sa-v3.0

#USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake msgfmt pkg-config

CFLAGS+=	-DCATA_NO_CPP11_STRING_CONVERSIONS
CXXFLAGS+=	-DCATA_NO_CPP11_STRING_CONVERSIONS
LDFLAGS+=	${BUILDLINK_LDADD.gettext}

REPLACE_SH+=	lang/compile_mo.sh


SUBST_CLASSES+=			fix-ncurses
SUBST_STAGE.fix-ncurses=	pre-configure
SUBST_MESSAGE.fix-ncurses=	Fixing ncurses configuration.
SUBST_FILES.fix-ncurses=	Makefile
SUBST_SED.fix-ncurses=		-e 's,ncursesw5-config,ncursesw6-config,g'

BUILD_MAKE_FLAGS+=	DYNAMIC_LINKING=1 RELEASE=1 USE_HOME_DIR=1
BUILD_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	DYNAMIC_LINKING=1 RELEASE=1 USE_HOME_DIR=1
INSTALL_MAKE_FLAGS+=	INSTALL_DATA="${INSTALL_DATA}"
INSTALL_MAKE_FLAGS+=	INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"
INSTALL_MAKE_FLAGS+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

LUA_VERSIONS_INCOMPATIBLE=	51

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
