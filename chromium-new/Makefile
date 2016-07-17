# $NetBSD: Makefile,v 1.14 2012/09/24 18:26:53 asau Exp $

DISTNAME=	chromium-51.0.2704.106
CATEGORIES=	www
MASTER_SITES=	http://commondatastorage.googleapis.com/chromium-browser-official/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.chromium.org/Home
COMMENT=	Chromium web browser
LICENSE=	modified-bsd AND gnu-lgpl-v3 AND mpl-2.0

USE_TOOLS+=	bash bison flex:pkgsrc gmake pax perl pkg-config
TOOLS_PLATFORM.flex=   # override the platform definition to use pkgsrc's flex.
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	gperf>=3.0.1:../../devel/gperf
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
BUILD_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build
BUILD_DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

ONLY_FOR_PLATFORM=	*-*-arm *-*-i386 *-*-x86_64

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
SUBST_FILES.path+=	base/base.gyp
SUBST_FILES.path+=	base/base_paths_linux.cc
SUBST_FILES.path+=	base/process_util_openbsd.cc
SUBST_FILES.path+=	build/common.gypi
SUBST_FILES.path+=	chrome/chrome_tests.gypi
SUBST_SED.path+=	-e 's:/usr/local/:${PREFIX}/:'
SUBST_SED.path+=	-e 's:/usr/lib/:${BUILDLINK_DIR}/lib/:'
SUBST_SED.path+=	-e 's:/usr/include/:${BUILDLINK_DIR}/include/:'

CONFIGURE_ENV+=		CC=${CC:Q}
CONFIGURE_ENV+=		CXX=${CXX:Q}
CONFIGURE_ENV+=		GYP_GENERATORS=ninja
CONFIGURE_ENV+=		GYP_DEFINES="${GYP_DEFINES}"

CFLAGS+=		-fno-stack-protector

BUILDTYPE=	Release
MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
MAKE_ENV+=	GPERF=${PREFIX}/bin/gperf

# Proprietary codecs are enabled.
GYP_DEFINES+=	proprietary_codecs=1
GYP_DEFINES+=	ffmpeg_branding=Chrome

# Some gyp or gn files may be broken for NetBSD...
GYP_DEFINES+=	desktop_linux=1

