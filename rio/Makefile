# $NetBSD$

DISTNAME=	rio-0.4.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=raphamorim/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rioterm.com/
COMMENT=	Hardware-accelerated GPU terminal emulator

LICENSE=	mit

RUST_REQ=	1.92.0

WRKSRC=		${WRKDIR}/${DISTNAME}

# Build only the terminal binary; x11 only (Wayland not packaged for NetBSD).
# X11/xkbcommon/xcb are loaded at runtime via dlopen (x11-dl, x11rb, xkbcommon-dl).
CARGO_ARGS=			build --release -p rioterm ${DEFAULT_CARGO_ARGS}
CARGO_NO_DEFAULT_FEATURES=	yes
CARGO_FEATURES=			x11

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config

# Force pkg-config to see only buildlink'd .pc files so fontconfig-sys picks
# up pkgsrc's libfontconfig.so.1 instead of X11R7's .so.2.
PKGSRC_MAKE_ENV+=	PKG_CONFIG_LIBDIR=${BUILDLINK_DIR}/lib/pkgconfig

# Embed rpath for pkgsrc libs so the binary finds them without LD_LIBRARY_PATH.
RUSTFLAGS+=	-C link-arg=-Wl,-rpath,${PREFIX}/lib
RUSTFLAGS+=	-C link-arg=-Wl,-rpath,/usr/X11R7/lib

ICON_THEMES=	yes

INSTALLATION_DIRS=	bin \
			share/applications \
			share/icons/hicolor/scalable/apps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rio \
		${DESTDIR}${PREFIX}/bin/rio
	${INSTALL_DATA} ${WRKSRC}/misc/rio.desktop \
		${DESTDIR}${PREFIX}/share/applications/rio.desktop
	${INSTALL_DATA} ${WRKSRC}/misc/logo.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/rio.svg

.include "cargo-depends.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
