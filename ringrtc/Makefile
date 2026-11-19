# $NetBSD$

.include "../../wip/signal-desktop/versions.mk"

DISTNAME=	ringrtc-${RINGRTC_VER}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=signalapp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

DISTFILES+=	${DEFAULT_DISTFILES}
DISTFILES+=	libsignal-v${LIBSIGNAL_VER}.tar.gz
DISTFILES+=	webrtc-${WEBRTC_VER}.tar.gz
DISTFILES+=	boringssl-${BORINGSSL_VER}.tar.gz
DISTFILES+=	build-${BUILD_VER}.tar.gz
DISTFILES+=	buildtools-${BUILDTOOLS_VER}.tar.gz
DISTFILES+=	catapult-${CATAPULT_VER}.tar.gz
DISTFILES+=	icu-${ICU_VER}.tar.gz
DISTFILES+=	libjpeg_turbo-${LIBJPEG_TURBO_VER}.tar.gz
DISTFILES+=	libsrtp-${LIBSRTP_VER}.tar.gz
DISTFILES+=	libvpx-${LIBVPX_VER}.tar.gz
DISTFILES+=	libyuv-${LIBYUV_VER}.tar.gz
DISTFILES+=	nasm-${NASM_VER}.tar.gz
DISTFILES+=	opus-${OPUS_VER}.tar.gz
DISTFILES+=	perfetto-${PERFETTO_VER}.tar.gz
DISTFILES+=	protobufjs-${PROTOBUFJS_VER}.tar.gz
DISTFILES+=	re2-${RE2_VER}.tar.gz
DISTFILES+=	testing-${TESTING_VER}.tar.gz
DISTFILES+=	third_party-${THIRD_PARTY_VER}.tar.gz
DISTFILES+=	tools-${TOOLS_VER}.tar.gz

SITES.webrtc-${WEBRTC_VER}.tar.gz=			-${MASTER_SITE_GITHUB:=signalapp/}webrtc/archive/${WEBRTC_VER}.tar.gz
SITES.libsignal-v${LIBSIGNAL_VER}.tar.gz=		-${MASTER_SITE_GITHUB:=signalapp/}libsignal/archive/v${LIBSIGNAL_VER}.tar.gz
SITES.boringssl-${BORINGSSL_VER}.tar.gz=		-https://boringssl.googlesource.com/boringssl.git/+archive/${BORINGSSL_VER}.tar.gz
EXTRACT_DIR.boringssl-${BORINGSSL_VER}.tar.gz=		${WRKDIR}/boringssl
SITES.build-${BUILD_VER}.tar.gz=			-https://chromium.googlesource.com/chromium/src/build.git/+archive/${BUILD_VER}.tar.gz
EXTRACT_DIR.build-${BUILD_VER}.tar.gz=			${WRKDIR}/build
SITES.buildtools-${BUILDTOOLS_VER}.tar.gz=		-https://chromium.googlesource.com/chromium/src/buildtools.git/+archive/${BUILDTOOLS_VER}.tar.gz
EXTRACT_DIR.buildtools-${BUILDTOOLS_VER}.tar.gz=	${WRKDIR}/buildtools
SITES.catapult-${CATAPULT_VER}.tar.gz=			-https://chromium.googlesource.com/catapult.git/+archive/${CATAPULT_VER}.tar.gz
EXTRACT_DIR.catapult-${CATAPULT_VER}.tar.gz=		${WRKDIR}/catapult
SITES.icu-${ICU_VER}.tar.gz=				-https://chromium.googlesource.com/chromium/deps/icu.git/+archive/${ICU_VER}.tar.gz
EXTRACT_DIR.icu-${ICU_VER}.tar.gz=			${WRKDIR}/icu
SITES.libjpeg_turbo-${LIBJPEG_TURBO_VER}.tar.gz=	-https://chromium.googlesource.com/chromium/deps/libjpeg_turbo.git/+archive/${LIBJPEG_TURBO_VER}.tar.gz
EXTRACT_DIR.libjpeg_turbo-${LIBJPEG_TURBO_VER}.tar.gz=	${WRKDIR}/libjpeg_turbo
SITES.libsrtp-${LIBSRTP_VER}.tar.gz=			-https://chromium.googlesource.com/chromium/deps/libsrtp.git/+archive/${LIBSRTP_VER}.tar.gz
EXTRACT_DIR.libsrtp-${LIBSRTP_VER}.tar.gz=		${WRKDIR}/libsrtp
SITES.libvpx-${LIBVPX_VER}.tar.gz=			-https://chromium.googlesource.com/webm/libvpx.git/+archive/${LIBVPX_VER}.tar.gz
EXTRACT_DIR.libvpx-${LIBVPX_VER}.tar.gz=		${WRKDIR}/libvpx
SITES.libyuv-${LIBYUV_VER}.tar.gz=			-https://chromium.googlesource.com/libyuv/libyuv.git/+archive/${LIBYUV_VER}.tar.gz
EXTRACT_DIR.libyuv-${LIBYUV_VER}.tar.gz=		${WRKDIR}/libyuv
SITES.nasm-${NASM_VER}.tar.gz=				-https://chromium.googlesource.com/chromium/deps/nasm.git/+archive/${NASM_VER}.tar.gz
EXTRACT_DIR.nasm-${NASM_VER}.tar.gz=			${WRKDIR}/nasm
SITES.opus-${OPUS_VER}.tar.gz=				-${MASTER_SITE_GITHUB:=xiph/}opus/archive/${OPUS_VER}.tar.gz
SITES.perfetto-${PERFETTO_VER}.tar.gz=			-${MASTER_SITE_GITHUB:=google/}perfetto/archive/${PERFETTO_VER}.tar.gz
SITES.protobufjs-${PROTOBUFJS_VER}.tar.gz=		-${MASTER_SITE_GITHUB:=protocolbuffers/}protobuf-javascript/archive/${PROTOBUFJS_VER}.tar.gz
SITES.re2-${RE2_VER}.tar.gz=				-${MASTER_SITE_GITHUB:=google/}re2/archive/${RE2_VER}.tar.gz
SITES.testing-${TESTING_VER}.tar.gz=			-https://chromium.googlesource.com/chromium/src/testing.git/+archive/${TESTING_VER}.tar.gz
EXTRACT_DIR.testing-${TESTING_VER}.tar.gz=		${WRKDIR}/testing
SITES.third_party-${THIRD_PARTY_VER}.tar.gz=		-https://chromium.googlesource.com/chromium/src/third_party.git/+archive/${THIRD_PARTY_VER}.tar.gz
EXTRACT_DIR.third_party-${THIRD_PARTY_VER}.tar.gz=	${WRKDIR}/third_party
SITES.tools-${TOOLS_VER}.tar.gz=			-https://chromium.googlesource.com/chromium/src/tools.git/+archive/${TOOLS_VER}.tar.gz
EXTRACT_DIR.tools-${TOOLS_VER}.tar.gz=			${WRKDIR}/tools

