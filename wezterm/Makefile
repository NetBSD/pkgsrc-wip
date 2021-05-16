# $NetBSD$

GITHUB_PROJECT=	wezterm
DISTNAME=	wezterm-20210502-154244-3f7122cb-src
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=wez/}
GITHUB_RELEASE=	20210502-154244-3f7122cb

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/wez/wezterm/
COMMENT=	Terminal emulator
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=			${WRKDIR}/wezterm-20210502-154244-3f7122cb
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

.include "cargo-depends.mk"

PKGCONFIG_OVERRIDE+=	deps/freetype/libpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	deps/freetype/libpng/scripts/libpng.pc.in
PKGCONFIG_OVERRIDE+=	deps/freetype/zlib/contrib/minizip/minizip.pc.in
PKGCONFIG_OVERRIDE+=	deps/freetype/zlib/zlib.pc.in
PKGCONFIG_OVERRIDE+=	deps/harfbuzz/harfbuzz/src/harfbuzz-gobject.pc.in
PKGCONFIG_OVERRIDE+=	deps/harfbuzz/harfbuzz/src/harfbuzz-icu.pc.in
PKGCONFIG_OVERRIDE+=	deps/harfbuzz/harfbuzz/src/harfbuzz-subset.pc.in
PKGCONFIG_OVERRIDE+=	deps/harfbuzz/harfbuzz/src/harfbuzz.pc.in

post-patch:
	${CP} ${FILESDIR}/netbsd.rs ${WRKDIR}/vendor/ioctl-rs-0.1.6/src/os/

.include "../../devel/wayland/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