GYP_DEFINES+=	use_gconf=0
GYP_DEFINES+=	use_pulseaudio=1
GYP_DEFINES+=	gcc_version=${CC_VERSION:S/gcc-//}
GYP_DEFINES+=	use_kerberos=0
GYP_DEFINES+=	linux_breakpad=0
GYP_DEFINES+=	linux_use_heapchecker=0
GYP_DEFINES+=	linux_strip_binary=1
GYP_DEFINES+=	use_aura=1
GYP_DEFINES+=	test_isolation_mode=noop
GYP_DEFINES+=	disable_nacl=1
GYP_DEFINES+=	enable_extensions=1
GYP_DEFINES+=	enable_one_click_signin=1
GYP_DEFINES+=	enable_webrtc=0
GYP_DEFINES+=	enable_web_speech=0
GYP_DEFINES+=	enable_service_discovery=1
GYP_DEFINES+=	werror=
GYP_DEFINES+=	no_gc_sections=1
GYP_DEFINES+=	OS=${LOWER_OPSYS}
GYP_DEFINES+=	os_ver=${OS_VERSION}
GYP_DEFINES+=	prefix_dir=${PREFIX}
GYP_DEFINES+=	python_ver=${PYVERSSUFFIX}
GYP_DEFINES+=	use_allocator=none
GYP_DEFINES+=	use_cups=1
GYP_DEFINES+=	linux_link_gsettings=1
GYP_DEFINES+=	linux_link_libpci=1
GYP_DEFINES+=	linux_link_libspeechd=0
GYP_DEFINES+=	want_separate_host_toolset=0
GYP_DEFINES+=	use_system_bzip2=1
GYP_DEFINES+=	use_system_flac=1
GYP_DEFINES+=	use_system_ffmpeg=0
GYP_DEFINES+=	use_system_harfbuzz=0
GYP_DEFINES+=	use_system_icu=0
GYP_DEFINES+=	use_system_jsoncpp=1
GYP_DEFINES+=	use_system_libevent=1
GYP_DEFINES+=	use_system_libexif=1
GYP_DEFINES+=	use_system_libjpeg=1
GYP_DEFINES+=	use_system_libpng=1
GYP_DEFINES+=	use_system_libusb=1
GYP_DEFINES+=	use_system_libwebp=1
GYP_DEFINES+=	use_system_libxml=1
GYP_DEFINES+=	use_system_libxslt=1
GYP_DEFINES+=	use_system_nspr=1
GYP_DEFINES+=	use_system_protobuf=0
GYP_DEFINES+=	use_system_re2=1
GYP_DEFINES+=	use_system_snappy=1
GYP_DEFINES+=	use_system_speex=1
GYP_DEFINES+=	use_system_xdg_utils=1
GYP_DEFINES+=	use_system_yasm=1
GYP_DEFINES+=	v8_use_external_startup_data=0
GYP_DEFINES+=	flapper_version_h_file='${WRKSRC}/flapper_version.h'
GYP_DEFINES+=	usb_ids_path=${PREFIX}/share/usbids/usb.ids

# API key and OAuth credential for Google.
# This is pkgsrc use only.
GYP_DEFINES+=	google_api_key=AIzaSyAT_3ogzNMKbBMFk3xQ6T35fg52Y9GrFBg
GYP_DEFINES+=	google_default_client_id=74061691103-faqqnan75j2s8ej3p7lh2k98dhkee816.apps.googleusercontent.com
GYP_DEFINES+=	google_default_client_secret=3R9TyUv14OXgzJnZi6Ismela

pre-patch:
	${RM} ${WRKSRC}/third_party/skia/tests/ImageFilterTest.cpp.*

pre-configure:
# Preserve third party source tree with remove_bundled_libraries.py script.
	cd ${WRKSRC} && \
	${PYTHONBIN} ./build/linux/unbundle/remove_bundled_libraries.py \
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
		'third_party/flac' \
		'third_party/flot' \
		'third_party/google_input_tools' \
		'third_party/google_input_tools/third_party/closure_library' \
		'third_party/google_input_tools/third_party/closure_library/third_party/closure' \
		'third_party/harfbuzz-ng' \
		'third_party/hunspell' \
		'third_party/iccjpeg' \
		'third_party/icu' \
		'third_party/jinja2' \
		'third_party/jstemplate' \
		'third_party/khronos' \
		'third_party/leveldatabase' \
		'third_party/libaddressinput' \
		'third_party/libphonenumber' \
		'third_party/libjingle' \
		'third_party/libsrtp' \
		'third_party/libusb' \
		'third_party/libvpx' \
		'third_party/libvpx/source/libvpx/third_party/x86inc' \
		'third_party/libwebm' \
		'third_party/libxml/chromium' \
		'third_party/libXNVCtrl' \
		'third_party/libyuv' \
		'third_party/lss' \
		'third_party/lzma_sdk' \
		'third_party/markupsafe' \
		'third_party/mesa' \
		'third_party/modp_b64' \
		'third_party/mt19937ar' \
		'third_party/openh264' \
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
		'third_party/speech-dispatcher' \
		'third_party/sqlite' \
		'third_party/tcmalloc' \
		'third_party/tlslite' \
		'third_party/usrsctp' \
		'third_party/web-animations-js' \
		'third_party/webdriver' \
		'third_party/webrtc' \
		'third_party/widevine' \
		'third_party/woff2' \
		'third_party/x86inc' \
		'third_party/yasm' \
		'third_party/zlib' \
		'url/third_party/mozilla' \
		'v8/src/third_party/valgrind' \
		'v8/src/third_party/fdlibm' \
		--do-remove
	cd ${WRKSRC} && \
	${PYTHONBIN} ./build/linux/unbundle/replace_gyp_files.py \
		${GYP_DEFINES:C/^/-D/}
# allow removal of third_party/adobe
	${TOUCH} ${WRKSRC}/flapper_version.h
# missing file: file is in -testdata only, but configure stage
# will fail if it's not there. do not break TESTS build while
# allowing regular build without pulling in -testdata.
	${TOUCH} ${WRKSRC}/chrome/test/data/webui/i18n_process_css_test.html

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} ./build/gyp_chromium chrome/chrome.gyp --depth . \
		${GYP_DEFINES:C/^/-D/}

