# $NetBSD$

DISTNAME=			electron32-${VERSION}
# See ${WRKSRC}/electron/DEPS for versions
VERSION=			32.2.7
CHROMIUM_VERSION=		128.0.6613.186
AUDIOIO_VERSION=		130.0
NODE_VERSION=			20.18.1
NAN_VERSION=			e14bdcd1f72d62bca1d541b66da43130384ec213
SQUIRREL_VERSION=		0e5d146ba13101a1302d59ea6e6e0b3cace4ae38
REACTIVEOBJC_VERSION=		74ab5baccc6f7202c8ac69a8d1e152c29dc1ea76
MANTLE_VERSION=			78d3966b3c331292ea29ec38661b25df0a245948
ENGFLOW_VERSION=		955335c30a752e9ef7bff375baab5e0819b6c00d
CATEGORIES=			devel
MASTER_SITES=			${MASTER_SITE_GITHUB:=electron/}
GITHUB_PROJECT=			electron
GITHUB_TAG=			v${PKGVERSION_NOREV}
EXTRACT_SUFX_C=			.tar.xz

CHROMIUM_DISTFILE=		chromium-${CHROMIUM_VERSION}${EXTRACT_SUFX_C}
CHROMIUM_DISTFILES=		chromium-${CHROMIUM_VERSION}${EXTRACT_SUFX_C}.0
CHROMIUM_DISTFILES+=		chromium-${CHROMIUM_VERSION}${EXTRACT_SUFX_C}.1
CHROMIUM_DISTFILES+=		chromium-${CHROMIUM_VERSION}${EXTRACT_SUFX_C}.2
SITES.${CHROMIUM_DISTFILE}.0=	https://github.com/tagattie/FreeBSD-Electron/releases/download/v32.2.1/
SITES.${CHROMIUM_DISTFILE}.1=	https://github.com/tagattie/FreeBSD-Electron/releases/download/v32.2.1/
SITES.${CHROMIUM_DISTFILE}.2=	https://github.com/tagattie/FreeBSD-Electron/releases/download/v32.2.1/
DISTFILES+=			${CHROMIUM_DISTFILES}
DISTFILES+=			${DEFAULT_DISTFILES}

GITHUB_SUBMODULES=		kikadf chromium-audioio v${AUDIOIO_VERSION} media/audio/audioio
GITHUB_SUBMODULES+=		nodejs node v${NODE_VERSION} third_party/electron_node
GITHUB_SUBMODULES+=		nodejs nan ${NAN_VERSION} third_party/nan
GITHUB_SUBMODULES+=		Squirrel Squirrel.Mac ${SQUIRREL_VERSION} third_party/squirrel.mac
GITHUB_SUBMODULES+=		ReactiveCocoa ReactiveObjC ${REACTIVEOBJC_VERSION} third_party/squirrel.mac/vendor/ReactiveObjC
GITHUB_SUBMODULES+=		Mantle Mantle ${MANTLE_VERSION} third_party/squirrel.mac/vendor/Mantle
GITHUB_SUBMODULES+=		EngFlow reclient-configs ${ENGFLOW_VERSION} third_party/engflow-reclient-configs