MAINTAINER=		kikadf@NetBSD.org
HOMEPAGE=		https://github.com/signalapp/ringrtc/
COMMENT=		Middleware library for Signal-Desktop
LICENSE=		gnu-agpl-v3

USE_LANGUAGES=		c c++

.include "../../mk/compiler.mk"
PKG_CC=			clang
PKG_CXX=		clang++

EXTRA_CXXFLAGS=		-Wno-unknown-warning-option
EXTRA_LDFLAGS=		-L${PREFIX}/lib

USE_TOOLS+=		pkg-config

TOOL_DEPENDS+=		ninja-build-[0-9]*:../../devel/ninja-build
TOOL_DEPENDS+=		gn-[0-9]*:../../wip/gn
TOOL_DEPENDS+=		cmake-[0-9]*:../../devel/cmake

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Set pathes
SUBST_FILES.path+=	src/rust/Cargo.toml
SUBST_FILES.path+=	src/webrtc/src/build/gn_run_binary.py
SUBST_FILES.path+=	src/webrtc/src/build/linux/strip_binary.gni
SUBST_FILES.path+=	src/webrtc/src/third_party/perfetto/src/base/utils.cc
SUBST_VARS.path+=	LIBSIGNAL_VER WRKDIR WRKSRC PREFIX

GN_ARGS+=	rtc_build_examples=false
GN_ARGS+=	rtc_build_tools=false
GN_ARGS+=	rtc_include_tests=false
GN_ARGS+=	rtc_enable_protobuf=false
GN_ARGS+=	rtc_use_x11=false
GN_ARGS+=	rtc_enable_sctp=false
GN_ARGS+=	rtc_libvpx_build_vp9=true
GN_ARGS+=	rtc_disable_metrics=true
GN_ARGS+=	rtc_disable_trace_events=true
GN_ARGS+=	clang_use_chrome_plugins=false
GN_ARGS+=	fatal_linker_warnings=false
GN_ARGS+=	is_clang=true
GN_ARGS+=	treat_warnings_as_errors=false
GN_ARGS+=	use_custom_libcxx=false
GN_ARGS+=	use_custom_libunwind=true
GN_ARGS+=	use_lld=false
GN_ARGS+=	use_llvm_libatomic=false
GN_ARGS+=	use_sysroot=false
GN_ARGS+=	use_system_freetype=false
GN_ARGS+=	use_system_harfbuzz=true
GN_ARGS+=	use_system_libjpeg=true
GN_ARGS+=	use_udev=false
GN_ARGS+=	extra_cflags="${EXTRA_CFLAGS}"
GN_ARGS+=	extra_cxxflags="${EXTRA_CXXFLAGS}"
GN_ARGS+=	extra_ldflags="${EXTRA_LDFLAGS}"
GN_ARGS+=	use_thin_lto=false
GN_ARGS+=	thin_lto_enable_optimizations=false
GN_ARGS+=	is_debug=false