# From OpenBSD Ports www/chromium
NINJA_BUILD_TARGETS+=	generate_version_info
NINJA_BUILD_TARGETS+=	cloud_policy_proto
NINJA_BUILD_TARGETS+=	net_interfaces
NINJA_BUILD_TARGETS+=	suggestions
NINJA_BUILD_TARGETS+=	cacheinvalidation
NINJA_BUILD_TARGETS+=	cacheinvalidation_proto_cpp
NINJA_BUILD_TARGETS+=	gfx_vector_icons
NINJA_BUILD_TARGETS+=	data_reduction_proxy_proto
NINJA_BUILD_TARGETS+=	cloud_policy_code_generate
NINJA_BUILD_TARGETS+=	common_constants
NINJA_BUILD_TARGETS+=	profile_reset_report_proto
NINJA_BUILD_TARGETS+=	autofill_server_proto
NINJA_BUILD_TARGETS+=	ipc_mojo
# Below is generated from ninja -t targets.
NINJA_BUILD_TARGETS+=	app_list_resources
NINJA_BUILD_TARGETS+=	app_shell_resources
NINJA_BUILD_TARGETS+=	ash_resources
NINJA_BUILD_TARGETS+=	blink_devtools_frontend_resources
NINJA_BUILD_TARGETS+=	blink_image_resources
NINJA_BUILD_TARGETS+=	blink_resources
NINJA_BUILD_TARGETS+=	chrome_extra_resources
NINJA_BUILD_TARGETS+=	chrome_resources
NINJA_BUILD_TARGETS+=	chrome_unscaled_resources
NINJA_BUILD_TARGETS+=	common_mojo_bindings
NINJA_BUILD_TARGETS+=	components_resources
NINJA_BUILD_TARGETS+=	content_common_mojo_bindings
NINJA_BUILD_TARGETS+=	content_common_mojo_bindings_mojom
NINJA_BUILD_TARGETS+=	content_resources
NINJA_BUILD_TARGETS+=	content_shell_mojo_bindings
NINJA_BUILD_TARGETS+=	content_shell_mojo_bindings_mojom
NINJA_BUILD_TARGETS+=	content_shell_resources
NINJA_BUILD_TARGETS+=	contextual_search_mojo_bindings
NINJA_BUILD_TARGETS+=	device_battery_mojo_bindings
NINJA_BUILD_TARGETS+=	device_usb_mojo_bindings
NINJA_BUILD_TARGETS+=	device_vibration_mojo_bindings
NINJA_BUILD_TARGETS+=	devtools_frontend_resources
NINJA_BUILD_TARGETS+=	devtools_resources
NINJA_BUILD_TARGETS+=	dom_distiller_mojo_bindings
NINJA_BUILD_TARGETS+=	extensions_resources
NINJA_BUILD_TARGETS+=	filesystem_bindings_mojom
NINJA_BUILD_TARGETS+=	keyboard_resources
NINJA_BUILD_TARGETS+=	leveldb_bindings_mojom
NINJA_BUILD_TARGETS+=	mojo_application_bindings_mojom
NINJA_BUILD_TARGETS+=	mojo_bindings
NINJA_BUILD_TARGETS+=	mojo_bindings_mojom
NINJA_BUILD_TARGETS+=	mojo_geometry_bindings_mojom
NINJA_BUILD_TARGETS+=	mojo_interface_bindings_mojom
NINJA_BUILD_TARGETS+=	net_resources
NINJA_BUILD_TARGETS+=	packed_extra_resources
NINJA_BUILD_TARGETS+=	packed_resources
NINJA_BUILD_TARGETS+=	platform_verification_mojo_bindings
NINJA_BUILD_TARGETS+=	profile_service_bindings_mojom
NINJA_BUILD_TARGETS+=	provision_fetcher_mojo_bindings
NINJA_BUILD_TARGETS+=	remoting_resources
NINJA_BUILD_TARGETS+=	resources
NINJA_BUILD_TARGETS+=	theme_resources
NINJA_BUILD_TARGETS+=	tracing_resources
NINJA_BUILD_TARGETS+=	tracing_service_bindings_mojom
NINJA_BUILD_TARGETS+=	ui_resources
NINJA_BUILD_TARGETS+=	views_resources
NINJA_BUILD_TARGETS+=	web_cache_mojo_bindings
NINJA_BUILD_TARGETS+=	web_ui_mojo_bindings
NINJA_BUILD_TARGETS+=	widevinecdmadapter_resources
NINJA_BUILD_TARGETS+=	browser_extensions
NINJA_BUILD_TARGETS+=	chrome_strings
# Real target
NINJA_BUILD_TARGETS+=	chrome

do-build:
.for target in ${NINJA_BUILD_TARGETS}
	${ECHO} TARGET is ${target} && \
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} \
	ninja -C out/${BUILDTYPE} ${target}
.endfor

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
#.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
# Use -lpciutils instead of -lpci under NetBSD.
BUILDLINK_TRANSFORM.NetBSD+=	opt:-lpci:-lpciutils
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../misc/usbids/buildlink3.mk"
#.include "../../textproc/icu/buildlink3.mk"

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
