# $NetBSD: Makefile,v 1.14 2012/09/24 18:26:53 asau Exp $

DISTNAME=	chromium-48.0.2564.116
CATEGORIES=	www
MASTER_SITES=	http://build.chromium.org/buildbot/official/obsolete/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://dev.chromium.org/Home
COMMENT=	Open-source browser project
LICENSE=	modified-bsd

USE_TOOLS+=	bash bison flex:pkgsrc gmake pax perl pkg-config
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	gperf>=3.0.1:../../devel/gperf
BUILD_DEPENDS+=	yasm>=0:../../devel/yasm

ONLY_FOR_PLATFORM=	*-*-arm *-*-i386 *-*-x86_64
TOOLS_PLATFORM.flex=	# override the platform definition to use pkgsrc's flex.

DATADIR=	${DESTDIR}${PREFIX}/share/chromium

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	third_party/icu/source
CONFIGURE_DIRS+=third_party/tcmalloc/vendor
CONFIGURE_DIRS+=third_party/yasm/source/patched-yasm
CONFIGURE_ENV+=	GYP_DEFINES=${GYP_DEFINES:C/^/-D/} 

# Replace config.{guess,sub}
OVERRIDE_DIRDEPTH=	5

GYP_DEFINES+=	clang=1
GYP_DEFINES+=	OS=${LOWER_OPSYS}
GYP_DEFINES+=	buildtype=Official
.if ${OPSYS} != "Linux"
GYP_DEFINES+=	disable_nacl=1
.endif
GYP_DEFINES+=	disable_sse2=0
GYP_DEFINES+=	ffmpeg_branding=${FFMPEG_CODECS}
GYP_DEFINES+=	libvpx_path=${BUILDLINK_DIR}/lib
.if ${OPSYS} != "Linux" && ${OPSYS} != "FreeBSD"
GYP_DEFINES+=	linux_use_tcmalloc=0
.endif
.if ${OPSYS} == "NetBSD"
GYP_DEFINES+=	no_gc_sections=1 
.endif
GYP_DEFINES+=	python_ver=2.7 # ${PYVERSSUFFIX}
GYP_DEFINES+=	linux_breakpad=0
GYP_DEFINES+=	use_system_bzip2=1 
GYP_DEFINES+=	use_system_ffmpeg=0 
GYP_DEFINES+=	use_system_libevent=1 
GYP_DEFINES+=	use_system_libjpeg=1 
GYP_DEFINES+=	use_system_libpng=1 
GYP_DEFINES+=	use_system_libxml=1 
GYP_DEFINES+=	use_system_sqlite=0 
GYP_DEFINES+=	use_system_ssl=0 
GYP_DEFINES+=	use_system_vpx=1 
GYP_DEFINES+=	use_system_yasm=0 
GYP_DEFINES+=	use_system_zlib=1 

FFMPEG_ARGS+=	--disable-everything
FFMPEG_ARGS+=	--disable-network
FFMPEG_ARGS+=	--disable-bzlib
FFMPEG_ARGS+=	--disable-zlib
FFMPEG_ARGS+=	--disable-swscale
FFMPEG_ARGS+=	--disable-amd3dnow
FFMPEG_ARGS+=	--disable-amd3dnowext
FFMPEG_ARGS+=	--enable-shared
FFMPEG_ARGS+=	--enable-libvpx
FFMPEG_ARGS+=	--enable-encoder=libvpx

.include "options.mk"

BUILD_DIRS=	.
MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
#MAKE_ENV+=	CC.host=${CC:Q}
MAKE_ENV+=	CFLAGS.host=${CFLAGS:M*:Q}
MAKE_ENV+=	CXX.host=${CXX:Q}
MAKE_ENV+=	CXXFLAGS.host=${CXXFLAGS:M*:Q}
MAKE_ENV+=	LINK.host=${CXX:Q}
MAKE_ENV+=	LDFLAGS.host=${LDFLAGS:M*:Q}
MAKE_ENV+=	AR.host=${AR:Q}
.if ${OPSYS} != "Linux"
# Override the LINK variable for the platforms which do not have flock(1).
MAKE_ENV+=	LINK=${CXX:Q}
.endif

BUILDDIR=	${WRKSRC}/out # /${BUILDTYPE}