RUSTC_VERSION=	rustc -V
MAKE_ENV+=	RUSTC_BOOTSTRAP=1
MAKE_ENV+=	OUTPUT_DIR=${WRKSRC}/src/webrtc/src/out
GN_ARGS+=	enable_rust=true
GN_ARGS+=	rust_sysroot_absolute="${PREFIX}"
GN_ARGS+=	rustc_version="${RUSTC_VERSION:sh}"

INSTALLATION_DIRS+=	lib

post-extract:
	${MKDIR} ${WRKSRC}/src/webrtc
	${MV} ${WRKDIR}/webrtc-${WEBRTC_VER} ${WRKSRC}/src/webrtc/src
	${MV} ${WRKDIR}/build ${WRKSRC}/src/webrtc/src
	${MV} ${WRKDIR}/buildtools ${WRKSRC}/src/webrtc/src
	${MV} ${WRKDIR}/testing ${WRKSRC}/src/webrtc/src
	${MV} ${WRKDIR}/third_party ${WRKSRC}/src/webrtc/src
	${MV} ${WRKDIR}/catapult ${WRKSRC}/src/webrtc/src/third_party
	${MV} ${WRKDIR}/boringssl ${WRKSRC}/src/webrtc/src/third_party/boringssl/src
	${MV} ${WRKDIR}/icu ${WRKSRC}/src/webrtc/src/third_party
	${MV} ${WRKDIR}/libjpeg_turbo ${WRKSRC}/src/webrtc/src/third_party
	${MV} ${WRKDIR}/libsrtp ${WRKSRC}/src/webrtc/src/third_party
	${MV} ${WRKDIR}/libvpx ${WRKSRC}/src/webrtc/src/third_party/libvpx/source
	${MV} ${WRKDIR}/libyuv ${WRKSRC}/src/webrtc/src/third_party
	${MV} ${WRKDIR}/nasm ${WRKSRC}/src/webrtc/src/third_party
	${MV} ${WRKDIR}/opus-${OPUS_VER} ${WRKSRC}/src/webrtc/src/ringrtc/opus/src
	${MV} ${WRKDIR}/perfetto-${PERFETTO_VER} \
		${WRKSRC}/src/webrtc/src/third_party/perfetto
	${MV} ${WRKDIR}/protobuf-javascript-${PROTOBUFJS_VER} \
		${WRKSRC}/src/webrtc/src/third_party/protobuf-javascript/src
	${MV} ${WRKDIR}/re2-${RE2_VER} ${WRKSRC}/src/webrtc/src/third_party/re2/src
	${MV} ${WRKDIR}/tools ${WRKSRC}/src/webrtc/src
	${CP} -R ${WRKSRC}/src/rust/src/webrtc_include \
		${WRKSRC}/src/webrtc/src/ringrtc/rffi/api

post-patch:
	${ECHO} "# Generated from 'DEPS'" > ${WRKSRC}/src/webrtc/src/build/config/gclient_args.gni
	${ECHO} 1591703586 > ${WRKSRC}/src/webrtc/src/build/util/LASTCHANGE.committime
	${ECHO} "qqchose " > ${WRKSRC}/src/webrtc/src/build/util/LASTCHANGE
	${RM} -r ${CARGO_VENDOR_DIR}/cubeb-sys-${LIBCUBEB_VER}/libcubeb/src/cubeb-pulse-rs

do-configure:
	# webrtc
	cd ${WRKSRC}/src/webrtc/src && \
		${SETENV} ${CONFIGURE_ENV} gn gen out/release --args='${GN_ARGS}'

pre-build:
	cd ${WRKSRC}/src/webrtc/src && \
		${SETENV} ${MAKE_ENV} ninja -C out/release

do-install:
	${INSTALL_LIB} ${WRKSRC}/target/release/libringrtc.so \
		${DESTDIR}${PREFIX}/lib


.include "cargo-depends.mk"

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/rust/cargo.mk"
CARGO_ARGS+=	--package ringrtc
CARGO_ARGS+=	--features electron
.include "../../fonts/harfbuzz/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
