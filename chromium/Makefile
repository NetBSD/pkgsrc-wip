# $NetBSD: Makefile,v 1.14 2012/09/24 18:26:53 asau Exp $

DISTNAME=	chromium-56.0.2924.87
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
BUILD_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
BUILD_DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

#ONLY_FOR_PLATFORM+=	*-*-arm # not tested yet
ONLY_FOR_PLATFORM+=	*-*-x86_64

# Workaround
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

REPLACE_BASH=		chrome/tools/build/linux/chrome-wrapper
SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Fixing pkg path
SUBST_FILES.path+=	chrome/common/chrome_paths.cc
SUBST_SED.path+=	-e 's:/usr/local/:${PREFIX}/:'

CFLAGS+=		-fno-stack-protector

.include "options.mk"

MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
MAKE_ENV+=	GPERF=${PREFIX}/bin/gperf

KEEPLIBS+= \
		base/third_party/dmg_fp \
		base/third_party/dynamic_annotations \
		base/third_party/icu \
		base/third_party/nspr \
		base/third_party/superfasthash \
		base/third_party/symbolize \
		base/third_party/valgrind \
		base/third_party/xdg_mime \
		base/third_party/xdg_user_dirs \
		breakpad/src/third_party/curl \
		chrome/third_party/mozilla_security_manager \
		courgette/third_party \
		net/third_party/mozilla_security_manager \
		net/third_party/nss \
		third_party/WebKit \
		third_party/analytics \
		third_party/angle \
		third_party/angle/src/common/third_party/numerics \
		third_party/angle/src/third_party/compiler \
		third_party/angle/src/third_party/libXNVCtrl \
		third_party/angle/src/third_party/murmurhash \
		third_party/angle/src/third_party/trace_event \
		third_party/boringssl \
		third_party/brotli \
		third_party/cacheinvalidation \
		third_party/catapult \
		third_party/catapult/third_party/polymer \
		third_party/catapult/third_party/py_vulcanize \
		third_party/catapult/third_party/py_vulcanize/third_party/rcssmin \
		third_party/catapult/third_party/py_vulcanize/third_party/rjsmin \
		third_party/catapult/tracing/third_party/d3 \
		third_party/catapult/tracing/third_party/gl-matrix \
		third_party/catapult/tracing/third_party/jszip \
		third_party/catapult/tracing/third_party/mannwhitneyu \
		third_party/ced \
		third_party/cld_2 \
		third_party/cld_3 \
		third_party/cros_system_api \
		third_party/devscripts \
		third_party/dom_distiller_js \
		third_party/fips181 \
		third_party/flatbuffers \
		third_party/flot \
		third_party/google_input_tools \
		third_party/google_input_tools/third_party/closure_library \
		third_party/google_input_tools/third_party/closure_library/third_party/closure \
		third_party/hunspell \
		third_party/iccjpeg \
		third_party/icu \
		third_party/inspector_protocol \
		third_party/jstemplate \
		third_party/khronos \
		third_party/leveldatabase \
		third_party/libXNVCtrl \
		third_party/libaddressinput \
		third_party/libjingle \
		third_party/libphonenumber \
		third_party/libsecret \
		third_party/libsrtp \
		third_party/libudev \
		third_party/libusb \
		third_party/libwebm \
		third_party/libxml/chromium \
		third_party/libyuv \
		third_party/lss \
		third_party/lzma_sdk \
		third_party/mesa \
		third_party/modp_b64 \
		third_party/mt19937ar \
		third_party/openh264 \
		third_party/openmax_dl \
		third_party/opus \
		third_party/ots \
		third_party/pdfium \
		third_party/pdfium/third_party/agg23 \
		third_party/pdfium/third_party/base \
		third_party/pdfium/third_party/bigint \
		third_party/pdfium/third_party/freetype \
		third_party/pdfium/third_party/lcms2-2.6 \
		third_party/pdfium/third_party/libjpeg \
		third_party/pdfium/third_party/libopenjpeg20 \
		third_party/pdfium/third_party/libpng16 \
		third_party/pdfium/third_party/libtiff \
		third_party/pdfium/third_party/zlib_v128 \
		third_party/polymer \
		third_party/protobuf \
		third_party/protobuf/third_party/six \
		third_party/qcms \
		third_party/sfntly \
		third_party/skia \
		third_party/smhasher \
		third_party/sqlite \
		third_party/tcmalloc \
		third_party/usrsctp \
		third_party/web-animations-js \
		third_party/webdriver \
		third_party/webrtc \
		third_party/widevine \
		third_party/woff2 \
		third_party/x86inc \
		third_party/zlib/google \
		url/third_party/mozilla \
		v8/src/third_party/valgrind \
		v8/third_party/inspector_protocol \
		base/third_party/libevent \
		third_party/adobe \
		third_party/speech-dispatcher \
		third_party/usb_ids \
		third_party/xdg-utils \
		third_party/yasm/run_yasm.py \
		third_party/jinja2 \
		third_party/ply \
		third_party/ffmpeg \
		third_party/markupsafe \
		third_party/harfbuzz-ng \
		third_party/zlib

