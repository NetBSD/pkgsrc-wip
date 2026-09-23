# $NetBSD$

DISTNAME=	rio-0.5.28
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=raphamorim/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rioterm.com/
COMMENT=	Hardware-accelerated GPU terminal emulator

LICENSE=	mit

RUST_REQ=	1.92.0

WRKSRC=		${WRKDIR}/${DISTNAME}

# x11 only; Wayland is not packaged for NetBSD.  X11/xcb/xkbcommon are
# dlopened at runtime, so nothing links against them.
CARGO_ARGS=			build --release -p rioterm ${DEFAULT_CARGO_ARGS}
CARGO_NO_DEFAULT_FEATURES=	yes
CARGO_FEATURES=			x11

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config
DEPENDS+=	ncurses-[0-9]*:../../devel/ncurses

.include "options.mk"

# Restrict pkg-config to buildlink .pc files so fontconfig-sys finds pkgsrc's
# libfontconfig.so.1, not X11R7's .so.2.
PKGSRC_MAKE_ENV+=	PKG_CONFIG_LIBDIR=${BUILDLINK_DIR}/lib/pkgconfig
# mk.conf may declare X11R7 fontconfig builtin, putting fontconfig.pc in
# .x11-buildlink/ where the restricted PKG_CONFIG_LIBDIR cannot see it.
USE_BUILTIN.fontconfig=	no

# Embed rpath so the binary runs without LD_LIBRARY_PATH.
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${X11BASE}/lib
# Without this the wrapper rewrites the ${X11BASE} rpath into the buildlink
# dir and drops it, leaving the dlopens unresolvable at runtime.
BUILDLINK_PASSTHRU_RPATHDIRS+=	${X11BASE}/lib

ICON_THEMES=	yes

# Expand @PREFIX@ in the .desktop Exec line so TERMINFO_DIRS resolves.
SUBST_CLASSES+=			terminfo-dirs
SUBST_STAGE.terminfo-dirs=	pre-configure
SUBST_FILES.terminfo-dirs=	misc/rio.desktop
SUBST_VARS.terminfo-dirs=	PREFIX

INSTALLATION_DIRS+=	bin \
			share/applications \
			share/icons/hicolor/scalable/apps \
			share/terminfo \
			share/doc/rio

# Enable the wgpu GLES backend on NetBSD: wgpu and wgpu-core gate Vulkan and
# GLES behind platform allowlists that omit it.  Each edited file gets its
# .cargo-checksum.json "files" emptied so Cargo skips per-file verification.
pre-configure:
	# wgpu/build.rs: add NetBSD to vulkan and gles cfg platform conditions
	${SED} -i \
	    -e 's|target_os = "freebsd"), feature = "vulkan")|target_os = "freebsd", target_os = "netbsd"), feature = "vulkan")|' \
	    -e 's|Emscripten), feature = "gles")|Emscripten, target_os = "netbsd"), feature = "gles")|' \
	    ${WRKDIR}/vendor/wgpu-30.0.1/build.rs
	${SED} -i 's/"files":{[^}]*}/"files":{}/' \
	    ${WRKDIR}/vendor/wgpu-30.0.1/.cargo-checksum.json
	# wgpu-core/build.rs: add NetBSD to windows_linux_android alias
	${SED} -i \
	    -e 's|target_os = "freebsd") }|target_os = "freebsd", target_os = "netbsd") }|' \
	    ${WRKDIR}/vendor/wgpu-core-30.0.1/build.rs
	# wgpu-core/Cargo.toml: add NetBSD to target dep + activate wgpu-hal features directly
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
	# wgpu-core-deps-windows-linux-android/Cargo.toml: unconditional wgpu-hal dependency
	${SED} -i \
	    -e "s|\[target\.'cfg(any(windows, target_os = \"linux\", target_os = \"android\", target_os = \"freebsd\"))'\.dependencies\.wgpu-hal\]|[dependencies.wgpu-hal]|" \
	    ${WRKDIR}/vendor/wgpu-core-deps-windows-linux-android-30.0.1/Cargo.toml
	${SED} -i 's/"files":{[^}]*}/"files":{}/' \
	    ${WRKDIR}/vendor/wgpu-core-deps-windows-linux-android-30.0.1/.cargo-checksum.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rio \
		${DESTDIR}${PREFIX}/bin/rio
	${INSTALL_DATA} ${WRKSRC}/misc/rio.desktop \
		${DESTDIR}${PREFIX}/share/applications/rio.desktop
	${INSTALL_DATA} ${WRKSRC}/misc/logo.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/rio.svg
	# terminfo for TERM=xterm-rio.
	${LOCALBASE}/bin/tic -x -o ${DESTDIR}${PREFIX}/share/terminfo \
		${WRKSRC}/misc/rio.terminfo
	${INSTALL_DATA} ${FILESDIR}/README.NetBSD \
		${DESTDIR}${PREFIX}/share/doc/rio/README.NetBSD
.if !empty(PKG_OPTIONS:Mmanual)
	${SCDOC} < ${WRKSRC}/extra/man/rio.1.scd > \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rio.1
	${SCDOC} < ${WRKSRC}/extra/man/rio.5.scd > \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/rio.5
	${SCDOC} < ${WRKSRC}/extra/man/rio-bindings.5.scd > \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/rio-bindings.5
.endif

.include "cargo-depends.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