EXTRACT_ONLY=			${CHROMIUM_DISTFILE}
EXTRACT_ONLY+=			${DISTFILES:C/${CHROMIUM_DISTFILE}\.[0-9]//}

MAINTAINER=			kikadf.01@gmail.com
HOMEPAGE=			https://electronjs.org
COMMENT=			Build cross-platform desktop apps with JavaScript, HTML, and CSS
LICENSE=			modified-bsd AND gnu-lgpl-v3 AND mpl-2.0 AND mit

USE_TOOLS+=			bash bison flex:pkgsrc gmake pax perl pkg-config
TOOLS_PLATFORM.flex=		# override the platform definition to use pkgsrc's flex.
USE_LANGUAGES=			c c++

CHECK_PORTABILITY_SKIP+=	third_party/dawn/third_party/dxc/utils/buildit/build_llvm
CHECK_PORTABILITY_SKIP+=	third_party/sqlite/src/configure
CHECK_PORTABILITY_SKIP+=	third_party/protobuf/post_process_dist.sh
CHECK_PORTABILITY_SKIP+=	third_party/ffmpeg/configure
CHECK_PORTABILITY_SKIP+=	third_party/nearby/src/embedded/build.sh
CHECK_PORTABILITY_SKIP+=	third_party/xdg-utils/scripts/xdg-terminal
CHECK_PORTABILITY_SKIP+=	third_party/xdg-utils/scripts/xdg-terminal.in
CHECK_PORTABILITY_SKIP+=	third_party/llvm/flang/tools/f18/flang.sh.in
CHECK_PORTABILITY_SKIP+=	third_party/rust-src/vendor/libdbus-sys-0.2.5/vendor/dbus/tools/cmake-format
CHECK_PORTABILITY_SKIP+=	third_party/rust-toolchain/lib/rustlib/src/rust/vendor/libdbus-sys-0.2.5/vendor/dbus/tools/cmake-format
CHECK_PORTABILITY_SKIP+=	v8/tools/run-llprof.sh
CHECK_PORTABILITY_SKIP+=	v8/tools/profiling/run-llprof.sh

TOOL_DEPENDS+=			gperf>=3.0.1:../../devel/gperf
TOOL_DEPENDS+=			nasm-[0-9]*:../../devel/nasm
TOOL_DEPENDS+=			ninja-build-[0-9]*:../../devel/ninja-build
TOOL_DEPENDS+=			${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
TOOL_DEPENDS+=			${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
TOOL_DEPENDS+=			${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply
TOOL_DEPENDS+=			nodejs-[0-9]*:../../lang/nodejs
#TOOL_DEPENDS+=			clang-[0-9]*:../../lang/clang # clang-format
TOOL_DEPENDS+=			rust-bindgen-[0-9]*:../../devel/rust-bindgen
TOOL_DEPENDS+=			yarn-[0-9]*:../../devel/yarn

DEPENDS+=			xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

#ONLY_FOR_PLATFORM+=		*-*-arm # not yet
#ONLY_FOR_PLATFORM+=		*-*-aarch64 # not yet
#ONLY_FOR_PLATFORM+=		*-*-i386 # not yet
ONLY_FOR_PLATFORM+=		*-*-x86_64

# Workaround for brotli and other commands.
#BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

# Let to chromium use the -Wl,-z,relro flag
BUILDLINK_TRANSFORM+=		rm:-Wl,-zrelro

# Do not use alloca(3) in libc.
BUILDLINK_TRANSFORM+=		opt:-std=c11:-std=gnu11
BUILDLINK_TRANSFORM+=		opt:-std=c99:-std=gnu99
BUILDLINK_TRANSFORM+=		opt:-std=c++14:-std=gnu++14
BUILDLINK_TRANSFORM+=		opt:-std=c++17:-std=gnu++17
BUILDLINK_TRANSFORM+=		opt:-std=c++20:-std=gnu++20

REPLACE_BASH=		chrome/tools/build/linux/chrome-wrapper
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN:Q}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	base/base_paths_posix.cc
SUBST_FILES.path+=	base/process/process_handle_openbsd.cc
SUBST_FILES.path+=	build/rust/rust_bindgen.gni
SUBST_FILES.path+=	chrome/common/chrome_paths.cc
SUBST_FILES.path+=	chromium.sh
SUBST_FILES.path+=	components/policy/core/common/policy_paths.cc
SUBST_FILES.path+=	sandbox/policy/openbsd/sandbox_openbsd.cc
SUBST_FILES.path+=	services/device/hid/hid_service_freebsd.cc
SUBST_FILES.path+=	services/device/time_zone_monitor/time_zone_monitor_linux.cc
SUBST_FILES.path+=	third_party/perfetto/src/base/utils.cc
SUBST_FILES.path+=	ui/qt/qt.gni
SUBST_FILES.path+=	v8/tools/run-paxctl.py
SUBST_VARS.path+=	PREFIX PKG_SYSCONFBASE VARBASE QTDIR X11BASE PYTHONBIN

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fixing manpage
SUBST_FILES.man+=	chrome/app/resources/manpage.1.in
SUBST_SED.man+=		-e 's,@@PACKAGE@@,chromium,g'
SUBST_SED.man+=		-e 's,@@MENUNAME@@,Chromium Web Browser,g'

.include "options.mk"

#SUBST_CLASSES+=		pulse
#SUBST_STAGE.pulse=	pre-configure
#SUBST_MESSAGE.pulse=	Set BUILT_WITH_PULSE to ${WITH_PA} in chromium wrapper
#SUBST_FILES.pulse+=	chromium.sh
#SUBST_SED.pulse+=	-e 's,@PULSE@,${WITH_PA},g'

MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
MAKE_ENV+=	GPERF=${PREFIX}/bin/gperf
TARGET=		electron electron:node_headers
#TARGET+=	chromedriver
TARGET+=	licenses version

# These libraries are used from the system and the build infrastructure
# removes them from the bundled third_party directory and replaces them
# with hooks to use them from the system.
GN_SYSTEM_LIBS=		dav1d
GN_SYSTEM_LIBS+=	fontconfig
GN_SYSTEM_LIBS+=	icu
GN_SYSTEM_LIBS+=	libaom
GN_SYSTEM_LIBS+=	libevent
#GN_SYSTEM_LIBS+=	libjpeg # libjpeg-turbo
GN_SYSTEM_LIBS+=	libpng
GN_SYSTEM_LIBS+=	libvpx
GN_SYSTEM_LIBS+=	libxml
GN_SYSTEM_LIBS+=	libxslt
GN_SYSTEM_LIBS+=	openh264
GN_SYSTEM_LIBS+=	opus

GN_ARGS+=	chrome_pgo_phase=0
GN_ARGS+=	clang_use_chrome_plugins=false
GN_ARGS+=	disable_fieldtrial_testing_config=true
GN_ARGS+=	enable_backup_ref_ptr_support=false
GN_ARGS+=	enable_hangout_services_extension=true
GN_ARGS+=	enable_log_error_not_reached=true
GN_ARGS+=	enable_nacl=false
GN_ARGS+=	enable_remoting=false
GN_ARGS+=	fatal_linker_warnings=false
GN_ARGS+=	icu_use_data_file=false
GN_ARGS+=	is_cfi=false
GN_ARGS+=	is_clang=true
GN_ARGS+=	optimize_webui=true
GN_ARGS+=	override_electron_version="${VERSION}"
GN_ARGS+=	thin_lto_enable_optimizations=true
GN_ARGS+=	treat_warnings_as_errors=false
GN_ARGS+=	use_allocator_shim=false
GN_ARGS+=	use_cups=true
GN_ARGS+=	use_custom_libcxx=true
GN_ARGS+=	use_custom_libunwind=true
GN_ARGS+=	use_kerberos=false
GN_ARGS+=	use_lld=false
GN_ARGS+=	use_partition_alloc=true
GN_ARGS+=	use_partition_alloc_as_malloc=false
GN_ARGS+=	use_sysroot=false
GN_ARGS+=	use_system_freetype=true
GN_ARGS+=	use_system_harfbuzz=true
GN_ARGS+=	use_system_libdrm=true
#GN_ARGS+=	use_system_libjpeg=true #libjpeg-turbo
GN_ARGS+=	use_thin_lto=false
GN_ARGS+=	use_udev=false
GN_ARGS+=	use_vaapi=false
GN_ARGS+=	v8_enable_cet_ibt=true

# flags
CFLAGS+=	-fno-stack-protector
CFLAGS+=	-isystem${PREFIX}/lib/clang/17/include # third_party/zlib with clang
CFLAGS+=	-Wno-error=unused-command-line-argument
CFLAGS+=	-Wno-unknown-warning-option

EXTRA_LDFLAGS=	-L${PREFIX}/lib \
		-L${X11BASE}/lib \
		${COMPILER_RPATH_FLAG}${PREFIX}/lib \
		${COMPILER_RPATH_FLAG}${PREFIX}/lib/nspr \
		${COMPILER_RPATH_FLAG}${PREFIX}/lib/nss \
		${COMPILER_RPATH_FLAG}${X11BASE}/lib
EXTRA_CXXFLAGS=	-Wno-unknown-warning-option \
		-I${BUILDLINK_DIR}/include \
		-I${BUILDLINK_DIR}/include/libepoll-shim \
		-I${BUILDLINK_DIR}/include/glib \
		-I${BUILDLINK_DIR}/include/nss

# rust
RUSTC_VERSION=	rustc -V
MAKE_ENV+=	RUSTC_BOOTSTRAP=1
GN_ARGS+=	enable_rust=true \
		rust_sysroot_absolute=\"${PREFIX}\" \
		rustc_version=\"${RUSTC_VERSION:sh}\"

PLIST_VARS+=		swiftshader
.if ${MACHINE_ARCH} == "aarch64"
FFMPEG_TARGET=		arm64
.elif ${MACHINE_ARCH} == "x86_64"
PLIST.swiftshader=	yes
FFMPEG_TARGET=		x64
.elif ${MACHINE_ARCH} == "i386"
EXTRA_LDFLAGS+=		-Wl,--no-keep-memory
PLIST.swiftshader=	yes
FFMPEG_TARGET=		ia32
.endif

GN_ARGS+=	extra_cxxflags=\"${EXTRA_CXXFLAGS}\" \
		extra_ldflags=\"${EXTRA_LDFLAGS}\"

# Proprietary codecs are enabled.
FFMPEG_BRAND=	Chrome
FFMPEG_BDIR=	${WRKSRC}/third_party/ffmpeg/build.${FFMPEG_TARGET}.${LOWER_OPSYS}/${FFMPEG_BRAND}
FFMPEG_CDIR=	${WRKSRC}/third_party/ffmpeg/chromium/config/${FFMPEG_BRAND}/${LOWER_OPSYS}/${FFMPEG_TARGET}

GN_ARGS+=	proprietary_codecs=true \
		ffmpeg_branding=\"${FFMPEG_BRAND}\"

GN_BOOTSTRAP_FLAGS+=	--no-clean --no-rebuild
GN_BOOTSTRAP_FLAGS+=	--skip-generate-buildfiles

# API key and OAuth credential for Google.
# This is pkgsrc use only.
#GN_ARGS+=	google_api_key=\"AIzaSyAT_3ogzNMKbBMFk3xQ6T35fg52Y9GrFBg\"

#NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/electron

PKG_CC=			clang
PKG_CXX=		clang++

post-fetch:
	@if [ ! -f ${DISTDIR}/chromium-${CHROMIUM_VERSION}${EXTRACT_SUFX_C} ]; then \
		${CAT} ${DISTDIR}/chromium-${CHROMIUM_VERSION}${EXTRACT_SUFX_C}.? > \
			${DISTDIR}/chromium-${CHROMIUM_VERSION}${EXTRACT_SUFX_C}; \
	fi

post-extract:
	# Make source tree
	${MV} ${WRKSRC} ${WRKDIR}/temp
	${MV} ${WRKDIR}/chromium-${CHROMIUM_VERSION} ${WRKSRC}
	${MV} ${WRKDIR}/temp/media/audio/audioio ${WRKSRC}/media/audio/audioio
	${MV} ${WRKDIR}/temp/third_party/electron_node ${WRKSRC}/third_party/electron_node
	${MV} ${WRKDIR}/temp/third_party/nan ${WRKSRC}/third_party/nan
	${MV} ${WRKDIR}/temp/third_party/squirrel.mac ${WRKSRC}/third_party/squirrel.mac
	${MV} ${WRKDIR}/temp/third_party/engflow-reclient-configs ${WRKSRC}/third_party/engflow-reclient-configs
	${MV} ${WRKDIR}/temp ${WRKSRC}/electron
	#${CP} ${FILESDIR}/chromium.sh.in ${WRKSRC}/chromium.sh

	# Install node modules for electron
	${SED} -i.bak '/.*prepare.*husky.*/d' ${WRKSRC}/electron/package.json
	cd ${WRKSRC}/electron && ${SETENV} yarn install --frozen-lockfile

pre-configure:
	# Prepare internal ffmpeg
	cd ${WRKSRC}/media/ffmpeg && \
		${PYTHONBIN} scripts/build_ffmpeg.py \
		${LOWER_OPSYS} ${FFMPEG_TARGET} --config-only --branding=${FFMPEG_BRAND}
	cd ${FFMPEG_BDIR} && ${GMAKE} ffversion.h
	${INSTALL_DATA_DIR} ${FFMPEG_CDIR}
.for ffmpeg_part in config.h config.asm config_components.h libavcodec libavformat libavutil
	cp -pR ${FFMPEG_BDIR}/${ffmpeg_part} ${FFMPEG_CDIR}
.endfor

	# Create symlink to NetBSD nodejs command.
	${MKDIR} ${WRKSRC}/third_party/node/${LOWER_OPSYS}/node-${LOWER_OPSYS}/bin
	${LN} -sf ${PREFIX}/bin/node \
		${WRKSRC}/third_party/node/${LOWER_OPSYS}/node-${LOWER_OPSYS}/bin/node

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./build/linux/unbundle/replace_gn_files.py \
		--system-libraries ${GN_SYSTEM_LIBS} || ${FALSE}

	cd ${WRKSRC}/tools/gn && \
		${SETENV} ${MAKE_ENV} ${PYTHONBIN} bootstrap/bootstrap.py ${GN_BOOTSTRAP_FLAGS}

	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ./out/${BUILDTYPE}/gn \
		gen --args='import("//electron/build/args/${GN_FILE}") ${GN_ARGS}' \
		--script-executable="${PYTHONBIN}" ${GN_VERBOSE} out/${BUILDTYPE}

do-build:
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${PREFIX}/bin/ninja -j ${_MAKE_JOBS_N} -C out/${BUILDTYPE} ${TARGET}


BUILDDIR=		${WRKSRC}/out/${BUILDTYPE}
INSTALLATION_DIRS+=	lib/${PKGBASE}
INSTALLATION_DIRS+=	bin

ELECTRON_LIBS+=		libEGL.so
ELECTRON_LIBS+=		libGLESv2.so
ELECTRON_LIBS+=		libVkICD_mock_icd.so
ELECTRON_LIBS+=		libvulkan.so.1
ELECTRON_LIBS+=		libffmpeg.so
.if ${MACHINE_ARCH} != "aarch64"
ELECTRON_LIBS+=		libvk_swiftshader.so
ELECTRON_LIBS+=		vk_swiftshader_icd.json
.endif

do-install:
	${INSTALL_PROGRAM} ${BUILDDIR}/electron ${DESTDIR}${PREFIX}/lib/${PKGBASE}
	${LN} -s ${PREFIX}/lib/${PKGBASE}/electron ${DESTDIR}${PREFIX}/bin/${PKGBASE}
	#${INSTALL_PROGRAM} ${BUILDDIR}/chromedriver.unstripped  ${DESTDIR}${PREFIX}/lib/${PKGBASE}/chromedriver
.for i in ${ELECTRON_LIBS}
	${INSTALL_LIB} ${BUILDDIR}/${i} ${DESTDIR}${PREFIX}/lib/${PKGBASE}
.endfor
	${INSTALL_DATA} ${BUILDDIR}/*.pak ${DESTDIR}${PREFIX}/lib/${PKGBASE}
.for i in locales resources gen/electron/buildflags gen/v8/embedded.S
	cd ${WRKSRC}/out/${BUILDTYPE} && \
		${FIND} ${i} -type f -print | pax -rw -pmp ${DESTDIR}${PREFIX}/lib/${PKGBASE}
.endfor
	cd ${WRKSRC}/out/${BUILDTYPE}/gen && \
		${FIND} node_headers -type f -print | pax -rw -pmp ${DESTDIR}${PREFIX}/lib/${PKGBASE}
.for f in snapshot_blob.bin v8_context_snapshot.bin LICENSE LICENSES.chromium.html version
	${INSTALL_DATA} ${BUILDDIR}/${f} ${DESTDIR}${PREFIX}/lib/${CHROMIUM}
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/compiler-rt/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/rust.mk"
.include "../../misc/usbids/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk" # libjpeg-turbo
.include "../../multimedia/dav1d/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../multimedia/openh264/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
# Use -lpciutils instead of -lpci for pkgsrc.
BUILDLINK_TRANSFORM+=	l:pci:pciutils
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
