# $NetBSD$

DISTNAME=	photocraft-0.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=storytold/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/storytold/photocraft/
COMMENT=	Layered image editor with PSD support, written in Rust
LICENSE=	mit OR apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}
RUST_REQ=	1.95.0

# Only the desktop app and the CLI; the default members also pull in xtask.
CARGO_ARGS=	build --release ${DEFAULT_CARGO_ARGS} \
		-p photocraft -p photocraft-cli

# winit and wgpu dlopen libX11/libxkbcommon/libwayland/libEGL at runtime.
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${X11BASE}/lib
BUILDLINK_PASSTHRU_RPATHDIRS+=	${X11BASE}/lib

USE_TOOLS+=	pax

ICON_THEMES=	yes
APP_ID=		ai.storyteller.photocraft

# The metainfo template carries the version and release date.
SUBST_CLASSES+=		metainfo
SUBST_STAGE.metainfo=	pre-configure
SUBST_FILES.metainfo=	packaging/linux/${APP_ID}.metainfo.xml.in
SUBST_SED.metainfo=	-e 's,@VERSION@,${PKGVERSION_NOREV},g'
SUBST_SED.metainfo+=	-e 's,@DATE@,2026-10-07,g'

INSTALLATION_DIRS+=	bin \
			share/applications \
			share/metainfo \
			share/mime/packages \
			share/doc/photocraft

# Enable the wgpu Vulkan and GLES backends on NetBSD: wgpu and wgpu-core
# gate them behind platform allowlists that omit it, which leaves no
# adapter at runtime.  Same edits as wip/rio.  Each edited file gets its
# .cargo-checksum.json "files" emptied so Cargo skips per-file verification.
pre-configure:
	${SED} -i \
	    -e 's|target_os = "freebsd"), feature = "vulkan")|target_os = "freebsd", target_os = "netbsd"), feature = "vulkan")|' \
	    -e 's|Emscripten), feature = "gles")|Emscripten, target_os = "netbsd"), feature = "gles")|' \
	    ${WRKDIR}/vendor/wgpu-30.0.1/build.rs
	${SED} -i 's/"files":{[^}]*}/"files":{}/' \
	    ${WRKDIR}/vendor/wgpu-30.0.1/.cargo-checksum.json
	${SED} -i \
	    -e 's|target_os = "freebsd") }|target_os = "freebsd", target_os = "netbsd") }|' \
	    ${WRKDIR}/vendor/wgpu-core-30.0.1/build.rs
	${SED} -i \
	    -e "s|'cfg(any(windows, target_os = \"linux\", target_os = \"android\", target_os = \"freebsd\"))'\.dependencies\.wgpu-core-deps|'cfg(any(windows, target_os = \"linux\", target_os = \"android\", target_os = \"freebsd\", target_os = \"netbsd\"))'.dependencies.wgpu-core-deps|" \
	    -e 's|vulkan = \["wgpu-core-deps-windows-linux-android/vulkan"\]|vulkan = ["wgpu-core-deps-windows-linux-android/vulkan", "wgpu-hal/vulkan"]|' \
	    ${WRKDIR}/vendor/wgpu-core-30.0.1/Cargo.toml
	${AWK} '/"wgpu-core-deps-emscripten\/gles",$$/ { print; print "    \"wgpu-hal/gles\","; next } { print }' \
	    ${WRKDIR}/vendor/wgpu-core-30.0.1/Cargo.toml > \
	    ${WRKDIR}/vendor/wgpu-core-30.0.1/Cargo.toml.new
	${MV} ${WRKDIR}/vendor/wgpu-core-30.0.1/Cargo.toml.new \
	    ${WRKDIR}/vendor/wgpu-core-30.0.1/Cargo.toml
	${SED} -i 's/"files":{[^}]*}/"files":{}/' \
	    ${WRKDIR}/vendor/wgpu-core-30.0.1/.cargo-checksum.json
	${SED} -i \
	    -e "s|\[target\.'cfg(any(windows, target_os = \"linux\", target_os = \"android\", target_os = \"freebsd\"))'\.dependencies\.wgpu-hal\]|[dependencies.wgpu-hal]|" \
	    ${WRKDIR}/vendor/wgpu-core-deps-windows-linux-android-30.0.1/Cargo.toml
	${SED} -i 's/"files":{[^}]*}/"files":{}/' \
	    ${WRKDIR}/vendor/wgpu-core-deps-windows-linux-android-30.0.1/.cargo-checksum.json

do-install:
.for b in photocraft photocraft-cli
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${b} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/packaging/linux/${APP_ID}.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/packaging/linux/${APP_ID}.mime.xml \
		${DESTDIR}${PREFIX}/share/mime/packages/${APP_ID}.xml
	${INSTALL_DATA} ${WRKSRC}/packaging/linux/${APP_ID}.metainfo.xml.in \
		${DESTDIR}${PREFIX}/share/metainfo/${APP_ID}.metainfo.xml
	cd ${WRKSRC}/assets/app-icon && ${PAX} -rw hicolor \
		${DESTDIR}${PREFIX}/share/icons
.for f in README.md LICENSE-MIT LICENSE-APACHE NOTICE
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/photocraft
.endfor

.include "cargo-depends.mk"

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
