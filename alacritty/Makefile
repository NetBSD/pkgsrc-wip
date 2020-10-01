# $NetBSD$

DISTNAME=	alacritty-0.5.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=alacritty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jwilm/alacritty
COMMENT=	Cross-platform, GPU-accelerated terminal emulator
LICENSE=	apache-2.0

BUILD_DEPENDS+=		cmake-[0-9]*:../../devel/cmake

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config	# for fontconfig-sys

.include "cargo-depends.mk"

#DEPENDS+=	xcb-[0-9]*:../../x11/xcb

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.freetype2}/lib
MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}

# TODO: doesn't include dlopen.bl3.mk?
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

# The xcb 0.8.2 crate depends on any version of python 3.
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool
BUILD_DEPENDS+=			${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
#REPLACE_PYTHON+=		../vendor/xcb-0.8.2/rs-client.py
#REPLACE_PYTHON+=		../vendor/xcb-0.8.2/build.rs

INSTALLATION_DIRS=	bin share/examples/alacritty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/alacritty ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/alacritty.yml ${DESTDIR}${PREFIX}/share/examples/alacritty

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
#.include "../../lang/rust/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
# .include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
