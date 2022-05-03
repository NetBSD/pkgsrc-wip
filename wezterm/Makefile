# $NetBSD$

GITHUB_PROJECT=	wezterm
DISTNAME=	wezterm-20220408-101518-b908e2dd-src
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=wez/}
GITHUB_RELEASE=	20220408-101518-b908e2dd
DISTFILES+=	${DISTNAME}.tar.gz

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/wez/wezterm/
COMMENT=	Terminal emulator
LICENSE=	mit AND ofl-v1.1

WRKSRC=			${WRKDIR}/wezterm-${GITHUB_RELEASE}
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

DISTFILES+=	xkbcommon-0.5.0-5cc8f233ac2b8bfa0d7a26fd981b77e68c3f2219.tar.gz
SITES.xkbcommon-0.5.0-5cc8f233ac2b8bfa0d7a26fd981b77e68c3f2219.tar.gz= \
	-https://github.com/wez/xkbcommon-rs/archive/5cc8f233ac2b8bfa0d7a26fd981b77e68c3f2219.tar.gz

.include "cargo-depends.mk"

PKGCONFIG_OVERRIDE+=	deps/freetype/libpng/libpng.pc.in
PKGCONFIG_OVERRIDE+=	deps/freetype/libpng/scripts/libpng.pc.in
PKGCONFIG_OVERRIDE+=	deps/freetype/zlib/contrib/minizip/minizip.pc.in
PKGCONFIG_OVERRIDE+=	deps/freetype/zlib/zlib.pc.in
PKGCONFIG_OVERRIDE+=	deps/harfbuzz/harfbuzz/src/harfbuzz-gobject.pc.in
PKGCONFIG_OVERRIDE+=	deps/harfbuzz/harfbuzz/src/harfbuzz-icu.pc.in
PKGCONFIG_OVERRIDE+=	deps/harfbuzz/harfbuzz/src/harfbuzz-subset.pc.in
PKGCONFIG_OVERRIDE+=	deps/harfbuzz/harfbuzz/src/harfbuzz.pc.in

SUBST_CLASSES+=		sshdtest
SUBST_STAGE.sshdtest=	pre-configure
SUBST_MESSAGE.sshdtest=	Do not print malformed sshd config
SUBST_FILES.sshdtest=	wezterm-ssh/tests/sshd.rs
SUBST_SED.sshdtest+=	-e 's,std::fs::write,//std::fs::write,g'

post-extract:
	${MV} ${WRKDIR}/xkbcommon-rs-5cc8f233ac2b8bfa0d7a26fd981b77e68c3f2219 ${WRKDIR}/vendor/xkbcommon-0.5.0
	${RUN}${PRINTF} '{"package":"%s","files":{}}'   \
	  `${DIGEST} sha256 < ${_DISTDIR}/xkbcommon-0.5.0-5cc8f233ac2b8bfa0d7a26fd981b77e68c3f2219.tar.gz` \
	  > ${CARGO_VENDOR_DIR}/xkbcommon-0.5.0/.cargo-checksum.json

post-patch:
	${CP} ${FILESDIR}/netbsd.rs ${WRKDIR}/vendor/ioctl-rs-0.1.6/src/os/
	rm ${WRKSRC}/wezterm-gui/src/update.rs

do-build:
	# Do not build ssh for now.
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo ${CARGO_ARGS} --manifest-path wezterm/Cargo.toml
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo ${CARGO_ARGS} --manifest-path wezterm-gui/Cargo.toml
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo ${CARGO_ARGS} --manifest-path wezterm-mux-server/Cargo.toml
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo ${CARGO_ARGS} --manifest-path strip-ansi-escapes/Cargo.toml

post-build:
	tic -x -o ${WRKSRC}/terminfo ${WRKSRC}/termwiz/data/wezterm.terminfo

do-test:
	# Alpine Linux writes about tests getting stuck and sshd needs to be killed
	cd ${WRKSRC} && ${MAKEENV} cargo test --frozen

.include "../../devel/wayland/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
