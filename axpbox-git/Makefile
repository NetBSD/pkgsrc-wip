# $NetBSD$

GITHUB_PROJECT=	axpbox
GITHUB_TAG=	main
DISTNAME=	main
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=lenticularis39/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lenticularis39/axpbox/
COMMENT=	AXPbox is a fork of the discontinued es40 emulator. It emulates Alpha processor and can OpenVMS,Tru64,Linux and NetBSD
#LICENSE=

WRKSRC=			${WRKDIR}/axpbox-main
USE_TOOLS+=		pkg-config gmake
USE_PKGLOCALEDIR+=	yes
USE_CMAKE=		yes
USE_LANGUAGES=		c c++14
MAKE_ENV+=		prefix=${PREFIX}

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DCMAKE_CXX_FLAGS="-O3 -march=native"
CMAKE_ARGS+=	-DDEBUG=OFF
CMAKE_ARGS+=	-DFASTER=OFF

INSTALLATION_DIRS+=	bin

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/axpbox ${DESTDIR}${PREFIX}/bin

.include "../../devel/cmake/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
