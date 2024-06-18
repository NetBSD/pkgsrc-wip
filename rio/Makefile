# $NetBSD$

DISTNAME=	rio-0.1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=raphamorim/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://raphamorim.io/rio/
COMMENT=	Hardware-accelerated GPU terminal emulator
LICENSE=	mit

TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config

.include "../../mk/bsd.prefs.mk"

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
.if ${OPSYS} != "Darwin"
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libxkbcommon}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libxkbcommon}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.fontconfig}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.freetype2}/lib
.endif

.if ${OPSYS} == "NetBSD" && exists(${X11BASE}/lib/X11/locale/lib/common/xlcUTF8Load.so)
# This works around XIM errors when RTLD local-binding libX11.
# See x11/alacritty for details.
SUBST_CLASSES+=		rtld
SUBST_MESSAGE.rtld=	amend RTLD_GLOBAL
SUBST_STAGE.rtld=	pre-configure
SUBST_FILES.rtld=	../vendor/x11-dl-*/src/link.rs
SUBST_SED.rtld=		-e 's,libc::RTLD_LAZY,& | libc::RTLD_GLOBAL,g'
.endif

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rio \
		${DESTDIR}${PREFIX}/bin

.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
.endif

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		x11

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
