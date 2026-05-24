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

.include "options.mk"

# Force pkg-config to see only buildlink'd .pc files so fontconfig-sys picks
# up pkgsrc's libfontconfig.so.1 instead of X11R7's .so.2.
PKGSRC_MAKE_ENV+=	PKG_CONFIG_LIBDIR=${BUILDLINK_DIR}/lib/pkgconfig

# Embed rpath for pkgsrc libs so the binary finds them without LD_LIBRARY_PATH.
RUSTFLAGS+=	-C link-arg=-Wl,-rpath,${PREFIX}/lib
RUSTFLAGS+=	-C link-arg=-Wl,-rpath,/usr/X11R7/lib

ICON_THEMES=	yes

# Substitute PREFIX into the .desktop Exec line so TERMINFO_DIRS points to
# the installed terminfo directory at runtime.
SUBST_CLASSES+=			terminfo-dirs
SUBST_STAGE.terminfo-dirs=	post-patch
SUBST_FILES.terminfo-dirs=	misc/rio.desktop
SUBST_VARS.terminfo-dirs=	PREFIX

INSTALLATION_DIRS+=	bin \
			share/applications \
			share/icons/hicolor/scalable/apps \
			share/terminfo


# Patch vendor crates to enable wgpu GLES backend on NetBSD.
#
# wgpu and wgpu-core have explicit platform allowlists (Windows/Linux/Android/FreeBSD/Apple)
# for their Vulkan and GLES backends.  Each patched file is followed by a checksum
# reset ("files":{}) so Cargo skips per-file verification of the modified entries.
pre-configure:
	# wgpu/build.rs: add NetBSD to vulkan and gles cfg platform conditions
	${SED} -i \
	    -e 's|target_os = "freebsd"), feature = "vulkan")|target_os = "freebsd", target_os = "netbsd"), feature = "vulkan")|' \
	    -e 's|Emscripten), feature = "gles")|Emscripten, target_os = "netbsd"), feature = "gles")|' \
	    ${WRKDIR}/vendor/wgpu-28.0.0/build.rs
	${SED} -i 's/"files":{[^}]*}/"files":{}/' \
	    ${WRKDIR}/vendor/wgpu-28.0.0/.cargo-checksum.json
	# wgpu-core/build.rs: add NetBSD to windows_linux_android alias
	${SED} -i \
	    -e 's|target_os = "freebsd") }|target_os = "freebsd", target_os = "netbsd") }|' \
	    ${WRKDIR}/vendor/wgpu-core-28.0.1/build.rs
	# wgpu-core/Cargo.toml: add NetBSD to target dep + activate wgpu-hal features directly
	${SED} -i \
	    -e "s|'cfg(any(windows, target_os = \"linux\", target_os = \"android\", target_os = \"freebsd\"))'\.dependencies\.wgpu-core-deps|'cfg(any(windows, target_os = \"linux\", target_os = \"android\", target_os = \"freebsd\", target_os = \"netbsd\"))'.dependencies.wgpu-core-deps|" \
	    -e 's|vulkan = \["wgpu-core-deps-windows-linux-android/vulkan"\]|vulkan = ["wgpu-core-deps-windows-linux-android/vulkan", "wgpu-hal/vulkan"]|' \
	    ${WRKDIR}/vendor/wgpu-core-28.0.1/Cargo.toml
	${AWK} '/"wgpu-core-deps-emscripten\/gles",$$/ { print; print "    \"wgpu-hal/gles\","; next } { print }' \
	    ${WRKDIR}/vendor/wgpu-core-28.0.1/Cargo.toml > \
	    ${WRKDIR}/vendor/wgpu-core-28.0.1/Cargo.toml.new
	${MV} ${WRKDIR}/vendor/wgpu-core-28.0.1/Cargo.toml.new \
	    ${WRKDIR}/vendor/wgpu-core-28.0.1/Cargo.toml
	${SED} -i 's/"files":{[^}]*}/"files":{}/' \
	    ${WRKDIR}/vendor/wgpu-core-28.0.1/.cargo-checksum.json
	# wgpu-core-deps-windows-linux-android/Cargo.toml: unconditional wgpu-hal dependency
	${SED} -i \
	    -e "s|\[target\.'cfg(any(windows, target_os = \"linux\", target_os = \"android\", target_os = \"freebsd\"))'\.dependencies\.wgpu-hal\]|[dependencies.wgpu-hal]|" \
	    ${WRKDIR}/vendor/wgpu-core-deps-windows-linux-android-28.0.0/Cargo.toml
	${SED} -i 's/"files":{[^}]*}/"files":{}/' \
	    ${WRKDIR}/vendor/wgpu-core-deps-windows-linux-android-28.0.0/.cargo-checksum.json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rio \
		${DESTDIR}${PREFIX}/bin/rio
	${INSTALL_DATA} ${WRKSRC}/misc/rio.desktop \
		${DESTDIR}${PREFIX}/share/applications/rio.desktop
	${INSTALL_DATA} ${WRKSRC}/misc/logo.svg \
		${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps/rio.svg
	# Install terminfo so programs inside rio recognise TERM=xterm-rio.
	${LOCALBASE}/bin/tic -x -o ${DESTDIR}${PREFIX}/share/terminfo \
		${WRKSRC}/misc/rio.terminfo
.if !empty(PKG_OPTIONS:Mman)
	# Build and install man pages from scdoc source in extra/man/.
	${SCDOC} < ${WRKSRC}/extra/man/rio.1.scd > \
		${DESTDIR}${PREFIX}/man/man1/rio.1
	${SCDOC} < ${WRKSRC}/extra/man/rio.5.scd > \
		${DESTDIR}${PREFIX}/man/man5/rio.5
	${SCDOC} < ${WRKSRC}/extra/man/rio-bindings.5.scd > \
		${DESTDIR}${PREFIX}/man/man5/rio-bindings.5
.endif

.include "cargo-depends.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