CHECK_PORTABILITY_SKIP+=gpu/demos/run_demo_ppapi.sh
CHECK_PORTABILITY_SKIP+=third_party/xdg-utils/scripts/xdg-terminal
CHECK_PORTABILITY_SKIP+=third_party/xdg-utils/scripts/xdg-terminal.in
CHECK_PORTABILITY_SKIP+=v8/tools/linux-tick-processor

SUBST_CLASSES+=		bash
SUBST_MESSAGE.bash=	Fixing bash path
SUBST_STAGE.bash=	post-patch
SUBST_FILES.bash+=	build/linux/python_arch.sh
SUBST_FILES.bash+=	chrome/tools/build/linux/chrome-wrapper
SUBST_FILES.bash+=	chrome/tools/build/linux/sed.sh
SUBST_SED.bash=		-e 's:/bin/bash:${BASH}:'

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing pkg path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path+=	base/base_paths_linux.cc
SUBST_FILES.path+=	base/process_util_openbsd.cc
SUBST_FILES.path+=	build/common.gypi
SUBST_FILES.path+=	chrome/chrome_tests.gypi
SUBST_SED.path+=	-e 's:/usr/local/:${PREFIX}/:'
SUBST_SED.path+=	-e 's:/usr/lib/:${BUILDLINK_DIR}/lib/:'
SUBST_SED.path+=	-e 's:/usr/include/:${BUILDLINK_DIR}/include/:'

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 bin share/chromium
INSTALLATION_DIRS+=	share/chromium/locales share/chromium/resources

MODPY_ADJ_FILES=build/linux/unbundle/replace_gyp_files.py

BUILDTYPE=		Release
MAKE_ENV+=		BUILDTYPE=${BUILDTYPE}

pre-configure:
	# phajdan-jr: list of things *not* to remove, so maybe the script
	#             should be called "keep_bundled_libraries.py"
	cd ${WRKSRC} && ${PYTHON_CMD} \
		./build/linux/unbundle/remove_bundled_libraries.py \
		'base/third_party/dmg_fp' \
		'base/third_party/dynamic_annotations' \
		'base/third_party/icu' \
		'base/third_party/nspr' \
		'base/third_party/superfasthash' \
		'base/third_party/symbolize' \
		'base/third_party/valgrind' \
		'base/third_party/xdg_mime' \
		'base/third_party/xdg_user_dirs' \
		'breakpad/src/third_party/curl' \
		'chrome/third_party/mock4js' \
		'chrome/third_party/mozilla_security_manager' \
		'courgette/third_party' \
		'crypto/third_party/nss' \
		'net/third_party/mozilla_security_manager' \
		'net/third_party/nss' \
		'third_party/WebKit' \
		'third_party/analytics' \
		'third_party/angle' \
		'third_party/angle/src/third_party' \
		'third_party/blanketjs' \
		'third_party/brotli' \
		'third_party/boringssl' \
		'third_party/cacheinvalidation' \
		'third_party/catapult' \
		'third_party/catapult/third_party/beautifulsoup' \
		'third_party/catapult/third_party/py_vulcanize' \
		'third_party/catapult/third_party/py_vulcanize/py_vulcanize' \
		'third_party/catapult/third_party/py_vulcanize/third_party/rcssmin' \
		'third_party/catapult/third_party/py_vulcanize/third_party/rjsmin' \
		'third_party/catapult/tracing' \
		'third_party/catapult/tracing/third_party' \
		'third_party/cld' \
		'third_party/cros_system_api' \
		'third_party/dom_distiller_js' \
		'third_party/dom_distiller_js/dist/proto_gen/third_party/dom_distiller_js' \
		'third_party/ffmpeg' \
		'third_party/gardiner_mod' \
		'third_party/fips181' \
		'third_party/flot' \
		'third_party/google_input_tools' \
		'third_party/google_input_tools/third_party/closure_library' \
		'third_party/google_input_tools/third_party/closure_library/third_party/closure' \
		'third_party/hunspell' \
		'third_party/iccjpeg' \
		'third_party/icu/icu.isolate' \
		'third_party/jinja2' \
		'third_party/jstemplate' \
		'third_party/khronos' \
		'third_party/leveldatabase' \
		'third_party/libaddressinput' \
		'third_party/libjingle' \
		'third_party/libphonenumber' \
		'third_party/libsrtp' \
		'third_party/libvpx_new' \
		'third_party/libvpx_new/source/libvpx/third_party/x86inc' \
		'third_party/libwebm' \
		'third_party/libxml/chromium' \
		'third_party/libXNVCtrl' \
		'third_party/libyuv' \
		'third_party/lss' \
		'third_party/lzma_sdk' \
		'third_party/markupsafe' \
		'third_party/mesa' \
		'third_party/mojo' \
		'third_party/modp_b64' \
		'third_party/mt19937ar' \
		'third_party/npapi' \
		'third_party/openmax_dl' \
		'third_party/opus' \
		'third_party/ots' \
		'third_party/pdfium' \
		'third_party/pdfium/third_party' \
		'third_party/ply' \
		'third_party/polymer' \
		'third_party/protobuf' \
		'third_party/pywebsocket' \
		'third_party/qcms' \
		'third_party/qunit' \
		'third_party/sfntly' \
		'third_party/sinonjs' \
		'third_party/skia' \
		'third_party/smhasher' \
		'third_party/sqlite' \
		'third_party/tcmalloc' \
		'third_party/tlslite' \
		'third_party/usrsctp' \
		'third_party/web-animations-js' \
		'third_party/webdriver' \
		'third_party/webrtc' \
		'third_party/widevine' \
		'third_party/x86inc' \
		'third_party/yasm' \
		'third_party/zlib' \
		'url/third_party/mozilla' \
		'v8/src/third_party/valgrind' \
		'v8/src/third_party/fdlibm' \
		--do-remove || ${FALSE}
	cd ${WRKSRC} && ${PYTHON_CMD} \
		./build/linux/unbundle/replace_gyp_files.py \
		${GYP_DEFINES:C/^/-D/} || ${FALSE}
	# allow removal of third_party/adobe
	${ECHO_CMD} > ${WRKSRC}/flapper_version.h
	# missing file: file is in -testdata only, but configure stage
	# will fail if it's not there. do not break TESTS build while
	# allowing regular build without pulling in -testdata.
	${TOUCH} ${WRKSRC}/chrome/test/data/webui/i18n_process_css_test.html

