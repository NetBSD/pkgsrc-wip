# $NetBSD: Makefile,v 1.14 2012/09/24 18:26:53 asau Exp $

DISTNAME=	chromium-85.0.4183.39
CATEGORIES=	www
MASTER_SITES=	http://commondatastorage.googleapis.com/chromium-browser-official/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.chromium.org/Home
COMMENT=	Open source web browser
LICENSE=	modified-bsd AND gnu-lgpl-v3 AND mpl-2.0

USE_TOOLS+=		bash bison flex:pkgsrc gmake pax perl pkg-config
TOOLS_PLATFORM.flex=	# override the platform definition to use pkgsrc's flex.
USE_LANGUAGES=		c c++

CHECK_PORTABILITY_SKIP+=	third_party/sqlite/src/configure
CHECK_PORTABILITY_SKIP+=	third_party/protobuf/post_process_dist.sh
CHECK_PORTABILITY_SKIP+=	third_party/ffmpeg/configure
CHECK_PORTABILITY_SKIP+=	third_party/xdg-utils/scripts/xdg-terminal
CHECK_PORTABILITY_SKIP+=	third_party/xdg-utils/scripts/xdg-terminal.in
CHECK_PORTABILITY_SKIP+=	third_party/llvm/flang/tools/f18/flang.sh.in
CHECK_PORTABILITY_SKIP+=	third_party/llvm/polly/lib/External/isl/configure
CHECK_PORTABILITY_SKIP+=	v8/tools/run-llprof.sh

BUILD_DEPENDS+=	gperf>=3.0.1:../../devel/gperf
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
BUILD_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build
BUILD_DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
BUILD_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
BUILD_DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply
BUILD_DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
BUILD_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs
BUILD_DEPENDS+=	openjdk11-[0-9]*:../../lang/openjdk11
#BUILD_DEPENDS+=	clang-[0-9]*:../../lang/clang # clang-format

PYTHON_VERSIONS_ACCEPTED=	27 # python3 not supported.

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

#ONLY_FOR_PLATFORM+=	*-*-arm # not yet
#ONLY_FOR_PLATFORM+=	*-*-aarch64 # not yet
#ONLY_FOR_PLATFORM+=	*-*-i386 # not yet
ONLY_FOR_PLATFORM+=	*-*-x86_64

# Workaround for brotli and other commands.
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

# Do not use alloca(3) in libc.
BUILDLINK_TRANSFORM+=		opt:-std=c11:-std=gnu11
BUILDLINK_TRANSFORM+=		opt:-std=c99:-std=gnu99
BUILDLINK_TRANSFORM+=		opt:-std=c++14:-std=gnu++14
BUILDLINK_TRANSFORM+=		opt:-std=c++17:-std=gnu++17

REPLACE_BASH=		chrome/tools/build/linux/chrome-wrapper

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Fixing pkg path
SUBST_FILES.path+=	chrome/common/chrome_paths.cc
SUBST_FILES.path+=	third_party/pdfium/core/fxge/fx_ge_linux.cpp
SUBST_FILES.path+=	third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp
SUBST_FILES.path+=	third_party/blink/renderer/bindings/scripts/bind_gen/style_format.py
SUBST_VARS.path+=	PREFIX X11BASE

CFLAGS+=		-fno-stack-protector
CFLAGS+=		-isystem${PREFIX}/lib/clang/10.0.0/include # third_party/zlib with clang

.include "options.mk"

MAKE_ENV+=	BUILDTYPE=${BUILDTYPE}
MAKE_ENV+=	GPERF=${PREFIX}/bin/gperf

# Proprietary codecs are enabled.
GN_ARGS+=	proprietary_codecs=true \
		ffmpeg_branding="Chrome"

GN_ARGS+=	clang_use_chrome_plugins=false \
		enable_hangout_services_extension=true \
		use_kerberos=false \
		use_aura=true \
		use_cups=true \
		enable_nacl=false \
		enable_remoting=false \
		fieldtrial_testing_like_official_build=true \
		toolkit_views=true \
		treat_warnings_as_errors=false \
		use_sysroot=false \
		use_system_libjpeg=false \
		use_system_harfbuzz=true \
		use_system_freetype=true \
		enable_one_click_signin=true \
		use_allocator="none" \
		use_allocator_shim=false \
		is_clang=true \
		use_lld=false \
		use_custom_libcxx=true \
		use_gold=false \
		icu_use_data_file=false
GN_ARGS+=	extra_cxxflags="-I${BUILDLINK_DIR}/include \
			-I${BUILDLINK_DIR}/include/glib \
			-I${BUILDLINK_DIR}/include/nss" \
		extra_ldflags="-L${PREFIX}/lib \
			-L${X11BASE}/lib \
			${COMPILER_RPATH_FLAG}${PREFIX}/lib \
			${COMPILER_RPATH_FLAG}${PREFIX}/lib/nspr \
			${COMPILER_RPATH_FLAG}${PREFIX}/lib/nss \
			${COMPILER_RPATH_FLAG}${PREFIX}/lib/ffmpeg4 \
			${COMPILER_RPATH_FLAG}${X11BASE}/lib"

GN_BOOTSTRAP_FLAGS+=	--no-clean --no-rebuild --skip-generate-buildfiles

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
#	${MKDIR} ${WRKSRC}/third_party/llvm-build/Release+Asserts/bin
#	${LN} -sf ${PREFIX}/bin/clang++ \
#		${WRKSRC}/third_party/llvm-build/Release+Asserts/bin/clang++
#	${LN} -sf ${PREFIX}/bin/clang \
#		${WRKSRC}/third_party/llvm-build/Release+Asserts/bin/clang
#	${LN} -sf ${PREFIX}/bin/llvm-ar \
#		${WRKSRC}/third_party/llvm-build/Release+Asserts/bin/llvm-ar
	${LN} -sf ${PREFIX}/java/openjdk11/bin/java \
		${BUILDLINK_DIR}/bin/java
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
		ffmpeg flac fontconfig freetype harfbuzz-ng libdrm libpng \
		libwebp libxml libxslt opus snappy \
			|| ${FALSE}

do-configure:
	# Create symlink to NetBSD nodejs command.
	${MKDIR} ${WRKSRC}/third_party/node/${LOWER_OPSYS}/node/bin
	${LN} -sf ${PREFIX}/bin/node \
		${WRKSRC}/third_party/node/${LOWER_OPSYS}/node/bin/node

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
		${PREFIX}/bin/ninja -j ${MAKE_JOBS:U1} -C out/${BUILDTYPE} \
			mksnapshot
	${TOOLS_PLATFORM.paxctl} +m ${WRKSRC}/out/${BUILDTYPE}/mksnapshot

	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/ninja -j ${MAKE_JOBS:U1} -C out/${BUILDTYPE} \
			v8_context_snapshot_generator
	${TOOLS_PLATFORM.paxctl} +m ${WRKSRC}/out/${BUILDTYPE}/v8_context_snapshot_generator

	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/ninja -j ${MAKE_JOBS:U1} -C out/${BUILDTYPE} \
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
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
# Not yet
#.include "../../devel/libevent/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
# Use -lpciutils instead of -lpci for pkgsrc.
BUILDLINK_TRANSFORM+=	l:pci:pciutils
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../misc/usbids/buildlink3.mk"
#.include "../../textproc/icu/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../devel/libatomic/buildlink3.mk"
# Some C++ files in ui/base/x are not buildable with GCC 8.4.0 on NetBSD/amd64.
PKG_CC=		${PREFIX}/bin/clang
PKG_CXX=	${PREFIX}/bin/clang++
BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
