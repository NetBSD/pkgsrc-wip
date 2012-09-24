# $NetBSD: Makefile,v 1.14 2012/09/24 18:26:53 asau Exp $

DISTNAME=	chromium-11.0.696.72
CATEGORIES=	www
MASTER_SITES=	http://build.chromium.org/buildbot/official/obsolete/
EXTRACT_SUFX=	.tar.bz2

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
CONFIGURE_ENV+=	GYP_DEFINES=${GYP_DEFINES:Q}

# Replace config.{guess,sub}
OVERRIDE_DIRDEPTH=	5

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
GYP_DEFINES+=	python_ver=${PYVERSSUFFIX}
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
MAKE_ENV+=	CC.host=${CC:Q}
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

BUILDDIR=	${WRKSRC}/out/${BUILDTYPE}

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

# Remove pre-configure stage when implement python in tools.
pre-configure:
	${LN} -sf ${PYTHONBIN} ${TOOLS_DIR}/bin/python
	${RM} -f ${BUILDLINK_DIR}/${PYINC}/ast.h
	${RM} -rf ${BUILDLINK_DIR}/include/GL
	cd ${WRKSRC}/third_party/icu && \
	${CP} -Rf public/common/unicode source/common

post-configure:
	cd ${WRKSRC}/third_party/icu && \
	${MV} -f source/common/unicode/platform.h public/common/unicode
	cd ${WRKSRC}/third_party/tcmalloc && \
	${MV} -f vendor/src/config.h chromium/src/config_linux.h
	cd ${WRKSRC}/third_party/ffmpeg/patched-ffmpeg-mt && \
	${SH} ./configure ${FFMPEG_ARGS} && cd .. && \
	${MV} -f patched-ffmpeg-mt/config.h \
		config/${FFMPEG_CODECS}/linux/${MACHINE_ARCH:S/i386/ia32/:S/x86_64/x64/}
	cd ${WRKSRC}/third_party/yasm/source && \
	${MKDIR} config/${LOWER_OPSYS} && \
	${MV} -f patched-yasm/Makefile \
		patched-yasm/config.h \
		patched-yasm/libyasm-stdint.h config/${LOWER_OPSYS}
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} python build/gyp_chromium --depth=${WRKSRC}

do-install:
.for f in chrome ffmpegsumo_nolink libffmpegsumo.so mksnapshot protoc
	${INSTALL_PROGRAM} ${BUILDDIR}/${f} ${DATADIR}
.endfor
.for f in chrome-wrapper xdg-mime xdg-settings
	${INSTALL_SCRIPT} ${BUILDDIR}/${f} ${DATADIR}
.endfor
.for f in chrome.pak product_logo_48.png resources.pak
	${INSTALL_DATA} ${BUILDDIR}/${f} ${DATADIR}
.endfor
.for d in locales resources
	cd ${BUILDDIR}/${d} && pax -rwpm . ${DATADIR}/${d}
.endfor
	${INSTALL_MAN} ${BUILDDIR}/chrome.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${LN} -sf ${DATADIR}/chrome ${DESTDIR}${PREFIX}/bin

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
