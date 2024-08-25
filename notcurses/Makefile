# $NetBSD$

DISTNAME=		notcurses-3.0.9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=dankamongmen/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://nick-black.com/dankwiki/index.php/Notcurses
COMMENT=		TUI library for modern terminal emulators
LICENSE=		apache-2.0

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=		-DUSE_PANDOC=OFF

PKGCONFIG_OVERRIDE+=	tools/notcurses++.pc.in
PKGCONFIG_OVERRIDE+=	tools/notcurses-core.pc.in
PKGCONFIG_OVERRIDE+=	tools/notcurses-ffi.pc.in
PKGCONFIG_OVERRIDE+=	tools/notcurses.pc.in

# TODO: borrow more from <https://github.com/freebsd/freebsd-ports/tree/main/devel/notcurses>

.include "../../devel/cmake/build.mk"
.include "../../devel/libdeflate/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
#.include "../../graphics/qr-code-generator/buildlink3.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../wip/doctest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