# Proprietary codecs are enabled.
GN_ARGS+=	proprietary_codecs=true \
		ffmpeg_branding="Chrome"

GN_ARGS+=	use_gconf=false \
		use_kerberos=false \
		use_cups=false \
		use_aura=true \
		enable_nacl=false \
		enable_hevc_demuxing=true \
		enable_media_router=true \
		enable_remoting=false \
		toolkit_views=true \
		treat_warnings_as_errors=false \
		use_sysroot=false \
		use_system_libjpeg=true \
		use_system_sqlite=false \
		use_alsa=false \
		enable_webrtc=false \
		enable_one_click_signin=true \
		use_allocator="none" \
		use_experimental_allocator_shim=false \
		is_clang=false \
		enable_webrtc=false \
		use_gnome_keyring=true
GN_ARGS+=	extra_cxxflags="-I${BUILDLINK_DIR}/include \
			-I${BUILDLINK_DIR}/include/glib \
			-I${BUILDLINK_DIR}/include/nss/nss " \
		extra_ldflags="-L${PREFIX}/lib \
			-L${X11BASE}/lib \
			${COMPILER_RPATH_FLAG}${PREFIX}/lib \
			${COMPILER_RPATH_FLAG}${X11BASE}/lib"
# To avoid error from sem_destroy(3) in mksnapshot
GN_ARGS+=	v8_use_snapshot=false

GN_BOOTSTRAP_FLAGS+=	--no-clean --no-rebuild

# API key and OAuth credential for Google.
# This is pkgsrc use only.
GN_ARGS+=	google_api_key="AIzaSyAT_3ogzNMKbBMFk3xQ6T35fg52Y9GrFBg" \
		google_default_client_id="74061691103-faqqnan75j2s8ej3p7lh2k98dhkee816.apps.googleusercontent.com" \
		google_default_client_secret="3R9TyUv14OXgzJnZi6Ismela"

NOT_PAX_MPROTECT_SAFE+=	bin/chrome
NOT_PAX_ASLR_SAFE+=	bin/chrome

post-extract:
	cp -r ${WRKSRC}/third_party/ffmpeg/chromium/config/Chrome/linux \
		${WRKSRC}/third_party/ffmpeg/chromium/config/Chrome/${LOWER_OPSYS}

pre-configure:
	cd ${WRKSRC} && \
	${PYTHONBIN} ./build/linux/unbundle/remove_bundled_libraries.py \
		${KEEPLIBS} --do-remove \
			|| ${FALSE}

	cp -r ${WRKSRC}/third_party/ffmpeg/chromium/config/Chrome/linux \
		${WRKSRC}/third_party/ffmpeg/chromium/config/Chrome/${LOWER_OPSYS}
