# $NetBSD$

DISTNAME=	wezterm-0.0.20250216
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=wezterm/}
GITHUB_TAG=	ee0c04e735fb94cb5119681f704fb7fa6731e713

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://wezterm.org/
COMMENT=	Powerful cross-platform terminal emulator and multiplexer
LICENSE=	mit AND ofl-v1.1

# wezterm just takes HEAD, but that will lead to distfile problems; hardcode the heads as of 20250216
GITHUB_SUBMODULES+=	harfbuzz harfbuzz b97ef6c702910f4317cc364c7d67c380047b237f deps/harfbuzz/harfbuzz
GITHUB_SUBMODULES+=	glennrp libpng b525503b78392335a43558c6a053e0209140762d deps/freetype/libpng
GITHUB_SUBMODULES+=	madler zlib 7108497fda9d4536a1afade7f42266e06dca4488 deps/freetype/zlib
GITHUB_SUBMODULES+=	freetype freetype b1f47850878d232eea372ab167e760ccac4c4e32 deps/freetype/freetype2
# xcb-imdkit-rs _also_ needs a submodule
GITHUB_SUBMODULES+=	fcitx xcb-imdkit 44f5c8219bcae9e6afc2391dc50486efcf0bdf06 ../xcb-imdkit-rs-${XCB_IMDKIT_RS_REV}/deps/xcb-imdkit

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
XCB_IMDKIT_RS_REV=	358e226573461fe540efb920e2aad740e3c6fab1
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		xcb-imdkit-rs-${XCB_IMDKIT_RS_REV}.tar.gz

SITES.xcb-imdkit-rs-${XCB_IMDKIT_RS_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=wez/}xcb-imdkit-rs/archive/${XCB_IMDKIT_RS_REV}.tar.gz

CHECK_PORTABILITY_SKIP=	get-deps

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/fish/completions
INSTALLATION_DIRS+=	share/icons/hicolor/symbolic/apps
INSTALLATION_DIRS+=	share/zsh/site-functions

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wezterm \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wezterm-gui \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/wezterm-mux-server \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/strip-ansi-escapes \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/sync-color-schemes \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/generate-bidi \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/assets/wezterm.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/assets/shell-completion/bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/wezterm
	${INSTALL_DATA} ${WRKSRC}/assets/shell-completion/fish \
		${DESTDIR}${PREFIX}/share/fish/completions/wezterm.fish
	${INSTALL_DATA} ${WRKSRC}/assets/shell-completion/zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_wezterm
	${INSTALL_DATA} ${WRKSRC}/assets/icon/wezterm-icon.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/symbolic/apps/org.wezfurlong.wezterm.svg

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