# gyp_chromium generates all the Makefiles from gyp
do-configure:
	cd ${WRKSRC} && \
		build/linux/unbundle/replace_gyp_files.py ${GYP_DEFINES:C/^/-D/} && \
		env -i ${CONFIGURE_ENV} ${MODPY_BIN} build/gyp_chromium \
		${GYP_DEFS} "--depth=${WRKSRC}"

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/out/${BUILDTYPE}/chrome.1 ${STAGEDIR}${MANPREFIX}/man/man1
.for s in 22 24 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/chrome/app/theme/chromium/product_logo_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/chrome.png
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/chrome/tools/build/linux/chrome-wrapper \
		${STAGEDIR}${DATADIR}
.for p in chrome_100_percent content_resources keyboard_resources resources
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${p}.pak \
		${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/chrome \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/out && \
		${COPYTREE_SHARE} "locales resources" ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/chromium-browser.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/chrome ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/mksnapshot \
		${STAGEDIR}${DATADIR}
# END OF THINGS FROM FREEBSD PORTS
	${INSTALL_DATA_DIR} ${PREFIX}/chrome
	${INSTALL_PROGRAM} ${BUILDDIR}/chrome ${PREFIX}/chrome
	${SUBST_PROGRAM} ${FILESDIR}/chrome ${PREFIX}/bin/chrome
	${INSTALL_MAN} ${BUILDDIR}/chrome.1 ${PREFIX}/man/man1

	${INSTALL_DATA} ${BUILDDIR}/*.pak ${PREFIX}/chrome

	${INSTALL_DATA_DIR} ${PREFIX}/chrome/locales
	${INSTALL_DATA} ${BUILDDIR}/locales/* ${PREFIX}/chrome/locales
	${INSTALL_DATA} ${BUILDDIR}/*.png ${PREFIX}/chrome
	${INSTALL_DATA_DIR} ${PREFIX}/chrome/resources
	@cp -Rp ${BUILDDIR}/resources/* ${PREFIX}/chrome/resources
	@chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/chrome/resources
.for f in libexif.so protoc icudtl.dat mksnapshot
	${INSTALL_DATA} ${BUILDDIR}/${f} ${PREFIX}/chrome
.endfor
.for s in 22 24 48 64 128 256
	${INSTALL_DATA_DIR} ${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/chrome/app/theme/chromium/product_logo_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}x${s}/apps/chrome.png
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/chromium-browser.desktop \
		${PREFIX}/share/applications/chromium-browser.desktop

.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
