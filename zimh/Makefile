# $NetBSD$

# Note on the version: this package currently has a high development speed but
# no releases yet. Typically, to get the latest version, you just need to update
# the GITHUB_TAG and put the correct date in PKGNAME's version part.
DISTNAME=	zimh-0.0.0
PKGNAME=	zimh-0.0.0.2026.05.09.00  # date + seqnr per day
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=pmetzger/}
GITHUB_PROJECT=	zimh
GITHUB_TAG=	ce0bfeac101ca289ff97e91aa8bbf36d99ef837c
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/pmetzger/zimh/
COMMENT=	Hard fork of open-simh, with different development cycle
LICENSE=	mit

USE_TOOLS+=	bison git pkg-config

TOOL_DEPENDS+=  ninja-build-[0-9]*:../../devel/ninja-build
#TOOL_DEPENDS+=	cmocka>=1.1.8:../../devel/cmocka
TOOL_DEPENDS+=	cmocka>=2.0.1:../../wip/cmocka201
DEPENDS+=       dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

CMAKE_CONFIGURE_ARGS+=	-DWITH_UNIT_TESTS=ON
#CMAKE_CONFIGURE_ARGS+=	-DWITH_UNIT_TESTS=OFF

.include "../../devel/cmake/build.mk"
#.include "../../devel/cmocka/buildlink3.mk"  # enabling this makes cmake find cmocka
.include "../../wip/cmocka201/buildlink3.mk"  # enabling this makes cmake find cmocka
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/libslirp/buildlink3.mk"
#.include "../../wip/libslirp491/buildlink3.mk"
#.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