# a wrapper for rpath $ORIGIN removal
#	echo "#! /bin/sh" > ${WRKSRC}/python
#	echo "LD_LIBRARY_PATH=./ ${PYTHONBIN} \"\$$@\"" >> ${WRKSRC}/python
#	chmod 755 ${WRKSRC}/python

# Sadly rpath $ORIGIN/. is needed.
#	rm -rf ${WRAPPER_DIR}

	cd ${WRKSRC} && \
	${PYTHONBIN} ./build/linux/unbundle/replace_gn_files.py \
		--system-libraries \
		flac libjpeg libpng libvpx libwebp libxml libxslt \
		re2 snappy yasm \
			|| ${FALSE}

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PYTHONBIN} ./tools/gn/bootstrap/bootstrap.py \
			${GN_BOOTSTRAP_FLAGS} \
			--gn-gen-args '${GN_ARGS}'
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		./out/${BUILDTYPE}/gn \
			gen --args='${GN_ARGS}' \
			--script-executable="${PYTHONBIN}" \
			${GN_VERBOSE} \
			out/${BUILDTYPE}
	
do-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} \
		ninja -j ${MAKE_JOBS} -C out/${BUILDTYPE} \
			chrome

CHROMIUM_DIR=		chrome
INSTALLATION_DIRS+=	${CHROMIUM_DIR}
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

ICON_SIZES=		22 24 48 64 128 256
.for i in ${ICON_SIZES}
ICONS_DIR${i}+=		share/icons/hicolor/${i}x${i}/apps
INSTALLATION_DIRS+=	${ICONS_DIR${i}}
.endfor

CHROMIUM_PROGS+=	chrome
CHROMIUM_SCRIPTS+=	chrome-wrapper

CHROMIUM_FILES+=	chrome.1
CHROMIUM_FILES+=	chrome_100_percent.pak
CHROMIUM_FILES+=	chrome_200_percent.pak
CHROMIUM_FILES+=	icudtl.dat
CHROMIUM_FILES+=	keyboard_resources.pak
CHROMIUM_FILES+=	resources.pak

do-install:
.for i in ${CHROMIUM_PROGS}
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BUILDTYPE}/${i} \
		${DESTDIR}${PREFIX}/${CHROMIUM_DIR}
.endfor
.for i in ${CHROMIUM_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/out/${BUILDTYPE}/${i} \
		${DESTDIR}${PREFIX}/${CHROMIUM_DIR}
.endfor
.for i in ${CHROMIUM_LIBS}
	${INSTALL_LIB} ${WRKSRC}/out/${BUILDTYPE}/${i} \
		${DESTDIR}${PREFIX}/${CHROMIUM_DIR}
.endfor
.for i in ${CHROMIUM_FILES}
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/${i} \
		${DESTDIR}${PREFIX}/${CHROMIUM_DIR}
.endfor
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf ../${CHROMIUM_DIR}/chrome .
	${INSTALL_DATA} ${WRKSRC}/out/${BUILDTYPE}/chrome.1 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1
.for i in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/chrome/app/theme/chromium/product_logo_${i}.png \
		${DESTDIR}${PREFIX}/${ICONS_DIR${i}}/chrome.png
.endfor
.for i in locales resources
	cd ${WRKSRC}/out/${BUILDTYPE} && \
		${FIND} ${i} -type f -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/${CHROMIUM_DIR}
.endfor

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
# This introduces OpenSSL dependency and it conflicts with bundled BoringSSL.
#.include "../../print/cups-base/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
# Not yet
#.include "../../fonts/harfbuzz/buildlink3.mk"
#.include "../../devel/libevent/buildlink3.mk"
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
.include "../../x11/gtk3/buildlink3.mk"
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
# Not yet
#.include "../../textproc/icu/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
# Conflict between OpenSSL and BoringSSL.
#.include "../../multimedia/ffmpeg3/buildlink3.mk"

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
